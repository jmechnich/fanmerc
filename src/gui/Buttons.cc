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

#include "Buttons.hh"

#include <QPainter>
#include <QBitmap>
#include <QPixmap>
#include <QMouseEvent>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Button::Button( QPixmap* defaultPixmap,
                         QPixmap* highlightedPixmap,
                         QBitmap* mask,
                         QWidget* parent,
                         const char* name)
        :QAbstractButton( parent),
         _defaultPixmap( defaultPixmap),
         _highlightedPixmap( highlightedPixmap),
         _currentPixmap( defaultPixmap),
         _mousePressed( false),
         _highlighted( false)
{
  setObjectName( name);
  setAttribute( Qt::WA_DeleteOnClose);
  setFixedSize( _defaultPixmap->width(), _defaultPixmap->height());
  setMask( *mask);
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Button::enterEvent( QEvent*)
{
  _currentPixmap = _highlightedPixmap;
  _highlighted = true;
  update();
  emit( highlighted());
}
  
/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Button::leaveEvent( QEvent*)
{
  _currentPixmap =  _defaultPixmap;
  _highlighted = false;
  update();
  emit( unhighlighted());
}
  
/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Button::paintEvent( QPaintEvent* e)
{
  QPainter painter(this);
  painter.drawPixmap( 0, 0, *_currentPixmap);
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Button::mousePressEvent( QMouseEvent* e)
{
  e->accept();
  _mousePressed = true;
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::Button::mouseReleaseEvent( QMouseEvent* e)
{
  e->accept();
  if( _mousePressed)
  {
    emit( clicked());
  }
  _mousePressed = false;
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
bool
fanmerc::Button::isHighlighted() const
{
  return _highlighted;
}
