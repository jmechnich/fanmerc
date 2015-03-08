/**************************************************************************
**       Title: 
**    $RCSfile: $
**   $Revision: $$Name:  $
**       $Date: $
**   Copyright: GPL $Author: $
** Description:
**
**    
**
**-------------------------------------------------------------------------
**
**  $Log: $
**
**
**************************************************************************/

#include "Character.hh"
#include "GlobalState.hh"

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Character::Character()
        :_currentQuest( 0)
{
  _stats["name"] = "";
  for( int i=0; i<4; ++i)
  {
    _activeItems[i] = 0;
  }
  
  for( int i=0; i<3; ++i)
  {
    _passiveItems[i] = 0;
  }
  
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Character::~Character()
{
  for( std::map<std::string,Item*>::iterator it = _locations.begin();
       it != _locations.end(); ++it)
  {
    delete it->second;
  }
  for( int i=0; i<4; ++i)
  {
    if( _activeItems[i] != 0)
    {
      delete _activeItems[i];
    }
  }
  
  for( int i=0; i<3; ++i)
  {
    if( _passiveItems[i] == 0)
    {
      delete _passiveItems[i];
    }
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Character::read( std::istream& is)
{
  std::string keyBuf, valBuf;
  is >> keyBuf;
  is >> std::ws;
  std::getline( is, valBuf);

  while( is.good() && keyBuf != "END")
  {
    Item* item;
    if( keyBuf == "BEGIN")
    {
      /*------------------------------------------------------------------
       *  Read name, gender, race, class, level and xp
       *------------------------------------------------------------------*/
      if( valBuf == "MAIN")
      {
        std::cout << "Parsing CHARACTER::MAIN" << std::endl;
        is >> keyBuf;
        is >> std::ws;
        std::getline( is, valBuf);
        while( keyBuf != "END")
        {
          setStat( keyBuf, valBuf);
          is >> keyBuf;
          is >> std::ws;
          std::getline( is, valBuf);
        }
        if( valBuf != "MAIN")
        {
          std::cerr << "Error parsing save file, invalid END MAIN tag"
                    << std::endl;
          return;
        }
      }
      /*-------------------------------------------------------------------
       *  Read stats
       *-------------------------------------------------------------------*/
      else if( valBuf == "STATS")
      {
        std::cout << "Parsing CHARACTER::STATS" << std::endl;
        is >> keyBuf;
        is >> std::ws;
        std::getline( is, valBuf);
       while( keyBuf != "END")
        {
          setStat( keyBuf, valBuf);
          is >> keyBuf;
          is >> std::ws;
          std::getline( is, valBuf);
        }
        if( valBuf != "STATS")
        {
          std::cerr << "Error parsing save file, invalid END STATS tag"
                    << std::endl;
          return;
        }
      }
      /*-------------------------------------------------------------------
       *  Read locations
       *-------------------------------------------------------------------*/
      else if( valBuf == "LOCATIONS")
      {
        std::cout << "Parsing CHARACTER::LOCATIONS" << std::endl;
        std::string location;
        is >> keyBuf;
        is >> valBuf;
        while( keyBuf != "END")
        {
          if( keyBuf == "BEGIN")
          {
            location = valBuf;
            
            is >> keyBuf;
            is >> valBuf;
            
            if( keyBuf == "BEGIN" && valBuf == "ITEM")
            {
              std::cout << "Parsing " << location << "::ITEM" << std::endl;
              item = new Item;
              item->setOwner( this);
              item->read( is);
            }
            else
            {
              std::cerr << "Unknown section LOCATION::" << valBuf << std::endl;
              return;
            }
                          
            _locations[location] = item;
            is >> keyBuf;
            is >> valBuf;
            if( keyBuf != "END" && valBuf != location)
            {
              std::cerr << "Error parsing save file, invalid END " << location
                        << " tag" << std::endl;
              return;
            }
            is >> keyBuf;
            is >> valBuf;
          }
        }
        if( valBuf != "LOCATIONS")
        {
          std::cerr << "Error parsing save file, invalid END LOCATIONS tag"
                    << std::endl;
          return;
        }
      }
      /*------------------------------------------------------------------
       *  Read active items
       *-------------------------------------------------------------------*/
      else if( valBuf == "ACTIVE")
      {
        std::cout << "Parsing CHARACTER::ACTIVE" << std::endl;
        is >> keyBuf;
        is >> valBuf;
        int i = 0;
        while( keyBuf != "END")
        {
          if( i == 4)
          {
            std::cerr << "Error parsing save file in CHARACTER::ACTIVE: "
                      << "too many items" << std::endl;
            return;
          }
          if( valBuf == "ITEM")
          {
            _activeItems[i] = new Item;
            _activeItems[i]->setOwner( this);
            _activeItems[i]->read( is);
            ++i;
          }
          else
          {
            std::cerr << "Unknown section ACTIVE::" << valBuf << std::endl;
            return;
          }
             
          is >> keyBuf;
          is >> valBuf;
        }
        if( valBuf != "ACTIVE")
        {
          std::cerr << "Error parsing save file, invalid END ACTIVE tag"
                    << std::endl;
          return;
        }
      }
      /*-------------------------------------------------------------------
       *  Read passive items
       *-------------------------------------------------------------------*/
      else if( valBuf == "PASSIVE")
      {
        std::cout << "Parsing CHARACTER::PASSIVE" << std::endl;
        is >> keyBuf;
        is >> valBuf;
        int i = 0;
        while( keyBuf != "END")
        {
          if( i == 3)
          {
            std::cerr << "Unknown section PASSIVE::" << valBuf << std::endl;
            return;
          }
          if( valBuf == "ITEM")
          {
            _passiveItems[i] = new Item;
            _passiveItems[i]->setOwner( this);
            _passiveItems[i]->read( is);
            ++i;
          }
          else
          {
            std::cerr << "Unknown section PASSIVE::" << valBuf << std::endl;
            return;
          }
             
          is >> keyBuf;
          is >> valBuf;
        }
        if( valBuf != "PASSIVE")
        {
          std::cerr << "Error parsing save file, invalid END ACTIVE tag"
                    << std::endl;
          return;
        }
      }
      else
      {
        std::cerr << "Error parsing save file, unknown section 'CHARACTER::"
                  << valBuf << "'" << std::endl;
        return;
      }
    }
    is >> keyBuf;
    is >> std::ws;
    std::getline( is, valBuf);
  }
  
  if( valBuf != "CHARACTER")
  {
    std::cerr << "Error parsing save file, invalid END CHARACTER tag"
              << std::endl;
    return;
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Character::initClassStats( const std::string& className)
{
  if( className == "WARRIOR")
  {
  }
  else if( className == "THIEF")
  {
  }
  else if( className == "MAGE")
  {
  }
  else
  {
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Character::initRaceStats( const std::string& race)
{}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Item*
fanmerc::Character::equip( Item* item, const std::string& location)
{
  Item* ret;

  if( item->type() == location)
  {
    
    std::map<std::string,Item*>::iterator it = _locations.find( location);
    if( it != _locations.end() && it->second != 0)
    {
      ret = it->second;
    }
    else
    {
      ret = 0;
    }
    
    _locations[location] = item;
  }
  else
  {
    ret = 0;
  }
  
  return ret;
}
    
  
