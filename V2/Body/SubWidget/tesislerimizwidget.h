#ifndef TESISLERIMIZWIDGET_H
#define TESISLERIMIZWIDGET_H

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



namespace Tesis {


    class TesislerimizWidget : public WContainerWidget
    {
    public:
        TesislerimizWidget();
    };


}



#endif // TESISLERIMIZWIDGET_H
