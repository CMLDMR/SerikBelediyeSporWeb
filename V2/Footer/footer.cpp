#include "footer.h"

Footer::Footer::Footer()
    :WContainerWidget()
{

    addStyleClass(Bootstrap::Grid::container_fluid);

    addStyleClass("footerWidget");

    mMainContainerWidget = addWidget(cpp14::make_unique<WContainerWidget>());

    mMainContainerWidget->addStyleClass(Bootstrap::Grid::row);
    mMainContainerWidget->setContentAlignment(AlignmentFlag::Center);

    {
        auto container = mMainContainerWidget->addWidget(cpp14::make_unique<WContainerWidget>());
        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);

        layout->addStretch(1);
        layout->addWidget(cpp14::make_unique<WText>("Serik Belediyesi Spor İşleri Müdürlüğü"));
        layout->addStretch(1);

    }


    {
        auto container = mMainContainerWidget->addWidget(cpp14::make_unique<WContainerWidget>());
        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
        auto text = layout->addWidget(cpp14::make_unique<WText>("Bu Web Sayfası Serik Belediyesi Bilgi İşlem Müdürlüğü Tarafından Açık Kaynak Kodlu Olarak Geliştirilmektedir."));
        text->addStyleClass("footerText");
    }

    {
        auto container = mMainContainerWidget->addWidget(cpp14::make_unique<WContainerWidget>());
        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);

        layout->addStretch(1);
        layout->addWidget(cpp14::make_unique<WText>("© Copyright 2018  "));
        {
            Wt::WLink link = Wt::WLink("http://www.webtoolkit.eu/");
            link.setTarget(Wt::LinkTarget::NewWindow);

            std::unique_ptr<Wt::WAnchor> anchor =
                    Wt::cpp14::make_unique<Wt::WAnchor>(link,"Wt");

            layout->addWidget(std::move(anchor));
        }
        layout->addWidget(cpp14::make_unique<WText>(", "));
        {
            Wt::WLink link = Wt::WLink("http://www.qt.io/");
            link.setTarget(Wt::LinkTarget::NewWindow);

            std::unique_ptr<Wt::WAnchor> anchor =
                    Wt::cpp14::make_unique<Wt::WAnchor>(link,"Qt");

            layout->addWidget(std::move(anchor));
        }
        layout->addWidget(cpp14::make_unique<WText>(" & "));
        {
            Wt::WLink link = Wt::WLink("https://github.com/CMLDMR/SerikBelediyeSporWeb");
            link.setTarget(Wt::LinkTarget::NewWindow);

            std::unique_ptr<Wt::WAnchor> anchor =
                    Wt::cpp14::make_unique<Wt::WAnchor>(link,"gitHub");

            layout->addWidget(std::move(anchor));
        }
        layout->addStretch(1);

    }



}
