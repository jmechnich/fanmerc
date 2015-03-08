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

#include "HouseWindow.hh"

#include "TownWindow.hh"

#include <QApplication>
#include <QRect>
#include <QListWidget>
#include <QPushButton>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::HouseWindow::HouseWindow( const QString& name,
                                   TownWindow* parent)
        :QWidget( parent), _name( name)
{
  setAttribute(Qt::WA_DeleteOnClose);
  Shop* shop = parent->town()->shop( name.toStdString());
  
  _widget = new QDialog( 0, Qt::SplashScreen);
  _widget->setAttribute(Qt::WA_DeleteOnClose);

  QRect screenRect = parent->geometry();
  _widget->setFixedSize( 450, 600);

  _widget->move( screenRect.center().x() - _widget->width()/2,
                screenRect.center().y() - _widget->height()/2);
  
  /*-----------------------------------------------------------------------
   *  Add user interface
   *-----------------------------------------------------------------------*/
  QPushButton* closeButton = new QPushButton( "Close", _widget);
  QObject::connect( closeButton, SIGNAL( clicked()),
                    _widget, SLOT( close()));

  closeButton->move( _widget->width() - closeButton->width()-10,
                     _widget->height() - closeButton->height()-10);

  QListWidget* listBox = new QListWidget( _widget);
  listBox->setGeometry( 10, 10,
                        _widget->width()-20,
                        _widget->height()-closeButton->height()-25);

  listBox->addItem( "Stats:");
  for( Shop::const_iterator it = shop->statsBegin();
       it != shop->statsEnd(); ++it)
  {
    listBox->addItem(
        QString( it->first.c_str()) + QString(": ") +
        QString( it->second.c_str()));
  }
  listBox->addItem("");

  listBox->addItem( "Actions:");
  for( Shop::const_iterator it = shop->descBegin();
       it != shop->descEnd(); ++it)
  {
    listBox->addItem(
        QString( it->first.c_str()) + QString(": ") +
        QString( it->second.c_str()));
  }
  listBox->addItem("");

  _widget->show();
}
