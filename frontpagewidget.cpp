#include "frontpagewidget.h"

FrontPageWidget::FrontPageWidget()
{


    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());

    /// for Large Desktop Screen
    {
        auto mainContainer = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        mainContainer->addStyleClass("borderl");
        mainContainer->setPadding(0,AllSides);
        mainContainer->setMargin(0,AllSides);
        auto subLayout = mainContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
//        subLayout->addStretch(1);
        /// Serik Belediye Spor Logosu
        {
            auto container = subLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Left);
            container->addStyleClass("frontpagelogo borderl");
        }

        /// Başkanımızın Sloganı
        {
            auto container = subLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);
            container->addStyleClass("frontpageTitle borderl");
            auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
            layout->addWidget(cpp14::make_unique<WText>("Fatih Terim: ''Seyretmedim, görmedim ama gördüğüm kadarıyla söylüyorum gol değildi''"),0,AlignmentFlag::Center|AlignmentFlag::Middle)->addStyleClass("borderl");
            layout->addWidget(cpp14::make_unique<WText>("Serik BelediyeSpor"),0,AlignmentFlag::Center)->addStyleClass("serikbelediyesporTitle borderl");
            layout->addWidget(cpp14::make_unique<WText>("Resmi Web Sayfası"),0,AlignmentFlag::Center)->addStyleClass("borderl");

        }

        /// Başkanımızın Resmi
        {
            auto container = subLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Right);
            container->addStyleClass("frontpagebaskan borderl");
        }

//        subLayout->addStretch(1);
    }


    navigation = mLayout->addWidget(Wt::cpp14::make_unique<Wt::WNavigationBar>());

    navigation->setTitle("Ana Sayfa","");
    navigation->setResponsive(true);
    setMaximumSize(1280,WLength::Auto);
    setContentAlignment(AlignmentFlag::Center);

    addStyleClass("frontpagewidget");

    this->fLoadMenu();

}

void FrontPageWidget::fLoadMenu()
{

    auto leftMenu = Wt::cpp14::make_unique<Wt::WMenu>();

    auto leftMenu_ = navigation->addMenu(std::move(leftMenu),AlignmentFlag::Left);

    leftMenu_->addItem("Haberler",cpp14::make_unique<WText>("Haberler"));
    leftMenu_->addItem("Fotoğraflar",cpp14::make_unique<WText>("Fotoğraflar"));
    leftMenu_->addItem("Videolar",cpp14::make_unique<WText>("Videolar"));
    leftMenu_->addItem("Fikstur",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Nostalji",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Canlı",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Store",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Hakkımızda",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Branşlar",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Spor Okulları",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Aktiviteler",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Tesislerimiz",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("İletişim",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Taraftar",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Basın",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Sosyal Medya",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Duyuru",cpp14::make_unique<WText>("Fikstur"));

//    auto scopeItem = leftMenu_->addItem("icon/btn-flat.jpg","SCOPE", this,&Body::f_Scope);

//    auto objItem = leftMenu_->addItem("icon/btn-flat.jpg","OBJECTIVE", this,&Body::f_objective);

//    auto rightMenu = Wt::cpp14::make_unique<Wt::WMenu>();

//    auto rightMenu_ = navigation->addMenu(std::move(rightMenu),AlignmentFlag::Right);

//    auto aboutItem = rightMenu_->addItem("icon/btn-flat.jpg","ABOUT", this,&Body::f_About);


}
