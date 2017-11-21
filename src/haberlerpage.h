#ifndef HABERLERPAGE_H
#define HABERLERPAGE_H

#include <QtCore/qglobal.h>


#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>

#include <vector>


using namespace Wt;

class LastHaber;
class HaberList;
class HaberWidget;

class HaberlerPage : public WContainerWidget
{
public:
    HaberlerPage();




};


class LastHaber : public WContainerWidget
{
public:
    LastHaber();
};

class HaberList : public WContainerWidget
{
public:
    HaberList();
};


class HaberWidget : public WContainerWidget
{
public:
    HaberWidget(std::string str = "Son 6 Haber");
};

#endif // HABERLERPAGE_H
