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

#ifndef GLOBALSTATE_HH
#define GLOBALSTATE_HH

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <sstream>

namespace fanmerc
{
  class Town;
  class Team;
  class Quest;
  
class GlobalState
{
public:
  GlobalState();
  ~GlobalState();
  
  void read( std::istream& is);
  void write( std::ostream& os);

  void clear();
    
  int statAsInt( const std::string& name, bool* exists=0) const;
  std::string statAsString( const std::string& name, bool* exists=0) const;

  template<class VALUETYPE>
  void setStat( const std::string& name, const VALUETYPE& value);

  Town* town();
  Team* team();
  
private:
  std::map<std::string,std::string> _stats;
  std::vector<Quest*> _availableQuests;
  
  Town* _town;
  Team* _team;
};

}

#include "GlobalState.icc"

#endif
