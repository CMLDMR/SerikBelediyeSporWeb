#include "kategorilerwidget.h"

#include <random>

KategorilerWidget::KategorilerWidget()
    :WContainerWidget()
{



//    addStyleClass("multbg-top-to-bottom");
//    setHeight(500);

    addStyleClass(Bootstrap::Grid::container_fluid);
    setPadding(25,AllSides);

    addWidget(cpp14::make_unique<WText>("Kategoriler"))->setAttributeValue("style","color:white;font-size:25px;font-weight:bold;padding-bottom:20px;margin:20px;");

    auto mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->setPadding(20,Side::Top);

    mMainContainer->addStyleClass(Bootstrap::Grid::row);

    std::vector<std::string> picList;

    picList.push_back("img/futbol.jpg");
    picList.push_back("img/basketbol.jpg");
    picList.push_back("img/golf.jpg");
    picList.push_back("img/hentbol.jpg");
    picList.push_back("img/voleybol.jpg");


    std::default_random_engine generator;
    std::uniform_int_distribution<int> distrubution(0,4);



    {
        auto container = Wt::cpp14::make_unique<Wt::WContainerWidget>();
        container->setHeight(250);
//        container.get()->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thin,WColor("rgb(255,0,0)")));
        container.get()->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container.get()->setAttributeValue("style","background:url(img/futbol.jpg); background-size:cover;");
        container.get()->addStyleClass("KatergoriTitleItem");
        container.get()->setContentAlignment(AlignmentFlag::Center|AlignmentFlag::Middle);
        container.get()->addWidget(cpp14::make_unique<WText>("Fulbol"))->addStyleClass("KatergoriTitle");

        mMainContainer->addWidget(std::move(container));
    }

    {
        auto container = Wt::cpp14::make_unique<Wt::WContainerWidget>();
        container->setHeight(250);
//        container.get()->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thin,WColor("rgb(255,0,0)")));
        container.get()->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container.get()->setAttributeValue("style","background:url(img/basketbol.jpg); background-size:cover;");
        container.get()->addStyleClass("KatergoriTitleItem");
        container.get()->setContentAlignment(AlignmentFlag::Center);
        container.get()->addWidget(cpp14::make_unique<WText>("Basketbol"))->addStyleClass("KatergoriTitle");

        mMainContainer->addWidget(std::move(container));
    }

    {
        auto container = Wt::cpp14::make_unique<Wt::WContainerWidget>();
        container->setHeight(250);
//        container.get()->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thin,WColor("rgb(255,0,0)")));
        container.get()->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container.get()->setAttributeValue("style","background:url(img/golf.jpg); background-size:cover;");
        container.get()->addStyleClass("KatergoriTitleItem");
        container.get()->setContentAlignment(AlignmentFlag::Center);
        container.get()->addWidget(cpp14::make_unique<WText>("Golf"))->addStyleClass("KatergoriTitle");

        mMainContainer->addWidget(std::move(container));
    }

    {
        auto container = Wt::cpp14::make_unique<Wt::WContainerWidget>();
        container->setHeight(250);
//        container.get()->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thin,WColor("rgb(255,0,0)")));
        container.get()->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container.get()->setAttributeValue("style","background:url(img/hentbol.jpg); background-size:cover;");
        container.get()->addStyleClass("KatergoriTitleItem");
        container.get()->setContentAlignment(AlignmentFlag::Center);
        container.get()->addWidget(cpp14::make_unique<WText>("Hentbol"))->addStyleClass("KatergoriTitle");

        mMainContainer->addWidget(std::move(container));
    }

    {
        auto container = Wt::cpp14::make_unique<Wt::WContainerWidget>();
        container->setHeight(250);
        container.get()->addStyleClass(Bootstrap::Grid::Large::col_lg_6+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container.get()->setAttributeValue("style","background:url(img/voleybol.jpg); background-size:cover;");
        container.get()->addStyleClass("KatergoriTitleItem");
        container.get()->setContentAlignment(AlignmentFlag::Center);
        container.get()->addWidget(cpp14::make_unique<WText>("Voleybol"))->addStyleClass("KatergoriTitle");
        mMainContainer->addWidget(std::move(container));
    }


    {
        auto container = Wt::cpp14::make_unique<Wt::WContainerWidget>();
        container->setHeight(250);
        container.get()->addStyleClass(Bootstrap::Grid::Large::col_lg_6+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container.get()->setAttributeValue("style","background:url(img/diger.jpg); background-size:cover;");
        container.get()->addStyleClass("KatergoriTitleItem");
        container.get()->setContentAlignment(AlignmentFlag::Center);
        container.get()->addWidget(cpp14::make_unique<WText>("Diğer"))->addStyleClass("KatergoriTitle");
        mMainContainer->addWidget(std::move(container));
    }

}
