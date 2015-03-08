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

#include <QAbstractButton>

class QPixmap;
class QBitmap;

namespace fanmerc
{
class Button : public QAbstractButton
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
  void paintEvent( QPaintEvent* e);
  void mousePressEvent( QMouseEvent* e);
  void mouseReleaseEvent( QMouseEvent* e);
  
private:
  QPixmap *_defaultPixmap, *_highlightedPixmap, *_currentPixmap;
  bool _mousePressed, _highlighted;
};
  
}

#endif
