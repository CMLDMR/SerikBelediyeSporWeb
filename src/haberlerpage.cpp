#include "haberlerpage.h"
#include "databasekeys.h"

HaberlerPage::HaberlerPage(mongocxx::database *_db)
    :WContainerWidget(),
      db(_db)
{

    addStyleClass(Bootstrap::Grid::container_fluid + "HaberlerPage");

    setContentAlignment(AlignmentFlag::Center);
    addWidget(cpp14::make_unique<WText>("Haberler"))->addStyleClass("Haberler");


    auto collection = db->collection(DataBaseKeys::Haberler::collection);

    {
        using namespace Bootstrap::Test;

        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->setContentAlignment(AlignmentFlag::Center);

        container->addWidget(cpp14::make_unique<LastHaber>(&collection))->addStyleClass( Bootstrap::Grid::Large::col_lg_4);

        container->addWidget(cpp14::make_unique<HaberList>())->addStyleClass(Bootstrap::Grid::Large::col_lg_8);
    }

}

LastHaber::LastHaber(mongocxx::collection *_col)
    :WContainerWidget(),
      collection(_col)
{
//    setContentAlignment(AlignmentFlag::Justify);

    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container_fluid);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    addStyleClass(Bootstrap::Grid::row + "LastHaber" + Bootstrap::Test::Color::red );
//    decorationStyle().setBackgroundImage(WLink("urun/news.png"));


    {
        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addWidget(cpp14::make_unique<WImage>(WLink("urun/news.png")));
    }



    {

        try {

            auto option = mongocxx::options::find{};

            auto sortDoc = document{};
            sortDoc.append(kvp(DataBaseKeys::Haberler::haberid,bsoncxx::types::b_int32{1}));

            option.sort(sortDoc.view());

            auto filter = document{};

            filter.append(kvp(DataBaseKeys::Haberler::yayinda,bsoncxx::types::b_bool{DataBaseKeys::Haberler::yayin::yayinda}));

            try {
                mongocxx::stdx::optional<bsoncxx::document::value> val = collection->find_one(filter.view(),option);

                if( val )
                {

                    {
                        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                        container->addStyleClass(Bootstrap::Grid::row);
                        container->addWidget(cpp14::make_unique<WText>(WString::fromUTF8(val.get().view()[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string().c_str())))->addStyleClass("LastHaberTitle");
                    }

                    {
                        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                        container->addStyleClass(Bootstrap::Grid::row);
                        QString str = QString::fromStdString(val.get().view()[DataBaseKeys::Haberler::icerik].get_utf8().value.to_string());
                        str.remove(QRegExp("<[^>]*>"));
                        container->addWidget(cpp14::make_unique<WText>(WString::fromUTF8(str.mid(0,150).toStdString().c_str())));
                    }

                }else{
                    auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                    container->addStyleClass(Bootstrap::Grid::row);
                    container->addWidget(cpp14::make_unique<WText>(WString("No Data Queried")));
                }

            } catch (mongocxx::exception &e) {
                auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                container->addStyleClass(Bootstrap::Grid::row);
                container->addWidget(cpp14::make_unique<WText>(WString("db Error: {1}").arg(e.what())));
            }


        } catch (bsoncxx::exception &e) {
            auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            container->addStyleClass(Bootstrap::Grid::row);
            container->addWidget(cpp14::make_unique<WText>(WString("item Error: {1}").arg(e.what())));
        }
    }

}

HaberList::HaberList()
{

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::container_fluid);
//    container->setContentAlignment(AlignmentFlag::Center);

    {

        auto container1 = container->addWidget(cpp14::make_unique<WContainerWidget>());
        container1->addStyleClass(Bootstrap::Grid::row);

        container1->addWidget(cpp14::make_unique<HaberWidget>("The background-repeat property sets if/how a background image will be repeated"))
                ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
        container1->addWidget(cpp14::make_unique<HaberWidget>("The numbers in the table specify the first browser version that fully supports the property"))
                ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
        container1->addWidget(cpp14::make_unique<HaberWidget>("IE8 and earlier do not support multiple background images on one element"))
                ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
    }

    {

        auto container1 = container->addWidget(cpp14::make_unique<WContainerWidget>());
        container1->addStyleClass(Bootstrap::Grid::row);


        container1->addWidget(cpp14::make_unique<HaberWidget>("The background-repeat property sets if/how a background image will be repeated"))
                ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
        container1->addWidget(cpp14::make_unique<HaberWidget>("The numbers in the table specify the first browser version that fully supports the property"))
                ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
        container1->addWidget(cpp14::make_unique<HaberWidget>("IE8 and earlier do not support multiple background images on one element"))
                ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
    }

}

HaberWidget::HaberWidget(std::string str)
{
    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Grid::container_fluid);
    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass("row");
        auto img = container->addWidget(cpp14::make_unique<WImage>(WLink("urun/news.png")));
        img->setMaximumSize(130,130);
    }

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass("row");
        container->addWidget(cpp14::make_unique<WText>(str))->addStyleClass(Bootstrap::Test::maxWidth150);
    }
}
