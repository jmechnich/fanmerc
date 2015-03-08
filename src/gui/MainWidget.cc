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

#include "MainWidget.hh"
#include "MainMenuWindow.hh"
#include "NodeWindow.hh"
#include "NodeCreateChar.hh"
#include "LoadGameWindow.hh"
#include "TownWindow.hh"

#include <QApplication>
#include <QDesktopWidget>
#include <QSound>
#include <QPainter>
#include <QMessageBox>
#include <QKeyEvent>

#include <iostream>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::MainWidget::MainWidget( PointerMap<QPixmap*>* imageMap,
                                 PointerMap<QBitmap*>* maskMap,
                                 PointerMap<QSound*>* soundMap)
        :QStackedWidget(), _imageMap( imageMap), _maskMap( maskMap),
         _soundMap( soundMap),
         _globalState( new GlobalState)
{
  //showFullScreen();
  setFixedSize( 1024, 768);
  QRect screenRect = QApplication::desktop()->availableGeometry();
  move(screenRect.width()/2  - 512, screenRect.height()/2 - 384);
  
  mainMenu();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::MainWidget::mainMenu()
{
  QWidget* oldWid = currentWidget();
  QWidget* newWid = new MainMenuWindow( this);
  addWidget( newWid);
  setCurrentWidget( newWid);

  if( oldWid != 0)
  {
    removeWidget( oldWid);
    oldWid->close();
  }
}
  
/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::MainWidget::newGame()
{
  QWidget* wid = 0;
  wid = currentWidget();

  QWidget* newWid = new NodeCreateChar( this);
  addWidget( newWid);
  setCurrentWidget( newWid);

  if( wid != 0)
  {
    removeWidget( wid);
    wid->close();
  }
}
  
/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::MainWidget::startGame( NodeWindow* oldNode)
{
  QWidget* newWid = new TownWindow( this);
  addWidget( newWid);
  setCurrentWidget( newWid);

  if( oldNode != 0)
  {
    removeWidget( oldNode);
    oldNode->close();
  }
}
  
/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::MainWidget::loadGame()
{
  QWidget* wid = 0;
  wid = currentWidget();

  LoadGameWindow* newWid = new LoadGameWindow( this);
  addWidget( newWid);
  setCurrentWidget( newWid);
  if( wid != 0)
  {
    removeWidget( wid);
    delete wid;
  }
  newWid->openFile( _globalState);
}


/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::MainWidget::exitGame()
{
  switch( QMessageBox::information( this, "Quit Fanmerc",
                                    "Do you really want to quit ?",
                                    "Yes", "No", QString::null, 1))
  {
  case( 0):
    qApp->quit();
    break;
  case( 1):
    break;
  default:
    break;
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::MainWidget::keyPressEvent( QKeyEvent* e)
{
  switch( e->key())
  {
  case(Qt::Key_Escape):
    if( dynamic_cast<MainMenuWindow*>( currentWidget()) != 0)
    {
      exitGame();
    }
    else
    {
      mainMenu();
    }
  default:
    e->accept();
    break;
  }
}
