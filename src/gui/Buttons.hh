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

#ifndef BUTTONS_HH
#define BUTTONS_HH

#include <qbutton.h>

class QPixmap;
class QBitmap;

namespace fanmerc
{
class Button : public QButton
{
  Q_OBJECT

public:
  Button( QPixmap* defaultPixmap,
          QPixmap* highlightedPixmap,
          QBitmap* mask,
          QWidget* parent=0, const char* name=0);

  bool isHighlighted() const;

signals:
  void highlighted();
  void unhighlighted();
  
protected:
  void enterEvent( QEvent*);
  void leaveEvent( QEvent*);
  void drawButton( QPainter* painter);
  void mousePressEvent( QMouseEvent* e);
  void mouseReleaseEvent( QMouseEvent* e);
  
private:
  QPixmap *_defaultPixmap, *_highlightedPixmap, *_currentPixmap;
  bool _mousePressed, _highlighted;
};
  
}

#endif
