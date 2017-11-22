#include "fikturpage.h"

FikturPage::FikturPage()
{


    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    mainContainer->addWidget(cpp14::make_unique<WText>("Fikstur"))->addStyleClass("Haberler");


    auto container = mainContainer->addWidget(Wt::cpp14::make_unique<Wt::WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::row);
    container->setContentAlignment(AlignmentFlag::Center);

    // Create a stack where the contents will be located.
    auto contents = Wt::cpp14::make_unique<Wt::WStackedWidget>();
//    contents.get()->addStyleClass(Bootstrap::Test::border1px);


    Wt::WMenu *menu =
        container->addWidget(Wt::cpp14::make_unique<Wt::WMenu>( contents.get()));
    menu->setStyleClass("nav nav-pills nav-stacked");
    menu->setWidth(150);

    menu->setVerticalAlignment(AlignmentFlag::Justify,WLength::Auto);



    // Add menu items using the default lazy loading policy.
    menu->addItem("Puan Durumu", Wt::cpp14::make_unique<Wt::WTextArea>("Puan Durumu"));
    menu->addItem("Geçmiş Maçlar", Wt::cpp14::make_unique<Wt::WTextArea>("Gelecek Maçlar"));
    menu->addItem("Gelecek Maçlar", Wt::cpp14::make_unique<Wt::WTextArea>("Geçmiş Maçlar"));

//    menu->addStyleClass(Bootstrap::Test::border1px);



    menu->addStyleClass(Bootstrap::Grid::Medium::col_md_3);
    contents.get()->addStyleClass(Bootstrap::Grid::Medium::col_md_9);

    container->addWidget(std::move(contents));







}
