#include "header.h"

Header::Header::Header()
    :WContainerWidget()
{

    setContentAlignment(AlignmentFlag::Center);
    addStyleClass("header");


    setMargin(0,AllSides);
    setPadding(0,AllSides);


    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->setMaximumSize(1000,WLength::Auto);

        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());


        {
            auto socialContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
            socialContainer->setContentAlignment(AlignmentFlag::Left);
            socialContainer->setMaximumSize(150,WLength::Auto);

            auto face = socialContainer->addWidget(cpp14::make_unique<WImage>(WLink("img/face.png")));
            face->setMaximumSize(40,40);
            face->setMargin(50,Side::Right);
            face->decorationStyle().setCursor(Cursor::PointingHand);

            auto Twitter = socialContainer->addWidget(cpp14::make_unique<WImage>(WLink("img/Twitter.png")));
            Twitter->setMaximumSize(40,40);
            Twitter->decorationStyle().setCursor(Cursor::PointingHand);


        }



        {
            auto toolbarCOntainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
            toolbarCOntainer->setContentAlignment(AlignmentFlag::Right);

            auto toolbar = toolbarCOntainer->addWidget(cpp14::make_unique<WToolBar>());
//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Kupalar");
//                homeBtn->addStyleClass("topBtn");
//                homeBtn->clicked().connect([=](){
//                    mKupalar.emit(NoClass());
//                });
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }
//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Kurumsal");
//                homeBtn->addStyleClass("topBtn");
//                homeBtn->clicked().connect([=](){
//                    mKurumsal.emit(NoClass());
//                });
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }
//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Basın");
//                homeBtn->addStyleClass("topBtn");
//                homeBtn->clicked().connect([=](){
//                    mBasin.emit(NoClass());
//                });
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }
            {
                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Üye Ol");
                homeBtn->addStyleClass("topBtn");
                homeBtn->clicked().connect([=](){
                    mSignUp.emit(NoClass());
                });
                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
            }
            {
                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Giriş");
                homeBtn->addStyleClass("topBtn");
                homeBtn->clicked().connect([=](){
                    mSignin.emit(NoClass());
                });
                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
            }
        }






    }


    {
        mLogoContainer = addWidget(cpp14::make_unique<WContainerWidget>());
        mLogoContainer->setMaximumSize(1000,WLength::Auto);
        mLogoContainer->setContentAlignment(AlignmentFlag::Left);
//        mLogoContainer->setAttributeValue(Style::style,Style::Border::border("1px solid black"));

        mLogoContainerLayout = mLogoContainer->setLayout(cpp14::make_unique<WHBoxLayout>());

        auto logoCont = mLogoContainerLayout->addWidget(cpp14::make_unique<WImage>(WLink("icon/1.png")),0,AlignmentFlag::Left);
        logoCont->setMaximumSize(180,60);
        logoCont->setMinimumSize(180,60);

        mUserIDContainer = mLogoContainerLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Right|AlignmentFlag::Middle);

        auto layout = mUserIDContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

        userad = layout->addWidget(cpp14::make_unique<WText>(("")),0,AlignmentFlag::Center|AlignmentFlag::Middle);
        usertel = layout->addWidget(cpp14::make_unique<WText>(("")),0,AlignmentFlag::Center|AlignmentFlag::Middle);

//        auto text = layout->addWidget(cpp14::make_unique<WText>(("Cemal DEMİR - 0532 677 80 51")),0,AlignmentFlag::Right|AlignmentFlag::Middle);


    }



    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->setMaximumSize(1050,WLength::Auto);

        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());

        {
            auto LeftContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
            LeftContainer->setContentAlignment(AlignmentFlag::Left);
            auto toolbar = LeftContainer->addWidget(cpp14::make_unique<WToolBar>());

            {
                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Ana Sayfa");
                homeBtn->addStyleClass("topBtn topAnaSayfaBtn");
                homeBtn->clicked().connect([=](){
                    mAnaSayfa.emit(NoClass());
                });
                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
            }
            {
                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Kategoriler");
                homeBtn->addStyleClass("topBtn topAnaSayfaBtn");
                homeBtn->clicked().connect([=](){
                    mKategoriSignal.emit(NoClass());
                });
                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
            }
//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Taraftar");
//                homeBtn->addStyleClass("topBtn topAnaSayfaBtn");
//                homeBtn->clicked().connect([=](){
//                    mTaraftarSignal.emit(NoClass());
//                });
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }

            {
                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Okullar");
                homeBtn->addStyleClass("topBtn topAnaSayfaBtn");
                homeBtn->clicked().connect([=](){
                    mOkullarSignal.emit(NoClass());
                });
                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
            }

//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Aktiviteler");
//                homeBtn->addStyleClass("topBtn topAnaSayfaBtn");
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }
        }

        {
            auto RightContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
            RightContainer->setContentAlignment(AlignmentFlag::Right);
            auto toolbar = RightContainer->addWidget(cpp14::make_unique<WToolBar>());
//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Haberler");
//                homeBtn->addStyleClass("topBtn topAnaSayfaHaberBtn");
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }
//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Duyurular");
//                homeBtn->addStyleClass("topBtn topAnaSayfaHaberBtn");
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }

//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Store");
//                homeBtn->addStyleClass("topBtn topAnaSayfaHaberBtn");
//                homeBtn->clicked().connect([=](){
//                    mStoreSignal.emit(NoClass());
//                });
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }

