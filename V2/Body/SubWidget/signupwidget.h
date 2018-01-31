#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QtCore/qglobal.h>


#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WMenu.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WTextArea.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WGridLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>


#include "bootstrap.h"
#include "inlinestyle.h"


using namespace Wt;


namespace User {

    class SignUpWidget : public WContainerWidget
    {
    public:
        SignUpWidget();
    };

    class SigninWidget : public WContainerWidget
    {
    public:
        SigninWidget();
    };

}


#endif // SIGNUPWIDGET_H
