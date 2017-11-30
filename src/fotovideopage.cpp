#include "fotovideopage.h"

FotoVideo::FotoVideoPage::FotoVideoPage()
{

}



FotoVideo::FotoVideoWidget::FotoVideoWidget()
{
    addStyleClass(Bootstrap::Grid::container_fluid+Bootstrap::Test::border1px);

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::row);

    container->addWidget(cpp14::make_unique<FotoWidget>())->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                          +Bootstrap::Grid::Medium::col_md_6);
    container->addWidget(cpp14::make_unique<VideoWidget>())->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                           +Bootstrap::Grid::Medium::col_md_6);
}



FotoVideo::FotoVideoWidget::FotoWidget::FotoWidget()
{
    addStyleClass(Bootstrap::Grid::container_fluid+Bootstrap::Test::border1px);
    setContentAlignment(AlignmentFlag::Center);


    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->addWidget(cpp14::make_unique<WText>("Foto Widget"))->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
    }


    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        for( int i = 0 ; i < 6 ; i++ )
        {
            container->addWidget(cpp14::make_unique<item>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4
                                                                            +Bootstrap::Grid::Medium::col_md_6
                                                                            +Bootstrap::Grid::Small::col_sm_6
                                                                            +Bootstrap::Grid::ExtraSmall::col_xs_12);;
        }
    }

}

FotoVideo::FotoVideoWidget::VideoWidget::VideoWidget()
{
    addStyleClass(Bootstrap::Grid::container_fluid+Bootstrap::Test::border1px);
    setContentAlignment(AlignmentFlag::Center);


    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->addWidget(cpp14::make_unique<WText>("Video Widget"))->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
    }


    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        for( int i = 0 ; i < 6 ; i++ )
        {
            container->addWidget(cpp14::make_unique<item>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4
                                                                            +Bootstrap::Grid::Medium::col_md_6
                                                                            +Bootstrap::Grid::Small::col_sm_6
                                                                            +Bootstrap::Grid::ExtraSmall::col_xs_12);;
        }
    }
}

FotoVideo::FotoVideoWidget::FotoWidget::item::item()
{
    addStyleClass(Bootstrap::Test::border1px);
    setMinimumSize(150,150);
    decorationStyle().setBackgroundColor(WColor(qrand()%255,qrand()%255,qrand()%255));

    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->addWidget(cpp14::make_unique<WText>("Foto item Widget"),0,AlignmentFlag::Center|AlignmentFlag::Middle);
}

FotoVideo::FotoVideoWidget::VideoWidget::item::item()
{
    addStyleClass(Bootstrap::Test::border1px);
    setMinimumSize(150,150);
    decorationStyle().setBackgroundColor(WColor(qrand()%255,qrand()%255,qrand()%255));

    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->addWidget(cpp14::make_unique<WText>("Video item Widget"),0,AlignmentFlag::Center|AlignmentFlag::Middle);
}
