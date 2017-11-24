#include "haberlerpage.h"

HaberlerPage::HaberlerPage()
{

    addStyleClass(Bootstrap::Grid::container_fluid + "HaberlerPage");

    setContentAlignment(AlignmentFlag::Center);
    addWidget(cpp14::make_unique<WText>("Haberler"))->addStyleClass("Haberler");

    {
        using namespace Bootstrap::Test;

        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->setContentAlignment(AlignmentFlag::Center);

        container->addWidget(cpp14::make_unique<LastHaber>())->addStyleClass( Bootstrap::Grid::Large::col_lg_4);

        container->addWidget(cpp14::make_unique<HaberList>())->addStyleClass(Bootstrap::Grid::Large::col_lg_8);
    }

}

LastHaber::LastHaber()
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
        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addWidget(cpp14::make_unique<WText>("Lorem Ipsum Nedir?"))->addStyleClass("LastHaberTitle");
    }

    {
        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->addWidget(cpp14::make_unique<WText>("Lorem Ipsum, dizgi ve baskı endüstrisinde kullanılan mıgır metinlerdir."
                                                       " Lorem Ipsum, adı bilinmeyen bir matbaacının bir hurufat numune kitabı "
                                                       "oluşturmak üzere bir yazı galerisini alarak karıştırdığı 1500'lerden "
                                                       "beri endüstri standardı sahte metinler olarak"));
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
