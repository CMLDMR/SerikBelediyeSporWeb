#ifndef CONTENTPAGE_H
#define CONTENTPAGE_H

#include <QtCore/qglobal.h>

#include "bootstrap.h"

#include <Necessary>

#include "ToolKit/wjavascriptslider.h"

class ContentPage : public WContainerWidget
{
public:
    ContentPage();

    WContainerWidget *getContentLayout();

    WContainerWidget *getFooterLayout();

    void initLayout();



    void setHaber(std::string oid);

private:
    WVBoxLayout* mLayout;

    WContainerWidget* mMainContainer,*mContentContainer;

    WVBoxLayout* mSubLayout;


};

#endif // CONTENTPAGE_H
