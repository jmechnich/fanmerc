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

#include <QWidget>
#include <QDialog>
#include <QString>

#include <Shop.hh>

namespace fanmerc
{

class TownWindow;
  
class HouseWindow : public QWidget
{
public:
  HouseWindow( const QString& name, TownWindow* parent);

private:
  QDialog* _widget;
  QString _name;
};
}

#endif
