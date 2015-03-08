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

#include "TownWindow.hh"

#include "MainWidget.hh"
#include "Util.hh"
#include "Buttons.hh"
#include "StatusBar.hh"
#include "HouseWindow.hh"

#include <QApplication>
#include <QRect>
#include <QStyleOption>

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::TownWindow::TownWindow( MainWidget* parent)
        :QWidget( parent), _parent( parent)
{
  QRect screenRect = parent->geometry();
  setBackgroundImage(this,"bg_camp.png");
  
  _houseButtons["DEFENCE"] = new Button(
      parent->getPixmap("house_defence.png"),
      parent->getPixmap("house_defence_highlight.png"),
      parent->getMask("house_defence.png"),
      this, "DEFENCE");
  _houseButtons["DEFENCE"]->move( 0, screenRect.height()*200/768);

  _houseButtons["OFFICE"] = new Button(
      parent->getPixmap("house_office.png"),
      parent->getPixmap("house_office_highlight.png"),
      parent->getMask("house_office.png"),
      this, "OFFICE");
  _houseButtons["OFFICE"]->move( screenRect.width()*250/1024,
                                 screenRect.height()*440/768);

  _houseButtons["BARRACKS"] = new Button(
      parent->getPixmap("house_barracks.png"),
      parent->getPixmap("house_barracks_highlight.png"),
      parent->getMask("house_barracks.png"),
      this, "BARRACKS");
  _houseButtons["BARRACKS"]->move( screenRect.width()*160/1024,
                                   screenRect.height()*500/768);

  _houseButtons["HALL"] = new Button(
      parent->getPixmap("house_hall.png"),
      parent->getPixmap("house_hall_highlight.png"),
      parent->getMask("house_hall.png"),
      this, "HALL");
  _houseButtons["HALL"]->move( screenRect.width()*70/1024,
                               screenRect.height()*550/768);

  _houseButtons["ENGINEER"] = new Button(
      parent->getPixmap("house_engineer.png"),
      parent->getPixmap("house_engineer_highlight.png"),
      parent->getMask("house_engineer.png"),
      this, "ENGINEER");
  _houseButtons["ENGINEER"]->move( 0,
                                   screenRect.height()*650/768);

  _houseButtons["BLACKSMITH"] = new Button(
      parent->getPixmap("house_blacksmith.png"),
      parent->getPixmap("house_blacksmith_highlight.png"),
      parent->getMask("house_blacksmith.png"),
      this, "BLACKSMITH");
  _houseButtons["BLACKSMITH"]->move( screenRect.width()*620/1024,
                                     screenRect.height()*440/768);

  _houseButtons["LIBRARY"] = new Button(
      parent->getPixmap("house_library.png"),
      parent->getPixmap("house_library_highlight.png"),
      parent->getMask("house_library.png"),
      this, "LIBRARY");
  _houseButtons["LIBRARY"]->move( screenRect.width()*700/1024,
                                  screenRect.height()*450/768);

  _houseButtons["MAGICTOWER"] = new Button(
      parent->getPixmap("house_mageTower.png"),
      parent->getPixmap("house_mageTower_highlight.png"),
      parent->getMask("house_mageTower.png"),
      this, "MAGICTOWER");
  _houseButtons["MAGICTOWER"]->move( screenRect.width()*750/1024,
                                     screenRect.height()*480/768);

  _houseButtons["STORAGE"] = new Button(
      parent->getPixmap("house_storage.png"),
      parent->getPixmap("house_storage_highlight.png"),
      parent->getMask("house_storage.png"),
      this, "STORAGE");
  _houseButtons["STORAGE"]->move( screenRect.width()*800/1024,
                                  screenRect.height()*510/768);

  _houseButtons["TREASURY"] = new Button(
      parent->getPixmap("house_treasury.png"),
      parent->getPixmap("house_treasury_highlight.png"),
      parent->getMask("house_treasury.png"),
      this, "TREASURY");
  _houseButtons["TREASURY"]->move( screenRect.width()*910/1024,
                                   screenRect.height()*580/768);

  _houseButtons["WELL"] = new Button(
      parent->getPixmap("house_well.png"),
      parent->getPixmap("house_well_highlight.png"),
      parent->getMask("house_well.png"),
      this, "WELL");
  _houseButtons["WELL"]->move( screenRect.width()/2 -
                               _houseButtons["WELL"]->width()/2,
                               screenRect.height()*650/768);
  

  for( std::map<std::string,Button*>::iterator it=_houseButtons.begin();
       it != _houseButtons.end(); ++it)
  {
    QObject::connect( it->second, SIGNAL( clicked()),
                      this, SLOT( showHouseWindow()));
    QObject::connect( it->second, SIGNAL( highlighted()),
                      this, SLOT( update()));
    it->second->show();
  }

  _statusBar = new StatusBar( this);

  QPixmap* pm = parent->getPixmap( "bg_camp_header.png");
  _statusBar->setFixedSize( pm->width(), pm->height());
  setBackgroundImage(_statusBar, "bg_camp_header.png");
  _statusBar->updateDate( parent->global()->statAsInt( "date"));
  _statusBar->updateGold( parent->team()->statAsInt( "gold"));
  _statusBar->updateTeamname( parent->team()->statAsString( "name").c_str());
  _statusBar->show();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::TownWindow::~TownWindow()
{
  for( std::map<std::string,Button*>::iterator it=_houseButtons.begin();
       it != _houseButtons.end(); ++it)
  {
    it->second->close();
  }
  _statusBar->close();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Button*
fanmerc::TownWindow::button( const std::string& name)
{
  std::map<std::string,Button*>::iterator it = _houseButtons.find( name);
  if( it != _houseButtons.end())
  {
    return it->second;
  }
  else
  {
    return 0;
  }
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::TownWindow::showHouseWindow()
{
  new HouseWindow( sender()->objectName(), this);
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::Town*
fanmerc::TownWindow::town()
{
  return _parent->town();
}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
void
fanmerc::TownWindow::paintEvent(QPaintEvent *pe)
{
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}
