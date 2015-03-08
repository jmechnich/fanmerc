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

#include "NodeWindow.hh"

#include "MainWidget.hh"
#include "Util.hh"

#include <QPixmap>
#include <QBitmap>
#include <QStyleOption>
#include <QPainter>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::NodeWindow::NodeWindow( MainWidget* parent,
                                 const QString& titlePixmap,
                                 const QString& left, const QString& right)
        :QWidget( parent),
         _parent( parent), _prev( 0)
{
  setAttribute( Qt::WA_DeleteOnClose);
  setBackgroundImage(this, "bg_brown_lbl2.png");
  
  _title = new Button( parent->getPixmap(titlePixmap),
                       parent->getPixmap(titlePixmap),
                       parent->getMask(titlePixmap),
                       this);
  _title->move( parent->width()/2-_title->width()/2, parent->height()/13);
  _title->show();
  
  _leftButton =
      new Button( parent->getPixmap("btn_" + left + ".png"),
                  parent->getPixmap("btn_" + left + "_highlight.png"),
                  parent->getMask("btn_" + left + ".png"),
                  this);
  _leftButton->move( parent->width()/1024*125 - _leftButton->width()/2,
                     parent->height()/768*80 - _leftButton->height()/2);
  _leftButton->show();
  
  _rightButton =
      new Button( parent->getPixmap("btn_" + right + ".png"),
                  parent->getPixmap("btn_" + right + "_highlight.png"),
                  parent->getMask("btn_" + right + ".png"),
                  this);
  _rightButton->move( parent->width()/1024*910 - _rightButton->width()/2,
                      parent->height()/768*80 - _rightButton->height()/2);
  _rightButton->show();

  QObject::connect( _leftButton, SIGNAL( clicked()),
                    this, SLOT( leftAction()));
  QObject::connect( _leftButton, SIGNAL( highlighted()),
                    parent, SLOT( beep()));
  
  QObject::connect( _rightButton, SIGNAL( clicked()),
                    this, SLOT( rightAction()));
  QObject::connect( _rightButton, SIGNAL( highlighted()),
                    parent, SLOT( beep()));
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::NodeWindow::~NodeWindow()
{
  _rightButton->close();
  _leftButton->close();
  
  _title->close();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeWindow::leftAction()
{
  std::cout << "NodeWindow left action" << std::endl;
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeWindow::rightAction()
{
  std::cout << "NodeWindow right action" << std::endl;
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeWindow::setPrevious( NodeWindow* prev)
{
  _prev = prev;
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::NodeWindow::paintEvent(QPaintEvent *pe)
{
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}
