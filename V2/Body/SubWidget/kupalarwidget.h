#ifndef KUPALARWIDGET_H
#define KUPALARWIDGET_H

#include <QtCore/qglobal.h>

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WMenu.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WTextArea.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>



#include "bootstrap.h"
#include "inlinestyle.h"


using namespace Wt;

namespace Kupa {
class KupalarWidget : public WContainerWidget
{
public:
    KupalarWidget();
};
}


#endif // KUPALARWIDGET_H
