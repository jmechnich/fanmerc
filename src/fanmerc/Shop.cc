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

#include "Shop.hh"

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Shop::Shop( const std::string& name)
{
  _stats["name"]=name;
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Shop::read( std::istream& is)
{
  std::string keyBuf, valBuf;
  is >> keyBuf;
  is >> std::ws;
  std::getline( is, valBuf);
  while( is.good() && keyBuf != "END")
  {
    _stats[keyBuf] = valBuf;
    is >> keyBuf;
    is >> std::ws;
    std::getline( is, valBuf);
  }
}
