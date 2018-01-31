#include "kurumsalwidget.h"

Kurumsal::KurumsalWidget::KurumsalWidget()
    :WContainerWidget()
{
    addStyleClass(Bootstrap::Grid::container_fluid);
    setContentAlignment(AlignmentFlag::Center);


    auto mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->addStyleClass(Bootstrap::Grid::row);
    mMainContainer->setMaximumSize(1200,WLength::Auto);


    {
        auto baskan = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        baskan->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
        auto layout = baskan->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto content = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
        auto vLayout = content->setLayout(cpp14::make_unique<WVBoxLayout>());
        auto ContainerWidget = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        ContainerWidget->setAttributeValue(Style::style,Style::background::url("img/Person.png")+Style::background::size::contain+Style::background::repeat::norepeat+Style::background::position::center_center);
        ContainerWidget->setWidth(150);
        ContainerWidget->setHeight(250);
        auto text = vLayout->addWidget(cpp14::make_unique<WText>("Başkan"));
        text->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
    }

    {
        auto baskan = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        baskan->addStyleClass(Bootstrap::Grid::Large::col_lg_6);
        auto layout = baskan->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto content = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
        auto vLayout = content->setLayout(cpp14::make_unique<WVBoxLayout>());
        auto ContainerWidget = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        ContainerWidget->setAttributeValue(Style::style,Style::background::url("img/Person.png")+Style::background::size::contain+Style::background::repeat::norepeat+Style::background::position::center_center);
        ContainerWidget->setWidth(120);
        ContainerWidget->setHeight(180);
        auto text = vLayout->addWidget(cpp14::make_unique<WText>("Başkan Yardımcısı"));
        text->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
    }

    {
        auto baskan = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        baskan->addStyleClass(Bootstrap::Grid::Large::col_lg_6);
        auto layout = baskan->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto content = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
        auto vLayout = content->setLayout(cpp14::make_unique<WVBoxLayout>());
        auto ContainerWidget = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        ContainerWidget->setAttributeValue(Style::style,Style::background::url("img/Person.png")+Style::background::size::contain+Style::background::repeat::norepeat+Style::background::position::center_center);
        ContainerWidget->setWidth(120);
        ContainerWidget->setHeight(180);
        auto text = vLayout->addWidget(cpp14::make_unique<WText>("Başkan Yardımcısı"));
        text->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
    }



    // 4 Adet Yönetim Kurulu Üyesi
    {
        {
            auto baskan = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            baskan->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            auto layout = baskan->setLayout(cpp14::make_unique<WHBoxLayout>());
            auto content = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            auto vLayout = content->setLayout(cpp14::make_unique<WVBoxLayout>());
            auto ContainerWidget = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
            auto hLayout = ContainerWidget->setLayout(cpp14::make_unique<WHBoxLayout>());
            auto img = hLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            img->setAttributeValue(Style::style,Style::background::url("img/Person.png")+Style::background::size::contain+Style::background::repeat::norepeat+Style::background::position::center_center);
            img->setWidth(80);
            img->setHeight(140);
            auto text = vLayout->addWidget(cpp14::make_unique<WText>("Yönetim Kurulu Üyesi"));
            text->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        }
        {
            auto baskan = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            baskan->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            auto layout = baskan->setLayout(cpp14::make_unique<WHBoxLayout>());
            auto content = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            auto vLayout = content->setLayout(cpp14::make_unique<WVBoxLayout>());
            auto ContainerWidget = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
            auto hLayout = ContainerWidget->setLayout(cpp14::make_unique<WHBoxLayout>());
            auto img = hLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            img->setAttributeValue(Style::style,Style::background::url("img/Person.png")+Style::background::size::contain+Style::background::repeat::norepeat+Style::background::position::center_center);
            img->setWidth(80);
            img->setHeight(140);
            auto text = vLayout->addWidget(cpp14::make_unique<WText>("Yönetim Kurulu Üyesi"));
            text->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        }
        {
            auto baskan = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            baskan->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            auto layout = baskan->setLayout(cpp14::make_unique<WHBoxLayout>());
            auto content = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            auto vLayout = content->setLayout(cpp14::make_unique<WVBoxLayout>());
            auto ContainerWidget = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
            auto hLayout = ContainerWidget->setLayout(cpp14::make_unique<WHBoxLayout>());
            auto img = hLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            img->setAttributeValue(Style::style,Style::background::url("img/Person.png")+Style::background::size::contain+Style::background::repeat::norepeat+Style::background::position::center_center);
            img->setWidth(80);
            img->setHeight(140);
            auto text = vLayout->addWidget(cpp14::make_unique<WText>("Yönetim Kurulu Üyesi"));
            text->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        }
        {
            auto baskan = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            baskan->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            auto layout = baskan->setLayout(cpp14::make_unique<WHBoxLayout>());
            auto content = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            auto vLayout = content->setLayout(cpp14::make_unique<WVBoxLayout>());
            auto ContainerWidget = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
            auto hLayout = ContainerWidget->setLayout(cpp14::make_unique<WHBoxLayout>());
            auto img = hLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            img->setAttributeValue(Style::style,Style::background::url("img/Person.png")+Style::background::size::contain+Style::background::repeat::norepeat+Style::background::position::center_center);
            img->setWidth(80);
            img->setHeight(140);
            auto text = vLayout->addWidget(cpp14::make_unique<WText>("Yönetim Kurulu Üyesi"));
            text->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        }
    }
}
