#ifndef UTIL_HH
#define UTIL_HH

#include <QString>

class QWidget;

namespace fanmerc 
{
  void setBackgroundImage( QWidget* w, const QString& imageName,
                           const QString& selector="*");
}

#endif // UTIL_HH
