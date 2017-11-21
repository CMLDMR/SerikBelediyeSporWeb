#ifndef WJAVASCRIPTSLIDER_H
#define WJAVASCRIPTSLIDER_H

#include <QtCore/qglobal.h>
#include <QString>

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>

#include <vector>


using namespace Wt;


class WJavaScriptSlider : public WContainerWidget
{
public:
    WJavaScriptSlider();

    void appendimg(std::string title, std::string link);

    WContainerWidget* imgcontainer;
    WContainerWidget* dotContainer;

    WHBoxLayout* dotLayout;

    struct imgItem
    {
        std::string title;
        std::string link;
        std::string widgetid;
        std::string dotid;
    };

    std::vector<imgItem> imgList;


};

#endif // WJAVASCRIPTSLIDER_H
