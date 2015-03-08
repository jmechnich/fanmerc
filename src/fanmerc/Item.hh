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

#ifndef ITEM_HH
#define ITEM_HH

#include <string>
#include <map>
#include <iostream>

#include "FanmercDefs.hh"

namespace fanmerc
{

class Character;
  
class Item
{
public:
  Item();
  virtual ~Item();
  
  std::string type() const;

  void setOwner( Character* owner);
  const Character* owner() const;

  template<class VALUETYPE>
  void setStat( const std::string& name, const VALUETYPE& value);

  template<class VALUETYPE>
  void setRequirement( const std::string& name, const VALUETYPE& value);

  int statAsInt( const std::string& name, bool* exists=0) const;
  int requirementAsInt( const std::string& name, bool* exists=0) const;

  std::string statAsString( const std::string& name, bool* exists=0) const;
  std::string requirementAsString( const std::string& name,
                                   bool* exists=0) const;

  virtual void read( std::istream& is);

  std::string checkRequirements( const Character* character,
                                 bool* requirementsMet) const;
       
protected:
  std::string _type;

  std::string _description;
  
  std::map<std::string,std::string> _requirements;
  std::map<std::string,std::string> _stats;
  
  const Character* _owner;
};
}

#include "Item.icc"

#endif
