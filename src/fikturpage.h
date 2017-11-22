#ifndef FIKTURPAGE_H
#define FIKTURPAGE_H

#include <QtCore/qglobal.h>



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


#include <vector>

#include "ToolKit/bootstrap.h"


using namespace Wt;


class FikturPage : public WContainerWidget
{
public:
    FikturPage();
};

#endif // FIKTURPAGE_H
