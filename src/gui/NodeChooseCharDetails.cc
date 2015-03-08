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

#include "NodeChooseCharDetails.hh"

#include "MainWidget.hh"
#include "Util.hh"

#include <QPixmap>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::NodeChooseCharDetails::NodeChooseCharDetails( MainWidget* parent)
        :NodeWindow( parent, "lbl_choose-details.png", "cancel", "accept")
{
  _left = new QWidget( this);
  QPixmap* pm = parent->getPixmap( "box_choose-left.png");
  _left->setFixedSize( pm->width(), pm->height());
  _left->move( 25, 150);
  setBackgroundImage(_left, "box_choose-left.png");
  _left->show();

  _right = new QWidget( this);
  pm = parent->getPixmap( "box_choose-right.png");
  _right->setFixedSize( pm->width(), pm->height());
  _right->move( parent->width()-_right->width()-25, 150);
  setBackgroundImage(_right, "box_choose-right.png");
  _right->show();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeChooseCharDetails::leftAction()
{
  if( _prev != 0)
  {
    _parent->setCurrentWidget( _prev);
    _parent->removeWidget( this);
    deleteLater();
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeChooseCharDetails::rightAction()
{
}
