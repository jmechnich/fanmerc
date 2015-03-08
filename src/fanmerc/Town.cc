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

#include "Town.hh"

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Town::Town()
{
  _shops["BARRACKS"] = new Barracks;
  _shops["BLACKSMITH"] = new Blacksmith;
  _shops["DEFENCE"] = new Defence;
  _shops["ENGINEER"] = new Engineer;
  _shops["HALL"] = new Hall;
  _shops["LIBRARY"] = new Library;
  _shops["MAGICTOWER"] = new MagicTower;
  _shops["OFFICE"] = new Office;
  _shops["STORAGE"] = new Storage;
  _shops["TREASURY"] = new Treasury;
  _shops["WELL"] = new Well;
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Town::read( std::istream& is)
{
  Shop* shop;
  std::string keyBuf, valBuf;
  is >> keyBuf;
  is >> std::ws;
  std::getline( is, valBuf);

  while( is.good() && keyBuf != "END")
  {
    if( keyBuf == "BEGIN")
    {
      if( valBuf == "BARRACKS")
      {
        shop = new Barracks;
      }
      else if( valBuf == "BLACKSMITH")
      {
        shop = new Blacksmith;
      }
      else if( valBuf == "DEFENCE")
      {
        shop = new Defence;
      }
      else if( valBuf == "ENGINEER")
      {
        shop = new Engineer;
      }
      else if( valBuf == "HALL")
      {
        shop = new Hall;
      }
      else if( valBuf == "LIBRARY")
      {
        shop = new Library;
      }
      else if( valBuf == "MAGICTOWER")
      {
        shop = new MagicTower;
      }
      else if( valBuf == "OFFICE")
      {
        shop = new Office;
      }
      else if( valBuf == "STORAGE")
      {
        shop = new Storage;
      }
      else if( valBuf == "TREASURY")
      {
        shop = new Treasury;
      }
      else if( valBuf == "WELL")
      {
        shop = new Well;
      }
      else
      {
        std::cerr << "Unknown section '" << valBuf << "'" << std::endl;
        return;
      }
      if( shop != 0)
      {
        std::cout << "Parsing TOWN::" << valBuf << std::endl;
        shop->read( is);
        std::map<std::string,Shop*>::iterator it = _shops.find( valBuf);
        if( it != _shops.end())
        {
          delete it->second;
        }
        _shops[valBuf] = shop;
        shop = 0;
      }
    }
    else
    {
      std::cerr << "TOWN: Parse error (" << keyBuf << ", " << valBuf << ")"
                << std::endl;
      return;
    }
    is >> keyBuf;
    is >> std::ws;
    std::getline( is, valBuf);
  }
}

