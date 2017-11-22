#include "frontpagewidget.h"
#include "ToolKit/bootstrap.h"


FrontPageWidget::FrontPageWidget()
{

    setContentAlignment(AlignmentFlag::Center);
//    setMargin(WLength::Auto,Side::Left|Side::Right);
    addStyleClass(Bootstrap::Grid::container_fluid + "frontpagewidget" );


    {

        auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
        mainContainer->setMaximumSize(1280,WLength::Auto);
        mainContainer->addStyleClass("row");

        mainContainer->addWidget(cpp14::make_unique<WImage>(WLink("img/serikbelediyesporlogo.png")))->addStyleClass("col-sm-2");

        auto middleContainer = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        middleContainer->addStyleClass("col-sm-8 align-items-center");
        middleContainer->setContentAlignment(AlignmentFlag::Center|AlignmentFlag::Middle);

        middleContainer->addWidget(cpp14::make_unique<WText>("Fatih Terim: ''Seyretmedim, görmedim ama gördüğüm kadarıyla söylüyorum gol değildi''"))
                ->addStyleClass("textcolorwhite");

        middleContainer->addWidget(cpp14::make_unique<WText>("SERİK BELEDİYE SPOR"))
                ->addStyleClass("serikbelediyesporTitle");

        middleContainer->addWidget(cpp14::make_unique<WText>("Resmi Web Sayfası"))
                ->addStyleClass("textcolorwhite");

        mainContainer->addWidget(cpp14::make_unique<WImage>(WLink("img/baskan.png")))->addStyleClass("col-sm-2");

    }




    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass("row justify-content-md-center");
        navigation = container->addWidget(Wt::cpp14::make_unique<Wt::WNavigationBar>());
        navigation->addStyleClass("col-sm-12 justify-content-md-center");
        navigation->setResponsive(true);
        this->fLoadMenu();
    }



}

void FrontPageWidget::fLoadMenu()
{

    auto leftMenu = Wt::cpp14::make_unique<Wt::WMenu>();

    auto leftMenu_ = navigation->addMenu(std::move(leftMenu),AlignmentFlag::Center);

    leftMenu_->addItem("Haberler",cpp14::make_unique<WText>("Haberler"));
    leftMenu_->addItem("Fikstur",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Canlı",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Store",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Branşlar",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Spor Okulları",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Aktiviteler",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Taraftar",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Duyuru",cpp14::make_unique<WText>("Fikstur"));

    /// Arşiv Menu
    {
        auto popupPtr = Wt::cpp14::make_unique<Wt::WPopupMenu>();
        auto popup = popupPtr.get();
        popup->addItem("icon/btn-flat.jpg","Fotoğraflar");
        popup->addItem("icon/btn-flat.jpg","Videolar");

        popup->itemSelected().connect([=] (Wt::WMenuItem *item) {
            auto messageBox = popup->addChild(
                    Wt::cpp14::make_unique<Wt::WMessageBox>
                    ("Arşiv",
                     Wt::WString("<p>İçerik Gösterme: {1}</p>").arg(item->text()),
                     Wt::Icon::Information, Wt::StandardButton::Ok));

            messageBox->buttonClicked().connect([=] {
                popup->removeChild(messageBox);
            });

            messageBox->show();
        });

        auto item = Wt::cpp14::make_unique<Wt::WMenuItem>("Arşiv");
        item->setMenu(std::move(popupPtr));
        leftMenu_->addItem(std::move(item));
    }

    /// Medya Menu
    {
        auto popupPtr = Wt::cpp14::make_unique<Wt::WPopupMenu>();
        auto popup = popupPtr.get();
        popup->addItem("icon/btn-flat.jpg","Basın");
        popup->addItem("icon/btn-flat.jpg","Sosyal Medya");
        popup->addItem("icon/btn-flat.jpg","Yayınlar");

        popup->itemSelected().connect([=] (Wt::WMenuItem *item) {
            auto messageBox = popup->addChild(
                    Wt::cpp14::make_unique<Wt::WMessageBox>
                    ("Arşiv",
                     Wt::WString("<p>İçerik Gösterme: {1}</p>").arg(item->text()),
                     Wt::Icon::Information, Wt::StandardButton::Ok));

            messageBox->buttonClicked().connect([=] {
                popup->removeChild(messageBox);
            });

            messageBox->show();
        });

        auto item = Wt::cpp14::make_unique<Wt::WMenuItem>("Medya");
        item->setMenu(std::move(popupPtr));
        leftMenu_->addItem(std::move(item));
    }


    /// Hakkımız Menu
    {
        auto popupPtr = Wt::cpp14::make_unique<Wt::WPopupMenu>();
        auto popup = popupPtr.get();
        popup->addItem("icon/btn-flat.jpg","Nostalji");
        popup->addItem("icon/btn-flat.jpg","Tesislerimiz");
        popup->addItem("icon/btn-flat.jpg","Hakkımızda");
        popup->addItem("icon/btn-flat.jpg","İletişim");

        popup->itemSelected().connect([=] (Wt::WMenuItem *item) {
            auto messageBox = popup->addChild(
                    Wt::cpp14::make_unique<Wt::WMessageBox>
                    ("Arşiv",
                     Wt::WString("<p>İçerik Gösterme: {1}</p>").arg(item->text()),
                     Wt::Icon::Information, Wt::StandardButton::Ok));

            messageBox->buttonClicked().connect([=] {
                popup->removeChild(messageBox);
            });

            messageBox->show();
        });

        auto item = Wt::cpp14::make_unique<Wt::WMenuItem>("Hakkımızda");
        item->setMenu(std::move(popupPtr));
        leftMenu_->addItem(std::move(item));
    }




}
