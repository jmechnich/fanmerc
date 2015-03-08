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

#include <qfiledialog.h>
#include <qstring.h>

#include <fstream>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::LoadGameWindow::LoadGameWindow( MainWidget* parent)
        :QWidget( parent), _parent( parent)
{
  setPaletteBackgroundPixmap(
      *(parent->getPixmap("bg_brown.png")));
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
    std::ifstream is( filename.latin1());
    globalState->read( is);
    _parent->startGame();
  }
  else
  {
    _parent->mainMenu();
  }
}

