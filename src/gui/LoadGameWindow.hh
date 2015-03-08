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

#ifndef LOADGAMEWINDOW_HH
#define LOADGAMEWINDOW_HH

#include <QWidget>

#include <GlobalState.hh>

namespace fanmerc
{
  class MainWidget;
    
  class LoadGameWindow : public QWidget
  {
  public:
    LoadGameWindow( MainWidget* parent);
    void openFile( GlobalState* globalState);

  private:
    MainWidget* _parent;
  };
}

#endif
