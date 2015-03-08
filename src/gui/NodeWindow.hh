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

#ifndef NODEWINDOW_HH
#define NODEWINDOW_HH

#include <QWidget>

#include "Buttons.hh"

namespace fanmerc
{
  class MainWidget;
  
  class NodeWindow : public QWidget
  {
    Q_OBJECT

  public:
    NodeWindow( MainWidget* parent, const QString& titlePixmap,
                const QString& left="back", const QString& right="done");
    virtual ~NodeWindow();

    void setPrevious( NodeWindow* prev);
    
  protected slots:
    virtual void leftAction();
    virtual void rightAction();
    
  protected:
    void paintEvent(QPaintEvent* e);
    
    Button* _title;
    Button* _leftButton;
    Button* _rightButton;
    MainWidget* _parent;

    NodeWindow* _prev;
  };
}

#endif
