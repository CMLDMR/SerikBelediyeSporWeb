#include "storewidget.h"

Store::StoreWidget::StoreWidget()
    :WContainerWidget()
{

    addStyleClass(Bootstrap::Grid::container_fluid);

    setContentAlignment(AlignmentFlag::Center);
    addWidget(cpp14::make_unique<WText>("Store"))->setAttributeValue("style","font-size:28px;color:white;font-weight:bold;");

    auto mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());

    mMainContainer->setMaximumSize(1200,WLength::Auto);


    mMainContainer->addStyleClass(Bootstrap::Grid::row);



    for( int i = 0 ; i < 4 ; i++ )
    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_3+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->setHeight(300);

        auto _container = container->addWidget(cpp14::make_unique<WContainerWidget>());
        _container->setAttributeValue("style","height:100%;background:url(img/tsort.jpg);background-size:100% 100%;");
        _container->setMargin(10,AllSides);
        auto layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());
        layout->addStretch(1);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(cpp14::make_unique<WText>("Ürün"),0,AlignmentFlag::Bottom)->setAttributeValue("style","vertical-align:middle;background:rgba(252,252,252,.9);color:black;min-height:30px;margin:0px 0px 0px 0px;");
        layout->addWidget(cpp14::make_unique<WText>("Tişört"),0,AlignmentFlag::Bottom)->setAttributeValue("style","background:rgba(25,25,25,.9);color:white;min-height:30px;margin:0px 0px 0px 0px;");
    }

    setMargin(25,Side::Bottom);


}
