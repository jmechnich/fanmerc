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

#include <qapplication.h>
#include <qwidget.h>

#include <qsettings.h>
#include <qstring.h>
#include <qrect.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qbitmap.h>
#include <qfile.h>
#include <qprogressbar.h>
#include <qsound.h>
#include <qdir.h>

#include <unistd.h>

#include <string>
#include <iostream>

#include "MainWidget.hh"
#include "PointerMap.hh"

using namespace fanmerc;

int main( int argc, char** argv)
{
  /*-----------------------------------------------------------------------
   *  Create qapplication and get system properties
   *-----------------------------------------------------------------------*/
  QApplication app( argc, argv);
  QSettings settings;
  QDir imageDir( settings.readEntry( "/fanmerc/General/imageDir"));
  QDir soundDir( settings.readEntry( "/fanmerc/General/soundDir"));
  
  /*-----------------------------------------------------------------------
   *  Show splash screen
   *-----------------------------------------------------------------------*/
  QWidget* splash = new QWidget(
      0, "splash",
      Qt::WStyle_NoBorder |Qt::WStyle_StaysOnTop | Qt::WX11BypassWM);
  QPixmap splashBG( imageDir.absPath() + "/bg_splash.png");
  splash->resize( splashBG.width(), splashBG.height());
  splash->setPaletteBackgroundPixmap( splashBG);
  splash->show();
  
  /*-----------------------------------------------------------------------
   *  Open image list file and read it
   *-----------------------------------------------------------------------*/
  PointerMap<QPixmap*> imageMap;
  PointerMap<QBitmap*> maskMap;

  QStringList imageFileNames( imageDir.entryList( "*.png"));
  
  QPixmap* pm;
  for( QStringList::const_iterator it = imageFileNames.begin();
       it != imageFileNames.end(); ++it)
  {
//     splash->message( "Loading image '" + *it + "'",
//                      Qt::AlignBottom | Qt::AlignHCenter,
//                      QColor( 250, 250, 250));
    app.processEvents();
    pm = new QPixmap( imageDir.absPath() + "/" + *it);
    if( pm->isNull())
    {
      std::cerr << "'" << imageDir.absPath() + "/" + *it 
                << "' is a null image" << std::endl;
      return 1;
    }
    imageMap[(*it).latin1()] = pm;

    if( !(*it).startsWith( "bg_"))
    {
//       splash->message( "Creating mask for image '" + *it + "'",
//                        Qt::AlignBottom | Qt::AlignHCenter,
//                        QColor( 250, 250, 250));
      app.processEvents();
      maskMap[(*it).latin1()] = new QBitmap( pm->createHeuristicMask());
    }
  }

  /*-----------------------------------------------------------------------
   *  Load sounds
   *-----------------------------------------------------------------------*/
  PointerMap<QSound*> soundMap;

  QStringList soundFileNames(soundDir.entryList( "*.wav"));
  
  QSound* sound;
  for( QStringList::const_iterator it = soundFileNames.begin();
       it != soundFileNames.end(); ++it)
  {
//     splash->message( "Loading sound '" + *it + "'",
//                      Qt::AlignBottom | Qt::AlignHCenter,
//                      QColor( 250, 250, 250));
    app.processEvents();
    sound = new QSound( soundDir.absPath() + "/" + *it);
    soundMap[(*it).latin1()] = sound;
  }

  /*-----------------------------------------------------------------------
   *  Start the game
   *-----------------------------------------------------------------------*/
  MainWidget mw( &imageMap, &maskMap, &soundMap);
  app.setMainWidget( &mw);
  mw.show();
//   splash->finish( &mw);
  delete splash;
  
  return app.exec();
}
