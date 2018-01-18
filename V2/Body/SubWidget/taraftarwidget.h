#ifndef TARAFTARWIDGET_H
#define TARAFTARWIDGET_H

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


using namespace Wt;


namespace Taraftar {
    class TaraftarWidget : public WContainerWidget
    {
    public:
        TaraftarWidget();

        void initWidget();

        void ListForumItems();

        void addItem(std::string trendCount,std::string okunmaCount,std::string itemtitle, std::string username);

        void initRightMenu();

    private:
        WContainerWidget* mMainContainer;
        WContainerWidget* ContentContainer;
        WContainerWidget* FeautureContainer;
    };
}


#endif // TARAFTARWIDGET_H
