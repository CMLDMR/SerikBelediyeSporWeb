#ifndef BASINPAGE_H
#define BASINPAGE_H

#include <QtCore/qglobal.h>

#include <QString>
#include <random>

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
#include <Wt/WText.h>
#include <Wt/WTable.h>
#include <Wt/WComboBox.h>


#include <vector>

#include "ToolKit/bootstrap.h"


using namespace Wt;


namespace Medya {
    class MedyaPage : public WContainerWidget
    {
    public:
        MedyaPage();
    };

    class MedyaWidget : public WContainerWidget
    {
    public:
        MedyaWidget();
        class BasinWidget : public WContainerWidget
        {
        public:
            BasinWidget();

            class item : public WContainerWidget
            {
            public:
                item();
            };
        };


        class SocialWidget : public WContainerWidget
        {
        public:
            SocialWidget();
        };


        class YayinlarWidget : public WContainerWidget
        {
        public:
            YayinlarWidget();
        };
    };




}




#endif // BASINPAGE_H
