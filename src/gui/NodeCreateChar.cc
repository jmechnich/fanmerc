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

#include "NodeCreateChar.hh"

#include "MainWidget.hh"
#include "NodeChooseCharDetails.hh"

#include <qpixmap.h>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::NodeCreateChar::NodeCreateChar( MainWidget* parent)
        :NodeWindow( parent, "lbl_createchars.png")
{
  parent->global()->clear();
  _left = new QWidget( this);
  QPixmap* pm = parent->getPixmap( "box_create-left.png");
  _left->setFixedSize( pm->width(), pm->height());
  
  _left->setPaletteBackgroundPixmap( *pm);
  _left->move( 25, 150);
  _left->show();

  _createButton[0] =
      new Button( parent->getPixmap("btn_createnew.png"),
                  parent->getPixmap("btn_createnew_highlight.png"),
                  parent->getMask("btn_createnew.png"),
                  _left);
  _createButton[0]->move(
      _left->width()/467*315 - _createButton[0]->width()/2,
      _left->height()/585*135 - _createButton[0]->height()/2);
  _createButton[0]->show();
  
  
  _createButton[1] =
      new Button( parent->getPixmap("btn_createnew.png"),
                  parent->getPixmap("btn_createnew_highlight.png"),
                  parent->getMask("btn_createnew.png"),
                  _left);
  _createButton[1]->move(
      _left->width()/467*315 - _createButton[1]->width()/2,
      _left->height()/585*305 - _createButton[1]->height()/2);
  _createButton[1]->show();
  
  
  _createButton[2] =
      new Button( parent->getPixmap("btn_createnew.png"),
                  parent->getPixmap("btn_createnew_highlight.png"),
                  parent->getMask("btn_createnew.png"),
                  _left);
  _createButton[2]->move(
      _left->width()/467*315 - _createButton[2]->width()/2,
      _left->height()/585*470 - _createButton[2]->height()/2);
  _createButton[2]->show();
  
  
  connect( _createButton[0], SIGNAL( clicked()),
           this, SLOT( createNew()));
  connect( _createButton[1], SIGNAL( clicked()),
           this, SLOT( createNew()));
  connect( _createButton[2], SIGNAL( clicked()),
           this, SLOT( createNew()));

  _right = new QWidget( this);
  pm = parent->getPixmap( "box_create-right.png");
  _right->setFixedSize( pm->width(), pm->height());
  
  _right->setPaletteBackgroundPixmap( *pm);
  _right->move( parent->width()-_right->width()-25, 150);
  _right->show();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeCreateChar::leftAction()
{
  _parent->mainMenu();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeCreateChar::rightAction()
{
  _parent->startGame( this);
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeCreateChar::createNew()
{
  NodeChooseCharDetails* wid = new NodeChooseCharDetails( _parent);
  wid->setPrevious( this);
  _parent->addWidget( wid);
  _parent->raiseWidget( wid);
}
