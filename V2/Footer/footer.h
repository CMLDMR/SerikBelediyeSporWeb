#ifndef FOOTER_H
#define FOOTER_H

#include <QtCore/qglobal.h>


#include <Wt/WContainerWidget.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WAnchor.h>
#include <Wt/WLink.h>
#include <Wt/WLineF.h>



#include "bootstrap.h"

using namespace Wt;

namespace Footer {
    class Footer : public WContainerWidget
    {
    public:
        Footer();


        WContainerWidget* mMainContainerWidget;

    };
}


#endif // FOOTER_H
