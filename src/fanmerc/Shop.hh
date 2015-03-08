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

#ifndef SHOP_HH
#define SHOP_HH

#include <iostream>
#include <string>
#include <map>
#include <sstream>

namespace fanmerc
{
class Shop
{
public:
  typedef std::map<std::string,std::string>::const_iterator const_iterator;
  
  virtual ~Shop()
        {}

  virtual void read( std::istream& is);
  
  virtual void exec( const std::string& action);
  
  std::string possibleActions() const;

  int statAsInt( const std::string& name, bool* exists=0) const;
  std::string statAsString( const std::string& name, bool* exists=0) const;

  template<class VALUETYPE>
  void setStat( const std::string& name, const VALUETYPE& value);

  std::string name();

  const_iterator statsBegin() const;
  const_iterator statsEnd() const;
  
  const_iterator descBegin() const;
  const_iterator descEnd() const;

protected:
  Shop( const std::string& name);
  
  std::map<std::string,std::string> _descriptions;

private:
  std::map<std::string,std::string> _stats;

};

class Barracks : public Shop
{
public:
  Barracks()
          :Shop( "Barracks")
        {
          _descriptions["Barracks_show"] = "Show characters";
          _descriptions["Barracks_create"] = "Create character";
          _descriptions["Barracks_hire"] = "Hire character";
        }
};
  
class Blacksmith : public Shop
{
public:
  Blacksmith()
          :Shop( "Blacksmith")
        {
          _descriptions["Blacksmith_createItem"] = "Create item";
        }
};
  
class Defence : public Shop
{
public:
  Defence()
          :Shop( "Defence")
        {
          _descriptions["Defence_start"] = "Start Quest";
        }
};
  
class Engineer : public Shop
{
public:
  Engineer()
          :Shop( "Engineer")
        {
          _descriptions["Engineer_tree"] = "Show tech tree";
        }
};
  
class Hall : public Shop
{
public:
  Hall()
          :Shop( "Hall")
        {}
};
  
class Library : public Shop
{
public:
  Library()
          :Shop( "Library")
        {
          _descriptions["Library_stats"] = "Show stats";
        }
};
  
class MagicTower : public Shop
{
public:
  MagicTower()
          :Shop( "MagicTower")
        {
          _descriptions["MagicTower_createItem"] = "Create item";
        }
};
  
class Office : public Shop
{
public:
  Office()
          :Shop( "Office")
        {
          _descriptions["Office_stats"] = "Show stats";
          _descriptions["Office_quests"] = "Show quests";
        }
};
  
class Storage : public Shop
{
public:
  Storage()
          :Shop( "Storage")
        {
          _descriptions["Storage_showItems"] = "Show items";
        }
};
  
class Treasury : public Shop
{
public:
  Treasury()
          :Shop( "Treasury")
        {
          _descriptions["Treasury_balance"] = "Show balance";
        }
};
  
class Well : public Shop
{
public:
  Well()
          :Shop( "Well")
        {}
};
  
}

#include "Shop.icc"

#endif
    
