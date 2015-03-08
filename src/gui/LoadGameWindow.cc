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

#include "LoadGameWindow.hh"

#include "MainWidget.hh"
#include "Util.hh"

#include <QFileDialog>
#include <QString>

#include <fstream>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::LoadGameWindow::LoadGameWindow( MainWidget* parent)
        :QWidget( parent), _parent( parent)
{
  setBackgroundImage(this, "bg_brown.png");
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::LoadGameWindow::openFile( GlobalState* globalState)
{
  QString filename = QFileDialog::getOpenFileName();
  if( !filename.isNull())
  {
    globalState->clear();
    std::ifstream is( filename.toStdString().c_str());
    globalState->read( is);
    _parent->startGame();
  }
  else
  {
    _parent->mainMenu();
  }
}