//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Nostalji");
//                homeBtn->addStyleClass("topBtn topAnaSayfaHaberBtn");
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }
//            {
//                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Tesislerimiz");
//                homeBtn->addStyleClass("topBtn topAnaSayfaHaberBtn");
//                homeBtn->clicked().connect([=](){
//                    mTesislerimiz.emit(NoClass());
//                });
//                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
//            }
            {
                std::unique_ptr<WPushButton> homeBtn = std::make_unique<WPushButton>("Hakkımızda");
                homeBtn->addStyleClass("topBtn topAnaSayfaHaberBtn");
                homeBtn->clicked().connect([=](){
                    mHakkimizda.emit(NoClass());
                });
                toolbar->addButton(std::move(homeBtn),AlignmentFlag::Left);
            }
        }

    }




//    navigation = addWidget(Wt::cpp14::make_unique<Wt::WNavigationBar>());
//    navigation->setResponsive(true);
//    navigation->setTitle("Serik BelediyeSpor");
//    navigation->setId("navbarid");
//    this->fLoadMenu();
}

void Header::Header::fLoadMenu()
{

    auto leftMenu = Wt::cpp14::make_unique<Wt::WMenu>();

    auto leftMenu_ = navigation->addMenu(std::move(leftMenu),AlignmentFlag::Center);

    leftMenu_->addItem("Haberler",cpp14::make_unique<WText>("Haberler"));
    leftMenu_->addItem("Fikstur",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem(WString::fromUTF8("Canlı"),cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Store",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem(WString::fromUTF8("Branşlar"),cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem(WString::fromUTF8("Spor Okulları"),cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Aktiviteler",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Taraftar",cpp14::make_unique<WText>("Fikstur"));
    leftMenu_->addItem("Duyuru",cpp14::make_unique<WText>("Fikstur"));

    /// Arşiv Menu
    {
        auto popupPtr = Wt::cpp14::make_unique<Wt::WPopupMenu>();
        auto popup = popupPtr.get();
        popup->addItem("icon/btn-flat.jpg",WString::fromUTF8("Fotoğraflar"));
        popup->addItem("icon/btn-flat.jpg",WString::fromUTF8("Videolar"));

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

        auto item = Wt::cpp14::make_unique<Wt::WMenuItem>(WString::fromUTF8("Arşiv"));
        item->setMenu(std::move(popupPtr));
        leftMenu_->addItem(std::move(item));
    }

    /// Medya Menu
    {
        auto popupPtr = Wt::cpp14::make_unique<Wt::WPopupMenu>();
        auto popup = popupPtr.get();
        popup->addItem("icon/btn-flat.jpg",WString::fromUTF8("Basın"));
        popup->addItem("icon/btn-flat.jpg","Sosyal Medya");
        popup->addItem("icon/btn-flat.jpg",WString::fromUTF8("Yayınlar"));

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
        popup->addItem("icon/btn-flat.jpg",WString::fromUTF8("Hakkımızda"));
        popup->addItem("icon/btn-flat.jpg",WString::fromUTF8("İletişim"));

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

        auto item = Wt::cpp14::make_unique<Wt::WMenuItem>(WString::fromUTF8("Hakkımızda"));
        item->setMenu(std::move(popupPtr));
        leftMenu_->addItem(std::move(item));
    }
}


Signal<NoClass> &Header::Header::mGetAnaSayfa()
{
    return this->mAnaSayfa;
}

Signal<NoClass> &Header::Header::mGetKategoriler()
{
    return this->mKategoriSignal;
}

Signal<NoClass> &Header::Header::mGetTaraftar()
{
    return this->mTaraftarSignal;
}

Signal<NoClass> &Header::Header::mGetOkullar()
{
    return this->mOkullarSignal;
}

Signal<NoClass> &Header::Header::mGetStore()
{
    return this->mStoreSignal;
}

Signal<NoClass> &Header::Header::mGetTesis()
{
    return this->mTesislerimiz;
}

Signal<NoClass> &Header::Header::mGetHakkimizda()
{
    return this->mHakkimizda;
}

Signal<NoClass> &Header::Header::mGetKupalar()
{
    return this->mKupalar;
}

Signal<NoClass> &Header::Header::mGetKurumsal()
{
    return this->mKurumsal;
}

Signal<NoClass> &Header::Header::mGetBasin()
{

    return this->mBasin;

}

Signal<NoClass> &Header::Header::mGetSignUp()
{

    return this->mSignUp;

}

Signal<NoClass> &Header::Header::mGetSignIn()
{
    return this->mSignin;
}

void Header::Header::UserId(DataBaseKeys::Userinfo::User user)
{
//    mUserIDContainer->clear();

//    mUserIDContainer->setId("MUSerID");

    std::cout << "Header User Id: " << user.tel << std::endl;

    userad->setText(user.ad+" "+user.soyad);
    usertel->setText(user.tel);

//    auto layout = mUserIDContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

//    layout->addWidget(cpp14::make_unique<WText>((user.ad+" "+user.soyad)),0,AlignmentFlag::Center|AlignmentFlag::Middle);
//    layout->addWidget(cpp14::make_unique<WText>((user.tel)),0,AlignmentFlag::Center|AlignmentFlag::Middle);

}
