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

#ifndef STATUSBAR_HH
#define STATUSBAR_HH

#include <QWidget>
#include <QString>
#include <QPainter>

namespace fanmerc
{

class StatusBar : public QWidget
{
public:
  StatusBar( QWidget* parent=0);
  void updateDate( int date);
  void updateGold( int gold);
  void updateTeamname( const QString& teamname);
  
protected:
  void paintEvent( QPaintEvent* e);
private:
  QString _date, _gold, _teamname;
};
}

#include "StatusBar.icc"

#endif
