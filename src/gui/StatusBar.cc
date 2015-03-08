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

#include "StatusBar.hh"


/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::StatusBar::StatusBar( QWidget* parent,
                               const char* name,
                               WFlags f)
        :QWidget( parent, name, f)
{}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::StatusBar::paintEvent( QPaintEvent* e)
{
  QFont font;
  font.setPointSize( 16);
  QPainter painter( this);
  painter.setFont( font);
  painter.drawText( 0, height()/8, width()/6, height(),
                    Qt::AlignRight, _date);
  painter.drawText( 0, height()/8, width()-5, height(),
                    Qt::AlignRight, _gold);
  font.setBold( true);
  font.setItalic( true);
  painter.setFont( font);
  painter.drawText( 0, height()/8, width(), height(),
                    Qt::AlignCenter, _teamname);
  painter.end();
}
