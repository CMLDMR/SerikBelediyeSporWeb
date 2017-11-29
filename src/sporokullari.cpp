#include "sporokullari.h"

Okullar::SporOkullari::SporOkullari()
{

}

Okullar::SporOkullariWidget::SporOkullariWidget()
{
    addStyleClass(Bootstrap::Grid::container);
    setContentAlignment(AlignmentFlag::Center);
    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->setSpacing(0);
    mLayout->setContentsMargins(0,0,0,0);


    {
        mLayout->addWidget(cpp14::make_unique<WText>("Spor Okulları"),0,AlignmentFlag::Center|AlignmentFlag::Middle)->addStyleClass("sporokullari");

        auto container = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row+Bootstrap::Test::border1px);
        for( int i = 0 ; i < 8 ; i++ )
        {
            container->addWidget(cpp14::make_unique<item>())->addStyleClass(Bootstrap::Grid::Large::col_lg_3
                                                                            +Bootstrap::Grid::Medium::col_md_3
                                                                            +Bootstrap::Grid::Small::col_sm_6
                                                                            +Bootstrap::Grid::ExtraSmall::col_xs_12+"okulitemBlock");
        }
    }

}

Okullar::SporOkullariWidget::item::item(std::string okuladi)
{
    addStyleClass(Bootstrap::Grid::container_fluid+Bootstrap::Test::border1px);

    setMinimumSize(150,150);

    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());

    mLayout->addWidget(cpp14::make_unique<WText>(okuladi),0,AlignmentFlag::Center|AlignmentFlag::Middle);

    decorationStyle().setBackgroundColor(WColor(qrand()%255,qrand()%255,qrand()%255));
}

Okullar::AktiviteWidget::AktiviteWidget()
{

    addStyleClass(Bootstrap::Grid::container);
    setContentAlignment(AlignmentFlag::Center);
    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->setSpacing(0);
    mLayout->setContentsMargins(0,0,0,0);


    {
        mLayout->addWidget(cpp14::make_unique<WText>("Aktiviteler"),0,AlignmentFlag::Center|AlignmentFlag::Middle)->addStyleClass("sporokullari");

        auto container = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row+Bootstrap::Test::border1px);
        for( int i = 0 ; i < 8 ; i++ )
        {
            container->addWidget(cpp14::make_unique<item>())->addStyleClass(Bootstrap::Grid::Large::col_lg_3
                                                                            +Bootstrap::Grid::Medium::col_md_3
                                                                            +Bootstrap::Grid::Small::col_sm_6
                                                                            +Bootstrap::Grid::ExtraSmall::col_xs_12+"okulitemBlock");
        }
    }

}

Okullar::AktiviteWidget::item::item(std::string okuladi)
{
    addStyleClass(Bootstrap::Grid::container_fluid+Bootstrap::Test::border1px);

    setMinimumSize(150,150);

    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());

    mLayout->addWidget(cpp14::make_unique<WText>(okuladi),0,AlignmentFlag::Center|AlignmentFlag::Middle);

    decorationStyle().setBackgroundColor(WColor(qrand()%255,qrand()%255,qrand()%255));
}
