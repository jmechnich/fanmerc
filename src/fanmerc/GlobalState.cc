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

#include "GlobalState.hh"

#include "Town.hh"
#include "Team.hh"

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::GlobalState::GlobalState()
        :_town( new Town), _team( new Team)
{}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::GlobalState::~GlobalState()
{
  if( _team != 0)
  {
    delete _team;
  }
  
  if( _town != 0)
  {
    delete _town;
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::GlobalState::read( std::istream& is)
{
  std::string keyBuf, valBuf;
  is >> keyBuf;
  is >> valBuf;
  if( keyBuf != "BEGIN" || valBuf != "GLOBALSTATE")
  {
    std::cerr << "Error parsing save file, invalid start of file"
              << std::endl;
    return;
  }
    
  is >> keyBuf;
  is >> valBuf;

  while( is.good() && keyBuf != "END")
  {
    if( keyBuf == "BEGIN")
    {
      if( valBuf == "MAIN")
      {
        std::cout << "Parsing GLOBALSTATE::MAIN" << std::endl;
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
      else if( valBuf == "TOWN")
      {
        std::cout << "Parsing GLOBALSTATE::TOWN" << std::endl;
        
        _town->read( is);
      }
      else if( valBuf == "TEAM")
      {
        std::cout << "Parsing GLOBALSTATE::TEAM" << std::endl;
        
        _team->read(is);
      }
      else
      {
        std::cerr << "Error parsing save file, unknown section GLOBALSTATE::"
                  << valBuf << std::endl;
        return;
      }
    }
    else
    {
      std::cerr << "Error parsing save file" << std::endl;
      return;
    }
    is >> keyBuf;
    is >> valBuf;
  }
  if( valBuf != "GLOBALSTATE")
  {
    std::cerr << "Error parsing save file, inavlid END GLOBALSTATE tag"
              << std::endl;
    return;
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::GlobalState::write( std::ostream& os)
{}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::GlobalState::clear()
{
  _stats.clear();
  _availableQuests.clear();
  
  if( _team != 0)
  {
    delete _team;
    _team = new Team;
  }
  if( _town != 0)
  {
    delete _town;
    _town = new Town;
  }
}
