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

#ifndef MAINMENUWINDOW_HH
#define MAINMENUWINDOW_HH

#include <qwidget.h>
#include <qwidgetstack.h>

namespace fanmerc
{
  
  class MainWidget;
  
  class MainMenuWindow : public QWidget
  {
  public:
    MainMenuWindow( MainWidget* parent);
    ~MainMenuWindow();
    
  private:
    QWidget* _widget;
  };
}

#endif
