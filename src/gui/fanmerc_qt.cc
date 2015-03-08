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

#include <QApplication>
#include <QSplashScreen>

#include <QSettings>
#include <QString>
#include <QRect>
#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QFile>
#include <QProgressBar>
#include <QSound>
#include <QDir>
#include <QDebug>

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
  app.setOrganizationName("mechnich");
  app.setApplicationName("fanmerc");

  qDebug() << "Loading settings";
  
  QSettings settings;
  QDir imageDir( settings.value( "imageDir").toString());
  if( !imageDir.exists())
  {
    qFatal("Image directory does not exist, exiting");
    return 1;
  }
  QDir soundDir( settings.value( "soundDir").toString());
  if( !soundDir.exists())
  {
    qFatal("Sound directory does not exist, exiting");
    return 1;
  }
  
  /*-----------------------------------------------------------------------
   *  Show splash screen
   *-----------------------------------------------------------------------*/
  qDebug() << "Showing splash screen";
  QPixmap splashBG( imageDir.absolutePath() + "/bg_splash.png");
  QSplashScreen* splash = new QSplashScreen( splashBG);
  splash->show();
  
  /*-----------------------------------------------------------------------
   *  Open image list file and read it
   *-----------------------------------------------------------------------*/
  qDebug() << "Loading images";
  PointerMap<QPixmap*> imageMap;
  PointerMap<QBitmap*> maskMap;

  QStringList imageFilter;
  imageFilter << "*.png";
  QStringList imageFileNames( imageDir.entryList(imageFilter));
  
  QPixmap* pm;
  for( QStringList::const_iterator it = imageFileNames.begin();
       it != imageFileNames.end(); ++it)
  {
    qDebug() << "  ...loading" << *it;
    splash->showMessage( "Loading image '" + *it + "'",
                         Qt::AlignBottom | Qt::AlignHCenter,
                         QColor( 250, 250, 250));
    app.processEvents();
    pm = new QPixmap( imageDir.absolutePath() + "/" + *it);
    if( pm->isNull())
    {
      std::cerr << "'"
                << (imageDir.absolutePath().toStdString() + "/" + it->toStdString()) 
                << "' is a null image" << std::endl;
      return 1;
    }
    imageMap[(*it).toStdString()] = pm;

    if( !(*it).startsWith( "bg_"))
    {
      qDebug() << "  ...creating mask for" << *it;
      splash->showMessage( "Creating mask for image '" + *it + "'",
                           Qt::AlignBottom | Qt::AlignHCenter,
                           QColor( 250, 250, 250));
      app.processEvents();
      maskMap[(*it).toStdString()] = new QBitmap( pm->createHeuristicMask());
    }
  }

  /*-----------------------------------------------------------------------
   *  Load sounds
   *-----------------------------------------------------------------------*/
  qDebug() << "Loading sounds";
  PointerMap<QSound*> soundMap;

  QStringList soundFilter;
  soundFilter << "*.wav";
  QStringList soundFileNames(soundDir.entryList(soundFilter));
  
  QSound* sound;
  for( QStringList::const_iterator it = soundFileNames.begin();
       it != soundFileNames.end(); ++it)
  {
    qDebug() << "  ...loading" << *it;
    splash->showMessage( "Loading sound '" + *it + "'",
                         Qt::AlignBottom | Qt::AlignHCenter,
                         QColor( 250, 250, 250));
    app.processEvents();
    sound = new QSound( soundDir.absolutePath() + "/" + *it);
    soundMap[(*it).toStdString()] = sound;
  }

  /*-----------------------------------------------------------------------
   *  Start the game
   *-----------------------------------------------------------------------*/
  qDebug() << "Starting game";
  MainWidget mw( &imageMap, &maskMap, &soundMap);
  mw.show();
  splash->finish( &mw);
  delete splash;
  
  return app.exec();
}
