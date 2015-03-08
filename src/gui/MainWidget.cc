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

#include <qapplication.h>
#include <qsound.h>
#include <qpainter.h>
#include <qmessagebox.h>

#include <iostream>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::MainWidget::MainWidget( PointerMap<QPixmap*>* imageMap,
                                 PointerMap<QBitmap*>* maskMap,
                                 PointerMap<QSound*>* soundMap)
        :QWidgetStack(), _imageMap( imageMap), _maskMap( maskMap),
         _soundMap( soundMap),
         _globalState( new GlobalState)
{
  showFullScreen();
  
  mainMenu();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::MainWidget::mainMenu()
{
  QWidget* oldWid = visibleWidget();
  QWidget* newWid = new MainMenuWindow( this);
  addWidget( newWid);
  raiseWidget( newWid);

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
  wid = visibleWidget();

  QWidget* newWid = new NodeCreateChar( this);
  addWidget( newWid);
  raiseWidget( newWid);

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
  raiseWidget( newWid);

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
  wid = visibleWidget();

  LoadGameWindow* newWid = new LoadGameWindow( this);
  addWidget( newWid);
  raiseWidget( newWid);
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
  switch( QMessageBox::information( 0, "Quit Fanmerc",
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
  case(Key_Escape):
    if( dynamic_cast<MainMenuWindow*>( visibleWidget()) != 0)
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
