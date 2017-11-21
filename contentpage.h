#ifndef CONTENTPAGE_H
#define CONTENTPAGE_H

#include <QtCore/qglobal.h>

#include <Necessary>

#include "ToolKit/wjavascriptslider.h"

class ContentPage : public WContainerWidget
{
public:
    ContentPage();



    WVBoxLayout* getContentLayout();

private:
    WVBoxLayout* mLayout;


};

#endif // CONTENTPAGE_H
