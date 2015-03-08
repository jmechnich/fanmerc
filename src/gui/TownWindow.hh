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

#ifndef TOWNWINDOW_HH
#define TOWNWINDOW_HH

#include <qwidget.h>

#include <map>
#include <string>

#include <Town.hh>

namespace fanmerc
{

  class Button;
  class StatusBar;
  class MainWidget;
  
  class TownWindow : public QWidget
  {
    Q_OBJECT
  public:
    TownWindow( MainWidget* parent);
    ~TownWindow();
    
    Button* button( const std::string& name);
    Town* town();
    
  public slots:
    void showHouseWindow();
    
  private:
    std::map<std::string,Button*> _houseButtons;
    StatusBar* _statusBar;
    MainWidget* _parent;
  };
}

#endif
