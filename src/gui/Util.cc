#include "Util.hh"

#include <QWidget>
#include <QString>
#include <QSettings>
#include <QDir>
#include <QDebug>

void
fanmerc::setBackgroundImage( QWidget* w, const QString& imageName,
                             const QString& selector)
{
  if(!w) return;
  
  QSettings settings;
  QDir imageDir(settings.value("imageDir").toString());
  if( !imageDir.exists( imageName))
  {
    qDebug() << "Could not open image file: " << imageName;
    return;
  }
  QString stylesheet = QString("%1 { background: url(%2); }").arg(
      selector, imageDir.filePath(imageName));
  // QString stylesheet = QString("background-image: url(%1)").arg(
  //     imageDir.filePath(imageName));
  qDebug() << QString("Setting style sheet for '%1' of class '%2' to: '%3'").arg(
      w->objectName(), w->metaObject()->className(), stylesheet).toStdString().c_str();
  w->setStyleSheet(stylesheet);
}
