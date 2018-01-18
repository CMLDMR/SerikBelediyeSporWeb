#ifndef OKULLARWIDGET_H
#define OKULLARWIDGET_H

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

namespace Okul {
    class OkullarWidget : public WContainerWidget
    {
    public:
        OkullarWidget();

        void addOkul(std::string okulName, std::string backimgPath);

    private:
        WContainerWidget *mMainContainer,*ContentContainer,*tempContainer,*mContentContainer;
    };
}


#endif // OKULLARWIDGET_H
