#ifndef HABERLERPAGE_H
#define HABERLERPAGE_H

#include <QtCore/qglobal.h>
#include <QString>
#include <QRegExp>


#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WCssDecorationStyle.h>

#include <vector>

#include "ToolKit/bootstrap.h"

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



private:

    mongocxx::database* db;




};


class LastHaber : public WContainerWidget
{
public:
    LastHaber(mongocxx::collection* _col);

private:
    mongocxx::collection* collection;
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
