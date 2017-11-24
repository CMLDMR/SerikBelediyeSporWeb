#include "storepage.h"
#include "ToolKit/bootstrap.h"

StorePage::StorePage()
{
    addStyleClass(Bootstrap::Grid::container_fluid+Bootstrap::Typography::text_center+" storepage");

    addWidget(cpp14::make_unique<WText>("Store"))->addStyleClass("store");


    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::row);
//    mainContainer->setMargin(WLength::Auto,Side::Left|Side::Right);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    {
        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setContentAlignment(AlignmentFlag::Center);
        container->setMargin(WLength::Auto,Side::Left|Side::Right);
        container->addStyleClass(Bootstrap::Grid::row);
        container->addWidget(cpp14::make_unique<Urun>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->addWidget(cpp14::make_unique<Urun>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->addWidget(cpp14::make_unique<Urun>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->addWidget(cpp14::make_unique<Urun>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->addWidget(cpp14::make_unique<Urun>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->addWidget(cpp14::make_unique<Urun>())->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
    }

}

Urun::Urun()
{

    setMargin(WLength::Auto,Side::Left|Side::Right);
    setContentAlignment(AlignmentFlag::Center);

    addStyleClass("product");

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
//    container->setMaximumSize(170,WLength::Auto);
    container->addStyleClass(Bootstrap::Test::Shadow::boxshadow2p2p4pGray);

    WVBoxLayout* layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());

    layout->addWidget(cpp14::make_unique<WText>("Ürün Adı"),0,AlignmentFlag::Center)->addStyleClass("text-color-gray");

    layout->addWidget(cpp14::make_unique<WImage>(WLink("urun/product.png")),0,AlignmentFlag::Center)->addStyleClass("productimg");

    layout->addWidget(cpp14::make_unique<WText>("25 TL"),0,AlignmentFlag::Center)->addStyleClass("text-color-gray");




}
