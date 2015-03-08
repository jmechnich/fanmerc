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

#ifndef MAINWIDGET_HH
#define MAINWIDGET_HH

#include <QPixmap>
#include <QBitmap>
#include <QSound>
#include <QStackedWidget>

#include "PointerMap.hh"

#include <GlobalState.hh>
#include <Town.hh>
#include <Team.hh>

#include <iostream>


namespace fanmerc
{

  class NodeWindow;
  
class MainWidget : public QStackedWidget
{
  Q_OBJECT

  
public:
    
  MainWidget( PointerMap<QPixmap*>* imageMap,
              PointerMap<QBitmap*>* maskMap,
              PointerMap<QSound*>* soundMap);

  QPixmap* getPixmap( const QString& fileName);
  QBitmap* getMask( const QString& fileName);
  QSound* getSound( const QString& fileName);
  GlobalState* global();
  Town* town();
  Team* team();
    
protected:
  void keyPressEvent( QKeyEvent* e);
  
public slots:
  void mainMenu();
  void newGame();
  void loadGame();
  void startGame( NodeWindow* oldNode=0);
  void exitGame();
  
  void beep();
  
private:
  PointerMap<QPixmap*>*  _imageMap;
  PointerMap<QBitmap*>*  _maskMap;
  PointerMap<QSound*>*  _soundMap;
  int _centerX, _centerY;

  GlobalState* _globalState;
};
 
}

#include "MainWidget.icc"

#endif
