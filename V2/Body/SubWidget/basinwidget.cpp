#include "basinwidget.h"

Basin::BasinWidget::BasinWidget()
{

    addStyleClass(Bootstrap::Grid::container_fluid);
    setContentAlignment(AlignmentFlag::Center);
    auto mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());


    mMainContainer->setMaximumSize(1200,WLength::Auto);
    mMainContainer->addStyleClass(Bootstrap::Grid::row);

    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
        auto text = container->addWidget(cpp14::make_unique<WText>("Yayınlarımız"));
        text->setAttributeValue(Style::style,Style::color::white+
                                Style::font::size::s24px+
                                Style::font::weight::bold
                                );

        container->setMargin(35,Side::Top);
        container->setMargin(70,Side::Bottom);
    }



    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
        container->setAttributeValue(Style::style,Style::background::color::rgba("85,65,25,.4"));




        for( int i = 0 ; i < 12 ; i++ )
        {
            auto gridContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
            gridContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_2);

            auto m_Container = gridContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            m_Container->addStyleClass(Bootstrap::Grid::container_fluid);

            auto _container = m_Container->addWidget(cpp14::make_unique<WContainerWidget>());
            _container->addStyleClass(Bootstrap::Grid::row+"KupalarimizItemWidget");


            auto imgContainer = _container->addWidget(cpp14::make_unique<WContainerWidget>());
            imgContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
            imgContainer->setHeight(200);
            imgContainer->setAttributeValue("style","background:url(img/1.jpg); background-size:cover;");
            imgContainer->setAttributeValue(Style::style,Style::background::url("img/dergi/2.jpg")+
                                            Style::background::size::cover);


            auto textWidget = _container->addWidget(cpp14::make_unique<WContainerWidget>());
            textWidget->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
            textWidget->setHeight(100);
            auto textLayout = textWidget->setLayout(cpp14::make_unique<WVBoxLayout>());
            {
                auto text = textLayout->addWidget(cpp14::make_unique<WText>("Full Extra"),0,AlignmentFlag::Middle);
                text->setAttributeValue("style","color:white;");
            }
            {
                auto text = textLayout->addWidget(cpp14::make_unique<WText>(WString("20{1}").arg(i+14)),0,AlignmentFlag::Middle);
                text->setAttributeValue("style","color:white;");
            }
        }
    }

}
