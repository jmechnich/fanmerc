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

#include <qapplication.h>
#include <qrect.h>
#include <qlistbox.h>
#include <qpushbutton.h>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::HouseWindow::HouseWindow( const QString& name,
                                   TownWindow* parent,
                                   WFlags f)
        :QWidget( parent, name.latin1(), f), _name( name)
{
  Shop* shop = parent->town()->shop( name.latin1());
  
  _widget = new QDialog( 0, 0, true,
                         Qt::WStyle_Splash | Qt::WDestructiveClose);

  QRect screenRect = QApplication::desktop()->availableGeometry();
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

  QListBox* listBox = new QListBox( _widget);
  listBox->setGeometry( 10, 10,
                        _widget->width()-20,
                        _widget->height()-closeButton->height()-25);

  listBox->insertItem( "Stats:");
  for( Shop::const_iterator it = shop->statsBegin();
       it != shop->statsEnd(); ++it)
  {
    listBox->insertItem(
        QString( it->first.c_str()) + QString(": ") +
        QString( it->second.c_str()));
  }
  listBox->insertItem("");

  listBox->insertItem( "Actions:");
  for( Shop::const_iterator it = shop->descBegin();
       it != shop->descEnd(); ++it)
  {
    listBox->insertItem(
        QString( it->first.c_str()) + QString(": ") +
        QString( it->second.c_str()));
  }
  listBox->insertItem("");

  _widget->show();
}
