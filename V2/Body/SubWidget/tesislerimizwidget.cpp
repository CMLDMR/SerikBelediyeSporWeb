#include "tesislerimizwidget.h"

Tesis::TesislerimizWidget::TesislerimizWidget()
    :WContainerWidget()
{

    addStyleClass(Bootstrap::Grid::container_fluid);
    setContentAlignment(AlignmentFlag::Center);
    auto mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());


    mMainContainer->setMaximumSize(1200,WLength::Auto);
    mMainContainer->addStyleClass(Bootstrap::Grid::row);

    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
        auto text = container->addWidget(cpp14::make_unique<WText>("Tesislerimiz"));
        text->setAttributeValue(Style::style,Style::color::white+
                                Style::font::size::s20px+
                                Style::font::weight::bold
                                );
    }



    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
        container->setAttributeValue(Style::style,Style::background::color::rgba("25,25,25,.5"));
        for( int i = 0 ; i < 5 ; i++ )
        {
            auto _container = container->addWidget(cpp14::make_unique<WContainerWidget>());
            _container->addStyleClass(Bootstrap::Grid::row+"TesislerimizItemWidget");
            _container->setAttributeValue(Style::style,Style::Border::top::border("1px solid white")+
                                          Style::Border::right::border("1px solid white"));

            auto imgContainer = _container->addWidget(cpp14::make_unique<WContainerWidget>());
            imgContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_4);
            imgContainer->setHeight(100);
            imgContainer->setAttributeValue("style","background:url(img/1.jpg); background-size:cover;");
            imgContainer->setAttributeValue(Style::style,Style::background::url("img/1.jpg")+
                                            Style::background::size::cover);


            auto textWidget = _container->addWidget(cpp14::make_unique<WContainerWidget>());
            textWidget->addStyleClass(Bootstrap::Grid::Large::col_lg_8);
            textWidget->setHeight(100);
            auto textLayout = textWidget->setLayout(cpp14::make_unique<WVBoxLayout>());
            auto text = textLayout->addWidget(cpp14::make_unique<WText>("İsmail Oğan Spor Komplexi"),0,AlignmentFlag::Middle);
            text->setAttributeValue("style","color:white;");
        }
    }



//    {
//        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
//        container->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
//        container->setAttributeValue("style","border: 1px solid green;");
//        container->setAttributeValue(Style::style,Style::background::color::rgb("235,235,235")+
//                                     Style::color::white+
//                                     Style::Border::bottom::border("1px solid black"));
//        for( int i = 0 ; i < 5 ; i++ )
//        {
//            auto _container = container->addWidget(cpp14::make_unique<WContainerWidget>());
//            _container->addStyleClass(Bootstrap::Grid::row);
//            _container->setAttributeValue(Style::style,Style::Border::bottom::border("2px solid black")+"vertical-align:middle;");

//            auto text = _container->addWidget(cpp14::make_unique<WText>("Etkinliklerimiz"));
//            text->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
//            text->setAttributeValue(Style::style,Style::color::white);
//        }
//    }



}
