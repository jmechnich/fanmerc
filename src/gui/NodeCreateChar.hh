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

#ifndef NODECREATECHAR_HH
#define NODECREATECHAR_HH

#include "NodeWindow.hh"

#include "Buttons.hh"
#include <QWidget>

namespace fanmerc
{

  class MainWidget;
  
  class NodeCreateChar :public NodeWindow
  {
    Q_OBJECT

  public:
    NodeCreateChar( MainWidget* parent);

  protected slots:
    void createNew();
    
  protected:
    void leftAction();
    void rightAction();

    QWidget* _left;
    Button* _createButton[3];
    QWidget* _right;

  };
}

#endif
