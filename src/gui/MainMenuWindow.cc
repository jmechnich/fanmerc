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

#include "MainMenuWindow.hh"

#include "MainWidget.hh"
#include "Util.hh"

#include <QPushButton>
#include <QDebug>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::MainMenuWindow::MainMenuWindow( MainWidget* parent)
        :QWidget( parent)
{
  qDebug() << "Drawing MainMenuWindow -" << metaObject()->className();
  
  setAttribute(Qt::WA_DeleteOnClose);
  setObjectName("TitleBackground");
  setBackgroundImage(this, "bg_camp.png", "QWidget#TitleBackground");
    
  /*-----------------------------------------------------------------------
   *  Set size and position of window
   *-----------------------------------------------------------------------*/
  qDebug() << "  ...drawing title";
  _widget = new QWidget( this, Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
  _widget->setObjectName("TitleScreen");
  setBackgroundImage( _widget, "bg_atat.png", "QWidget#TitleScreen");
  
  QRect screenRect = parent->geometry();
  _widget->setFixedSize( 450, 600);
  _widget->move( screenRect.width()/2  - _widget->width()/2,
                 screenRect.height()/2 - _widget->height()/2);
  qDebug() << "  ...geometry" << _widget->geometry();


  /*-----------------------------------------------------------------------
   *  Add user interface
   *-----------------------------------------------------------------------*/
  qDebug() << "  ...drawing buttons";
  QPushButton* newButton = new QPushButton( "New", _widget);
  QPushButton* loadButton = new QPushButton( "Load", _widget);
  QPushButton* exitButton = new QPushButton( "Exit", _widget);
  QObject::connect( newButton, SIGNAL( clicked()),
                    parent, SLOT( newGame()));
  QObject::connect( loadButton, SIGNAL( clicked()),
                    parent, SLOT( loadGame()));
  QObject::connect( exitButton, SIGNAL( clicked()),
                    parent, SLOT( exitGame()));

  newButton->move( 10,
                   _widget->height() - newButton->height()-10);
  loadButton->move( _widget->width()/2 - loadButton->width()/2,
                    _widget->height() - loadButton->height()-10);
  exitButton->move( _widget->width() - exitButton->width()-10,
                    _widget->height() - exitButton->height()-10);
  _widget->show();
}
