#ifndef FRONTPAGEWIDGET_H
#define FRONTPAGEWIDGET_H

#include <QtCore/qglobal.h>



#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WMenu.h>
#include <Wt/WMenuItem.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPopupMenuItem.h>
#include <Wt/WMessageBox.h>
#include <Wt/WCssDecorationStyle.h>







using namespace Wt;


class FrontPageWidget : public WContainerWidget
{
public:
    FrontPageWidget();


    ///
    /// \brief fLoadMenu
    /// Menüleri Yükle
    void fLoadMenu();

private:
    Wt::WNavigationBar *navigation;
};

#endif // FRONTPAGEWIDGET_H
