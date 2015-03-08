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

#include <QWidget>

namespace fanmerc
{
  
  class MainWidget;
  
  class MainMenuWindow : public QWidget
  {
  public:
    MainMenuWindow( MainWidget* parent);
    
  private:
    QWidget* _widget;
  };
}

#endif
