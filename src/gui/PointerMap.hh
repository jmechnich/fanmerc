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

#ifndef POINTERMAP_HH
#define POINTERMAP_HH

#include <map>
#include <string>

#include <qstring.h>
#include <qpixmap.h>

namespace fanmerc
{
template<class POINTERTYPE>
class PointerMap : public std::map<std::string,POINTERTYPE>
{
public:
  PointerMap( bool autoDelete=true);
  ~PointerMap();
private:
  bool _autoDelete;
};
}

#include "PointerMap.icc"

#endif
