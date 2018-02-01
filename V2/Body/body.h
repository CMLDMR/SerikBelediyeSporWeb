#ifndef BODY_H
#define BODY_H

#include <QtCore/qglobal.h>
#include <QFile>
#include <QFileInfo>
#include <QDate>

#include <Wt/WContainerWidget.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WImage.h>


#include "bootstrap.h"
#include "inlinestyle.h"
#include "databasekeys.h"

#include "SubWidget/kategorilerwidget.h"
#include "SubWidget/taraftarwidget.h"
#include "SubWidget/okullarwidget.h"
#include "SubWidget/storewidget.h"
#include "SubWidget/tesislerimizwidget.h"
#include "SubWidget/hakkimizdawidget.h"
#include "SubWidget/kupalarwidget.h"
#include "SubWidget/kurumsalwidget.h"
#include "SubWidget/basinwidget.h"
#include "SubWidget/signupwidget.h"

#include "bsoncxx/builder/basic/document.hpp"
#include "bsoncxx/builder/basic/array.hpp"
#include "bsoncxx/builder/basic/kvp.hpp"
#include "bsoncxx/types.hpp"
#include "bsoncxx/document/value.hpp"
#include "bsoncxx/exception/exception.hpp"
#include "bsoncxx/json.hpp"
#include "bsoncxx/document/element.hpp"
#include <bsoncxx/stdx/make_unique.hpp>

#include "mongocxx/client.hpp"
#include "mongocxx/collection.hpp"
#include "mongocxx/exception/exception.hpp"



using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;




using namespace Wt;

namespace Body {

    class MainHaber;
    class Duyurular;


    class Body : public WContainerWidget
    {
    public:
        Body(mongocxx::database* _db);
        WContainerWidget *mainContainer;

        WContainerWidget *SubContainer;
        User::SigninWidget* mSiginWidget;

        void initBody();

        void initKategoriler();
        void initTaraftar();
        void initOkullar();
        void initStore();
        void initTesis();
        void initHakkimizda();
        void initKupalar();
        void initKurumsal();
        void initBasin();
        void initSignUp();
        void initSignIn();


        void setHaberDetail(std::string oid);
        void setDuyuruDetail(std::string oid);

        Signal<DataBaseKeys::Userinfo::User> &mGetSiginSuccess();

    private:
        mongocxx::database* db;

        mongocxx::collection HaberlerCol;
        mongocxx::collection DuyurularCol;
        mongocxx::collection UserCol;

        MainHaber* mMainHaber;
        Duyurular* mDuyuru;

        std::string downloadifNotExist(std::string oid);
        void downloadHtmlimg(std::string oid);

        Signal<DataBaseKeys::Userinfo::User> mSigninSuccess;
    };


    class MainHaber : public WContainerWidget
    {
    public:
        MainHaber(mongocxx::collection* _collection,mongocxx::database* _db);
        WContainerWidget *mainContainer;
        void addHaber(std::string category, std::string title, std::string subTitle, std::string imgpath, std::string oid);

        struct item
        {
            std::string title;
            std::string explain;
            std::string imgPath;
            std::string type;
            std::string oid;
        };
        Signal<std::string> &mGetOid();


    private:
        mongocxx::collection* collection;
        mongocxx::database* db;

        std::vector<item> itemList;

        void initHaberList();

        std::string downloadifNotExist(std::string oid);

        Signal<std::string> oidClicked;

    };


    class SubHaber : public WContainerWidget
    {
    public:
        SubHaber(mongocxx::collection* _collection,mongocxx::database* _db);
        WContainerWidget* mMainContainer;

        void addItem(std::string Cat, std::string title, std::string subTitle , std::string imgPath , std::string videoFoto , std::string styleClass , std::string oid);

        struct item
        {
            std::string title;
            std::string explain;
            std::string imgPath;
            std::string type;
            std::string oid;
        };
        Signal<std::string> &mGetOid();


    private:
        mongocxx::collection* collection;
        mongocxx::database* db;

        std::vector<item> itemList;

        void initHaberList();

        std::string downloadifNotExist(std::string oid);

        Signal<std::string> oidClicked;
    };


    class Duyurular : public WContainerWidget
    {
    public:
        Duyurular(mongocxx::collection* _collection);

        Signal<std::string> &mGetOid();
    private:

        void addLastMatch(WVBoxLayout* _layout);
        void initList(WVBoxLayout* layout);
        void addMatch(WVBoxLayout* _layout, std::string _title, std::string catTitle, std::string takim1, std::string takim2, std::string tarih, std::string saat, std::string yer);
        void addDuyuru(WVBoxLayout *layout, std::string title, std::string icerik, std::string oid);
        WContainerWidget* mMainContainer;
        mongocxx::collection* collection;

        Signal<std::string> _oid;
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
