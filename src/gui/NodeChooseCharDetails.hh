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

#ifndef NODECHOOSECAHRDETAILS_HH
#define NODECHOOSECAHRDETAILS_HH

#include "NodeWindow.hh"
#include <iostream>

namespace fanmerc
{
  class MainWidget;
  
  class NodeChooseCharDetails : public NodeWindow
  {
  public:
    NodeChooseCharDetails(  MainWidget* parent);
    
  protected:
    void leftAction();
    void rightAction();

    QWidget* _left;
    Button* _createButton[3];
    QWidget* _right;
  };
}

#endif
