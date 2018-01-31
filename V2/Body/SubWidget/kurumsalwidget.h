#ifndef KURUMSALWIDGET_H
#define KURUMSALWIDGET_H

#include <QtCore/qglobal.h>

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WMenu.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WTextArea.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>


#include "bootstrap.h"
#include "inlinestyle.h"


using namespace Wt;

namespace Kurumsal {

    class KurumsalWidget : public WContainerWidget
    {
    public:
        KurumsalWidget();
    };

}



#endif // KURUMSALWIDGET_H
