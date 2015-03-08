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

#include "Team.hh"

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Team::Team()
{
  initDefaultTeam();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Team::initDefaultTeam()
{

  _stats["name"] = "Green Berets";
  _stats["gold"] = 100;
  
  Character* character;

  character = new Character;
  character->setStat( "name", "Dr. Kongo");
  character->setStat( "gender", "MALE");
  character->initRaceStats( "HUMAN");
  character->initClassStats( "WARRIOR");

  character = new Character;
  character->setStat( "name", "Sgt Smoke");
  character->setStat( "gender", "MALE");
  character->initRaceStats( "DWARF");
  character->initClassStats( "THIEF");

  character = new Character;
  character->setStat( "name", "Dr. Kralle");
  character->setStat( "gender", "FEMALE");
  character->initRaceStats( "ELF");
  character->initClassStats( "MAGE");
 
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Team::read( std::istream& is)
{
  Character* character;
  std::string keyBuf, valBuf;
  is >> keyBuf;
  is >> std::ws;
  std::getline( is, valBuf);

  while( is.good() && keyBuf != "END")
  {
    if( keyBuf == "BEGIN")
    {
      if( valBuf == "MAIN")
      {
        std::cout << "Parsing TEAM::MAIN" << std::endl;
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
          std::cerr << "Error parsing save file in section 'TEAM::MAIN'"
                    << std::endl;
        }
      }
      else if( valBuf == "INVENTORY")
      {
        std::cout << "Parsing TEAM::INVENTORY" << std::endl;
      }
      else if( valBuf == "CHARACTER")
      {
        std::cout << "Parsing TEAM::CHARACTER" << std::endl;
        character = new Character;
        character->read( is);
        _members[character->name()] = character;
        character = 0;
      }
      else
      {
        std::cerr << "TEAM: Parse error (" << keyBuf << ", " << valBuf << ")"
                  << std::endl;
        return;
      }
    }
    is >> keyBuf;
    is >> std::ws;
    std::getline( is, valBuf);
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Team::addCharacter( Character* character)
{
  if( _members.size() > MAX_MEMBERS)
  {
    std::cerr << "Can't add " << character->name() << " to team, "
              << "maximum team size of " << MAX_MEMBERS << " reached\n";
  }
  else
  {
    if( _members.find( character->name()) != _members.end())
    {
      std::cerr << "There is already a member with name "
                << character->name() << " in the team\n";
    }
    else
    {
      _members[character->name()] = character;
    }
  }
}
