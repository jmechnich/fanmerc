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

#ifndef HOUSEWINDOW_HH
#define HOUSEWINDOW_HH

#include <qwidget.h>
#include <qdialog.h>
#include <qstring.h>

#include <Shop.hh>

namespace fanmerc
{

class TownWindow;
  
class HouseWindow : public QWidget
{
public:
  HouseWindow( const QString& name, TownWindow* parent,
               WFlags f=0);

private:
  QDialog* _widget;
  QString _name;
};
}

#endif
