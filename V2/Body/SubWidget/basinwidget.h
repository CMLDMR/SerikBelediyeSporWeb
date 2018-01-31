#ifndef BASINWIDGET_H
#define BASINWIDGET_H

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


namespace Basin {
    class BasinWidget : public WContainerWidget
    {
    public:
        BasinWidget();
    };
}



#endif // BASINWIDGET_H
