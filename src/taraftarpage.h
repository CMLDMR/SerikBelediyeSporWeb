#ifndef TARAFTARPAGE_H
#define TARAFTARPAGE_H

#include <QtCore/qglobal.h>
#include <QString>
//#include <experimental/random>
#include <random>

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WMenuItem.h>
#include <Wt/WTabWidget.h>
#include <Wt/WTextArea.h>
#include <Wt/WMenu.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WText.h>
#include <Wt/WTable.h>


#include <vector>

#include "ToolKit/bootstrap.h"


using namespace Wt;

namespace Taraftar {
    class TaraftarPage : public WContainerWidget
    {
    public:
        TaraftarPage();
    };


    class TaraftarWidget : public WContainerWidget
    {
    public:
        TaraftarWidget();
        class Event : public WContainerWidget
        {
        public:
            Event();
        };
    };

    class FaceBookWidget : public WContainerWidget
    {
    public:
        FaceBookWidget();
    };

    class DuyurularWidget : public WContainerWidget
    {
    public:
        DuyurularWidget();

        class item : public WContainerWidget
        {
        public:
            item();
        };
    };
}



#endif // TARAFTARPAGE_H
