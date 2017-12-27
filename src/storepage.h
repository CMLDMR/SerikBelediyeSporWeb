#ifndef STOREPAGE_H
#define STOREPAGE_H

#include <QtCore/qglobal.h>

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WMenu.h>
#include <Wt/WMenuItem.h>
#include <Wt/WText.h>
#include <Wt/WBootstrapTheme.h>
#include <Wt/WPushButton.h>
#include <Wt/WCssDecorationStyle.h>


#include <vector>

using namespace Wt;


class Urun;

class StorePage : public WContainerWidget
{
public:
    StorePage();

};


class Urun : public WContainerWidget
{
public:
    Urun();
};

#endif // STOREPAGE_H
