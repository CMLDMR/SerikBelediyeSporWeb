#ifndef BODY_H
#define BODY_H

#include <QtCore/qglobal.h>

#include <Wt/WContainerWidget.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WImage.h>


#include "bootstrap.h"

#include "SubWidget/kategorilerwidget.h"
#include "SubWidget/taraftarwidget.h"
#include "SubWidget/okullarwidget.h"
#include "SubWidget/storewidget.h"



using namespace Wt;

namespace Body {
    class Body : public WContainerWidget
    {
    public:
        Body();
        WContainerWidget *mainContainer;

        WContainerWidget *SubContainer;

        void initBody();

        void initKategoriler();
        void initTaraftar();
        void initOkullar();
        void initStore();
    };


    class MainHaber : public WContainerWidget
    {
    public:
        MainHaber();
        WContainerWidget *mainContainer;
        void addHaber(std::string category,std::string title, std::string subTitle, std::string imgpath);
    };


    class SubHaber : public WContainerWidget
    {
    public:
        SubHaber();
        WContainerWidget* mMainContainer;

        void addItem(std::string Cat, std::string title, std::string subTitle , std::string imgPath , std::string videoFoto , std::string styleClass );
    };


    class Duyurular : public WContainerWidget
    {
    public:
        Duyurular();

        WContainerWidget* mMainContainer;
    };



    class Kategoriler : public WContainerWidget
    {
    public:
        Kategoriler();

        WContainerWidget* mMainContainerWidget;

        void addItem(std::string title,std::string imgPath, std::string subTitle);
    };


    class PhotoVideo : public WContainerWidget
    {
    public:
        PhotoVideo();

        WContainerWidget* mMainContainer;


        WContainerWidget* SliderContainer,*SliderSubContainer;

        WHBoxLayout* fLayout;


        void addItem(std::string imgPath, bool video = false, std::string title = "Başlık");

    };



    class Ozellerimiz : public WContainerWidget
    {
    public:
        Ozellerimiz();

        WContainerWidget* mMainContainer;
    };


}


#endif // BODY_H
