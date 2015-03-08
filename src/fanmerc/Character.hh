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

#ifndef CHARACTER_HH
#define CHARACTER_HH

#include <string>
#include <map>
#include <sstream>
#include <istream>

#include "FanmercDefs.hh"
#include "Item.hh"

namespace fanmerc
{

class Quest;
  
class Character
{
public:
  Character();
  ~Character();

  void read( std::istream& is);
  void initClassStats( const std::string& className);
  void initRaceStats( const std::string& race);
  
  int modStatAsInt( const std::string& name) const;

  int statAsInt( const std::string& name, bool* exists=0) const;
  std::string statAsString( const std::string& name, bool* exists=0) const;

  template<class VALUETYPE>
  void setStat( const std::string& name, const VALUETYPE& value);

  int modAttr( const std::string& name) const;
  Item* equip( Item* item, const std::string& location);

  std::string name() const;
  int HP() const;
  int MP() const;
  int attackClose() const;
  int attackMissile() const;
  int defence() const;
  int armor() const;
  int damRed() const;
  int numDamageClose() const;
  int typeDamageClose() const;
  int numDamageMissile() const;
  int typeDamageMissile() const;
  
private:
  std::map<std::string,std::string> _stats;
  std::map<std::string,Item*> _locations;

  Item* _activeItems[4];
  Item* _passiveItems[3];

  Quest* _currentQuest;
};
}

#include "Character.icc"

#endif
