#include "basinpage.h"





Medya::MedyaPage::MedyaPage()
{

}



Medya::MedyaWidget::MedyaWidget()
{
    addStyleClass(Bootstrap::Grid::container_fluid);

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addWidget(cpp14::make_unique<WText>("Medya"))->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
    }

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->setContentAlignment(AlignmentFlag::Center);

        container->addWidget(cpp14::make_unique<BasinWidget>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4
                                                                               +Bootstrap::Grid::Medium::col_md_6
                                                                               +Bootstrap::Grid::Small::col_sm_12
                                                                               +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->addWidget(cpp14::make_unique<SocialWidget>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4
                                                                               +Bootstrap::Grid::Medium::col_md_6
                                                                               +Bootstrap::Grid::Small::col_sm_12
                                                                               +Bootstrap::Grid::ExtraSmall::col_xs_12);


        container->addWidget(cpp14::make_unique<YayinlarWidget>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4
                                                                               +Bootstrap::Grid::Medium::col_md_6
                                                                               +Bootstrap::Grid::Small::col_sm_12
                                                                               +Bootstrap::Grid::ExtraSmall::col_xs_12);

    }

}

Medya::MedyaWidget::BasinWidget::BasinWidget()
{
    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Grid::container_fluid+Bootstrap::Test::border1px);

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->addWidget(cpp14::make_unique<WText>("Basın da..."));
    }


    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);

        for( int i = 0 ; i < 6 ; i++ )
        {
            container->addWidget(cpp14::make_unique<item>())->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                            +Bootstrap::Grid::Medium::col_md_6
                                                                            +Bootstrap::Grid::Small::col_sm_4
                                                                            +Bootstrap::Grid::ExtraSmall::col_xs_12);
        }
    }


}

Medya::MedyaWidget::SocialWidget::SocialWidget()
{
    addWidget(cpp14::make_unique<WText>("Sosyal Ağ..."));
    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Test::border1px);
}

Medya::MedyaWidget::YayinlarWidget::YayinlarWidget()
{
    addWidget(cpp14::make_unique<WText>("Yayınlar..."));
    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Test::border1px);
}

Medya::MedyaWidget::BasinWidget::item::item()
{

    setMinimumSize(150,150);
    decorationStyle().setBackgroundColor(WColor(qrand()%255,qrand()%255,qrand()%255));
    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->addWidget(cpp14::make_unique<WText>("Basın Haberi"),0,AlignmentFlag::Center|AlignmentFlag::Middle);
}
