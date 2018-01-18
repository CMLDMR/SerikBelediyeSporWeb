#include "okullarwidget.h"

Okul::OkullarWidget::OkullarWidget()
    :WContainerWidget()
{

    addStyleClass(Bootstrap::Grid::container_fluid);


    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());

    mMainContainer->addStyleClass(Bootstrap::Grid::row);

    mMainContainer->setMargin(10,Side::Bottom);

    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->addStyleClass("bot-left");
        auto title = container->addWidget(cpp14::make_unique<WText>("OKULLARIMIZ"));
        title->addStyleClass("OkullarimizWidgetTitle");
        container->setContentAlignment(AlignmentFlag::Left);
        setHeight(50);
        container->setMargin(10,AllSides);
    }

    ContentContainer = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    ContentContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
    ContentContainer->setContentAlignment(AlignmentFlag::Center);


    tempContainer = ContentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    tempContainer->addStyleClass(Bootstrap::Grid::container_fluid);

    mContentContainer = tempContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    mContentContainer->addStyleClass(Bootstrap::Grid::row);


    addOkul("Futbol Okulu","img/futbol.jpg");
    addOkul("Basketbol Okulu","img/golf.jpg");
    addOkul("Hentbol Okulu","img/basketbol.jpg");
    addOkul("Santraç Okulu","img/voleybol.jpg");
    addOkul("Golf Okulu","img/golf.jpg");
    addOkul("Okçuluk Okulu","img/basketbol.jpg");
    addOkul("Minikler Takımı","img/diger.jpg");
    addOkul("U18 Eğitim Kampı","img/futbol.jpg");

}

void Okul::OkullarWidget::addOkul(std::string okulName, std::string backimgPath)
{

    {
        auto sCOntainer = mContentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        sCOntainer->setHeight(300);
        sCOntainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        sCOntainer->setPadding(5,AllSides);
        auto container = sCOntainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue("style","background:url("+backimgPath+"); background-size:cover;height:100%;margin-top:5px;");


        auto subcontainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
        subcontainer->addStyleClass("OkullarimizWidgetItem");

        auto layout = subcontainer->setLayout(cpp14::make_unique<WVBoxLayout>());
        auto title = layout->addWidget(cpp14::make_unique<WText>(okulName),0,AlignmentFlag::Middle|AlignmentFlag::Justify);
        title->addStyleClass("OkullarWidgetItemTitle");
    }


}
