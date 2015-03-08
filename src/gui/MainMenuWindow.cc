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

#include <qpushbutton.h>
#include <qapplication.h>
#include <qimage.h>
#include <qpainter.h>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::MainMenuWindow::MainMenuWindow( MainWidget* parent)
        :QWidget( parent, "MainMenuWindow", Qt::WDestructiveClose)
{
  /*-----------------------------------------------------------------------
   *  Set size and position of window
   *-----------------------------------------------------------------------*/
  setPaletteBackgroundPixmap( *(parent->getPixmap("bg_camp.png")));
  _widget = new QWidget( this, 0, Qt::WStyle_NoBorder | Qt::WX11BypassWM);
  
  QRect screenRect = QApplication::desktop()->availableGeometry();
  _widget->setFixedSize( 450, 600);

  _widget->move( screenRect.center().x() - _widget->width()/2,
                screenRect.center().y() - _widget->height()/2);
  _widget->setPaletteBackgroundPixmap( *parent->getPixmap( "bg_atat.png"));
  
  /*-----------------------------------------------------------------------
   *  Add user interface
   *-----------------------------------------------------------------------*/
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

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::MainMenuWindow::~MainMenuWindow()
{}
