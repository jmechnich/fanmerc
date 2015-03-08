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

#ifndef TEAM_HH
#define TEAM_HH

#include <string>

#include "Item.hh"
#include "Character.hh"

#define MAX_MEMBERS 24

namespace fanmerc
{
class Team
{
public:
  Team();
    
  void initDefaultTeam();
  void read( std::istream& is);
  
  std::string name();
  
  void addCharacter( Character* character);
  
  int statAsInt( const std::string& name, bool* exists=0) const;
  std::string statAsString( const std::string& name, bool* exists=0) const;

  template<class VALUETYPE>
  void setStat( const std::string& name, const VALUETYPE& value);

private:

  std::map<std::string,std::string> _stats;
  std::map<std::string,Item*> _stash;
  std::map<std::string,Character*> _members;
};

}

#include "Team.icc"

#endif
