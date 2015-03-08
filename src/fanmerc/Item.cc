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

#include "Item.hh"

#include "Character.hh"

#include <sstream>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Item::Item() 
        :_owner( 0)
{
  _stats["type"] ="";
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Item::~Item() 
{}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Item::read( std::istream& is)
{
  std::string keyBuf, valBuf;
  is >> keyBuf;
  is >> std::ws;
  std::getline( is, valBuf);

  while( is.good() && keyBuf != "END")
  {
    if( valBuf == "MAIN")
    {
      std::cout << "Parsing ITEM::MAIN" << std::endl;
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
    else if( valBuf == "STATS")
    {
      std::cout << "Parsing ITEM::STATS" << std::endl;
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
    else if( valBuf == "REQUIREMENTS")
    {
      std::cout << "Parsing ITEM::REQUIREMENTS" << std::endl;
      setRequirement( keyBuf, valBuf);
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
      if( valBuf != "REQUIREMENTS")
      {
        std::cerr << "Error parsing save file, invalid END REQUIREMENTS tag"
                  << std::endl;
        return;
      }
    }
    else
    {
      std::cerr << "Error parsing save file, unknown section ITEM::"
                << valBuf << std::endl;
        return;
    }
    is >> keyBuf;
    is >> std::ws;
    std::getline( is, valBuf);
  }
  
  if( valBuf != "ITEM")
  {
    std::cerr << "Error parsing save file, invalid END ITEM tag" << std::endl;
    return;
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
std::string
fanmerc::Item::checkRequirements( const Character* character,
                                  bool* requirementsMet) const
{
  *requirementsMet = true;
  
  bool exists;
  std::stringstream ret;
  std::string name, value;
  for( std::map<std::string,std::string>::const_iterator it =
           _requirements.begin(); it != _requirements.end(); ++it)
  {
    name = it->first.substr( 3, it->first.length());
    if( it->first.substr( 0, 3) == "Min")
    {
      value = character->statAsString( name, &exists);
      if( exists == true)
      {
        if( value < it->second)
        {
          *requirementsMet = false;
          ret << "Minimum requirement not met for " << name << ": "
              << value << " is smaller than " << it->second << "\n";
        }
      }
    }
    else if( it->first.substr( 0, 3) == "Max")
    {
      value = character->statAsString( name, &exists);
      if( exists == true)
      {
        if( value > it->second)
        {
          *requirementsMet = false;
          ret << "Maximum requirement not met for " << name << ": "
              << value << " is greater than " << it->second << "\n";
        }
      }
    }
    else
    {
    }
  }
  return ret.str();
}

