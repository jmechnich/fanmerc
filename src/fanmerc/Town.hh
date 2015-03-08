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

#ifndef TOWN_HH
#define TOWN_HH

#include "Shop.hh"
#include <string>

namespace fanmerc
{
class Town
{
public:
  Town();
  
  void read( std::istream& is);
  Shop* shop( const std::string& name)
        {
          std::map<std::string,Shop*>::iterator it = _shops.find( name);
          if( it != _shops.end())
          {
            return it->second;
          }
          else
          {
            return 0;
          }
        }
  
private:
  std::map<std::string,Shop*> _shops;
  
};
}

#endif
