#ifndef HABERLERPAGE_H
#define HABERLERPAGE_H

#include <QtCore/qglobal.h>
#include <QString>
#include <QRegExp>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>


#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WSignal.h>

#include <vector>

#include "bootstrap.h"

#include "mongoheaders.h"


using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;



using namespace Wt;

class LastHaber;
class HaberList;
class HaberWidget;

class HaberlerPage : public WContainerWidget
{
public:
    HaberlerPage(mongocxx::database* _db);



    Signal<std::string> &ClickLastHaber();


private:
    mongocxx::database* db;

    LastHaber* mLastHaber;
    HaberList* mHaberList;
};






class LastHaber : public WContainerWidget
{
public:
    LastHaber(mongocxx::collection* _col, mongocxx::gridfs::bucket *_bucket);

    Signal<std::string> mClicked;

private:
    mongocxx::collection* collection;
    mongocxx::gridfs::bucket* bucket;

    std::string oid;
};





class HaberList : public WContainerWidget
{
public:
    HaberList(mongocxx::collection* _col, mongocxx::gridfs::bucket *_bucket);

private:
    mongocxx::collection* collection;
    mongocxx::gridfs::bucket* bucket;
};




class HaberWidget : public WContainerWidget
{
public:
    HaberWidget(std::string str = "Son 6 Haber", std::string iconPath = "urun/news.png");
};

#endif // HABERLERPAGE_H
