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
                                                                               +Bootstrap::Grid::Medium::col_md_4
                                                                               +Bootstrap::Grid::Small::col_sm_12
                                                                               +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->addWidget(cpp14::make_unique<SocialWidget>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4
                                                                               +Bootstrap::Grid::Medium::col_md_4
                                                                               +Bootstrap::Grid::Small::col_sm_12
                                                                               +Bootstrap::Grid::ExtraSmall::col_xs_12);


        container->addWidget(cpp14::make_unique<YayinlarWidget>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4
                                                                               +Bootstrap::Grid::Medium::col_md_4
                                                                               +Bootstrap::Grid::Small::col_sm_12
                                                                               +Bootstrap::Grid::ExtraSmall::col_xs_12);

    }

}

Medya::MedyaWidget::BasinWidget::BasinWidget()
{
    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Grid::container_fluid);

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

    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Grid::container_fluid);

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->addWidget(cpp14::make_unique<WText>("Sosyal Ağ..."));
    }


    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);

        container->addWidget(cpp14::make_unique<faceitem>())->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                            +Bootstrap::Grid::Medium::col_md_6
                                                                            +Bootstrap::Grid::Small::col_sm_6
                                                                            +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->addWidget(cpp14::make_unique<tweeteritem>())->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                            +Bootstrap::Grid::Medium::col_md_6
                                                                            +Bootstrap::Grid::Small::col_sm_6
                                                                            +Bootstrap::Grid::ExtraSmall::col_xs_12);
    }


}

Medya::MedyaWidget::YayinlarWidget::YayinlarWidget()
{
    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Grid::container_fluid);

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->addWidget(cpp14::make_unique<WText>("Yayınlar..."));
    }


    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->setContentAlignment(AlignmentFlag::Center);


        container->addWidget(cpp14::make_unique<item>("img/dergi/1.jpg"))->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                        +Bootstrap::Grid::Medium::col_md_12
                                                                        +Bootstrap::Grid::Small::col_sm_12
                                                                        +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->addWidget(cpp14::make_unique<item>("img/dergi/2.jpg"))->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                        +Bootstrap::Grid::Medium::col_md_12
                                                                        +Bootstrap::Grid::Small::col_sm_12
                                                                        +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->addWidget(cpp14::make_unique<item>("img/dergi/3.jpg"))->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                        +Bootstrap::Grid::Medium::col_md_12
                                                                        +Bootstrap::Grid::Small::col_sm_12
                                                                        +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->addWidget(cpp14::make_unique<item>("img/dergi/4.jpg"))->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                        +Bootstrap::Grid::Medium::col_md_12
                                                                        +Bootstrap::Grid::Small::col_sm_12
                                                                        +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->addWidget(cpp14::make_unique<item>("img/dergi/5.jpg"))->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                        +Bootstrap::Grid::Medium::col_md_12
                                                                        +Bootstrap::Grid::Small::col_sm_12
                                                                        +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->addWidget(cpp14::make_unique<item>("img/dergi/6.jpg"))->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                                                        +Bootstrap::Grid::Medium::col_md_12
                                                                        +Bootstrap::Grid::Small::col_sm_12
                                                                        +Bootstrap::Grid::ExtraSmall::col_xs_12);

    }
}

Medya::MedyaWidget::BasinWidget::item::item()
{
    setMinimumSize(150,150);
    decorationStyle().setBackgroundColor(WColor(qrand()%255,qrand()%255,qrand()%255));
    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->addWidget(cpp14::make_unique<WText>("Basın Haberi"),0,AlignmentFlag::Center|AlignmentFlag::Middle);
}

Medya::MedyaWidget::SocialWidget::faceitem::faceitem()
{
    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/socialtest/face.jpg")));
}

Medya::MedyaWidget::SocialWidget::tweeteritem::tweeteritem()
{
    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->addWidget(cpp14::make_unique<WImage>(WLink("img/socialtest/tweeter.jpg")));
}

Medya::MedyaWidget::YayinlarWidget::item::item(std::string path)
{

    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Grid::container_fluid);
    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::row);
    auto img = container->addWidget(cpp14::make_unique<WImage>(WLink(path)));
    img->addStyleClass(Bootstrap::Grid::Large::col_lg_8);
    img->setMaximumSize(250,150);

    auto text = container->addWidget(cpp14::make_unique<WText>("Kasım Yayımınz"));
    text->addStyleClass(Bootstrap::Grid::Large::col_lg_4);

}
