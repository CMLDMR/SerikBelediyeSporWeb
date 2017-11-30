#ifndef FOTOVIDEOPAGE_H
#define FOTOVIDEOPAGE_H

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


namespace FotoVideo {
    class FotoVideoPage : public WContainerWidget
    {
    public:
        FotoVideoPage();
    };


    class FotoVideoWidget : public WContainerWidget
    {
    public:
        FotoVideoWidget();


        class FotoWidget : public WContainerWidget
        {
        public:
            FotoWidget();

            class item : public WContainerWidget
            {
            public:
                item();
            };
        };


        class VideoWidget : public WContainerWidget
        {
        public:
            VideoWidget();

            class item : public WContainerWidget
            {
            public:
                item();
            };
        };
    };

}


#endif // FOTOVIDEOPAGE_H
