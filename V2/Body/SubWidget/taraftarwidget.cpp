#include "taraftarwidget.h"

Taraftar::TaraftarWidget::TaraftarWidget()
    :WContainerWidget()
{


    addStyleClass(Bootstrap::Grid::container_fluid);
    setContentAlignment(AlignmentFlag::Center);

    this->initWidget();


}

void Taraftar::TaraftarWidget::initWidget()
{

    clear();

    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->setMaximumSize(1200,WLength::Auto);
    mMainContainer->addStyleClass(Bootstrap::Grid::row);

    ContentContainer = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    ContentContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_8+"multbg-top-to-bottom");

    FeautureContainer = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    FeautureContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_4+"multbg-top-to-bottom");


    ContentContainer->addWidget(cpp14::make_unique<WText>("Forum"))->setAttributeValue("style","color:white;font-size:28px;font-weight:bold;");


    this->ListForumItems();

    this->initRightMenu();
}

void Taraftar::TaraftarWidget::ListForumItems()
{
    for( int i = 0 ; i < 8 ; i++ )
    {
        this->addItem("0","5","This header introduces random number generation facilities.","cmldmr");
    }
}

void Taraftar::TaraftarWidget::addItem(std::string trendCount, std::string okunmaCount, std::string itemtitle, std::string username)
{

    auto container = ContentContainer->addWidget(cpp14::make_unique<WContainerWidget>());

    container->addStyleClass(Bootstrap::Grid::row+"TaraftarForumItem");
    container->setHeight(75);
    container->setContentAlignment(AlignmentFlag::Middle);

    {
        auto item = container->addWidget(cpp14::make_unique<WContainerWidget>());
        item->setContentAlignment(AlignmentFlag::Center);
        item->addStyleClass(Bootstrap::Grid::Large::col_lg_1+"TaraftarForumItemWidget");
        auto layout = item->setLayout(cpp14::make_unique<WVBoxLayout>());
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>(trendCount),0,AlignmentFlag::Center);
            title->setMargin(WLength::Auto,AllSides);
        }
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>("Trend"),0,AlignmentFlag::Center);
            title->setMargin(WLength::Auto,AllSides);
        }
    }

    {
        auto item = container->addWidget(cpp14::make_unique<WContainerWidget>());
        item->setContentAlignment(AlignmentFlag::Center);
        item->addStyleClass(Bootstrap::Grid::Large::col_lg_1+"TaraftarForumItemWidget");
        auto layout = item->setLayout(cpp14::make_unique<WVBoxLayout>());
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>(okunmaCount),0,AlignmentFlag::Center);
            title->setMargin(WLength::Auto,AllSides);
        }
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>("Okunma"),0,AlignmentFlag::Center);
            title->setMargin(WLength::Auto,AllSides);
        }
    }

    {
        auto item = container->addWidget(cpp14::make_unique<WContainerWidget>());
        item->setContentAlignment(AlignmentFlag::Left);
        item->addStyleClass(Bootstrap::Grid::Large::col_lg_10+"TaraftarForumItemWidget");
        auto layout = item->setLayout(cpp14::make_unique<WVBoxLayout>());
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>(itemtitle),0,AlignmentFlag::Center);
            title->setMargin(WLength::Auto,AllSides);
        }
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>(username),0,AlignmentFlag::Center);
            title->setMargin(WLength::Auto,AllSides);
        }
    }

}

void Taraftar::TaraftarWidget::initRightMenu()
{
    FeautureContainer->setMargin(0,AllSides);
    FeautureContainer->setPadding(0,AllSides);
    //YENI BASLIK AÇMA
    {
        auto container = FeautureContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::container_fluid);
        container->setContentAlignment(AlignmentFlag::Middle);
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        layout->addStretch(1);
        auto title = layout->addWidget(cpp14::make_unique<WText>("Yeni Konu"),0,AlignmentFlag::Middle);
        title->addStyleClass("RightMenuWidgetTitleNewTopic");
        layout->addStretch(1);
    }


    {
        auto container = FeautureContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::container_fluid+"RightMenuWidgetMostRead");
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());


        auto title = layout->addWidget(cpp14::make_unique<WText>("En Çok Okunanlar"),0,AlignmentFlag::Left);
        title->addStyleClass("RightMenuWidgetMostReadTitle");

        for( int i  = 0 ; i < 5 ; i++ )
        {
            auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
//            _container->setMargin(0,AllSides);
            _container->setPadding(5,AllSides);
            _container->addStyleClass("RightMenuWidgetMostReadItem");
            _container->setHeight(40);
            _container->setAttributeValue("style","border-top:1px solid gray");
            auto _layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());
            auto _title = _layout->addWidget(cpp14::make_unique<WText>("This header introduces random"),0,AlignmentFlag::Left);

        }
    }



}
