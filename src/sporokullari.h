#ifndef SPOROKULLARI_H
#define SPOROKULLARI_H

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

#include "bootstrap.h"


using namespace Wt;


namespace Okullar {
    class SporOkullari : public WContainerWidget
    {
    public:
        SporOkullari();


    };


    class SporOkullariWidget : public WContainerWidget
    {
    public:
        SporOkullariWidget();


        class item : public WContainerWidget
        {
        public:
            item(std::string okuladi = "Yaz Okulu Adı");
        };
    };



    class AktiviteWidget : public WContainerWidget
    {
    public:
        AktiviteWidget();

        class item : public WContainerWidget
        {
        public:
            item(std::string okuladi = "Aktivite Adı");
        };
    };




}



#endif // SPOROKULLARI_H
