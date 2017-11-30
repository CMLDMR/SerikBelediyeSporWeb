#include "taraftarpage.h"



Taraftar::TaraftarPage::TaraftarPage()
{

}

Taraftar::TaraftarWidget::TaraftarWidget()
{

//    addWidget(cpp14::make_unique<WText>("Sizden Gelenler..."));
    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::container_fluid);

    {
        auto row = container->addWidget(cpp14::make_unique<WContainerWidget>());
        row->setContentAlignment(AlignmentFlag::Center);
        row->addStyleClass(Bootstrap::Grid::row);
        row->addWidget(cpp14::make_unique<WText>("Taraftar"))->addStyleClass(Bootstrap::Grid::Large::col_lg_1+"Haberler");
    }

    {
        auto row = container->addWidget(cpp14::make_unique<WContainerWidget>());
        row->setContentAlignment(AlignmentFlag::Center);
        auto layout = row->setLayout(cpp14::make_unique<WHBoxLayout>());

        layout->addWidget(cpp14::make_unique<WText>("Kategori Seç"),0,AlignmentFlag::Middle)->addStyleClass(Bootstrap::Grid::Large::col_lg_2);
        auto com = layout->addWidget(cpp14::make_unique<WComboBox>(),0,AlignmentFlag::Middle);
        com->addStyleClass(Bootstrap::Grid::Large::col_lg_1);
        com->addItem("Futbol");
        com->addItem("Basketbol");
        com->addItem("Hentbol");

        layout->addWidget(cpp14::make_unique<WText>("Yeni Konu"),0,AlignmentFlag::Middle)->addStyleClass(Bootstrap::Grid::Large::col_lg_1+"ForumYeniKonu");
    }

    for( int i = 0 ; i < 5 ; i++ )
    {
        auto row = container->addWidget(cpp14::make_unique<WContainerWidget>());
        row->addStyleClass(Bootstrap::Grid::row);
        row->setContentAlignment(AlignmentFlag::Center);
        row->addWidget(cpp14::make_unique<Event>());
    }

}

Taraftar::FaceBookWidget::FaceBookWidget()
{

//    addWidget(cpp14::make_unique<WText>("FaceBook Widget"));


    auto face = addWidget(cpp14::make_unique<WText>( ));

    QString str = "<iframe src=\"https://www.facebook.com/plugins/page.php?href=https%3A%2F%2Fwww.facebook.com%2Fser"
                  "ikbelediye%2F&tabs=timeline&width=350&height=600&small_header=false&adapt_container_width=true&hide_co"
                  "ver=false&show_facepile=true&appId\"; width=\"350\" height=\"600\" style=\"border:none;overflow:hidden\" scroll"
                                                              "ing=\"no\" frameborder=\"0\" allowTransparency=\"true\"></iframe>";
    face->setText(str.toStdString().c_str());
    face->setTextFormat(TextFormat::UnsafeXHTML);
    face->addStyleClass(Bootstrap::Test::Shadow::boxshadow2p2p4pGray);

}

Taraftar::DuyurularWidget::DuyurularWidget()
{
//    addWidget(cpp14::make_unique<WText>("Duyuru Widget"));
//    addStyleClass(Bootstrap::Test::border1px);

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::container_fluid);


    {
        auto row = container->addWidget(cpp14::make_unique<WContainerWidget>());
        row->setContentAlignment(AlignmentFlag::Center);
        row->addStyleClass(Bootstrap::Grid::row);
        row->addWidget(cpp14::make_unique<WText>("Duyurular"))->addStyleClass("Haberler");
    }


    for( int i = 0 ; i < 6 ; i++ )
    {
        auto row = container->addWidget(cpp14::make_unique<WContainerWidget>());
        row->setContentAlignment(AlignmentFlag::Center);
        row->addStyleClass(Bootstrap::Grid::row);
        row->addWidget(cpp14::make_unique<item>());
//        row->setMaximumSize(550,120);
    }
}

Taraftar::TaraftarWidget::Event::Event()
{

    addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
    addStyleClass(Bootstrap::Test::Shadow::boxshadow2p2p4pGray+"ForumTitleWidget ");
//    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());

//    mLayout->setContentsMargins(0,0,0,0);
    setMargin(0,AllSides);
    setPadding(0,AllSides);



//    auto mainContainer = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
//    auto mSubLayout = mainContainer->setLayout(cpp14::make_unique<WHBoxLayout>());


    /// Trend
    /// Doğrulama
    /// Okunma
//    {
//        auto Container = mLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify);
//        Container->addStyleClass(Bootstrap::Grid::container_fluid+Bootstrap::Test::border1px);
//        auto layout = Container->setLayout(cpp14::make_unique<WVBoxLayout>());
//        layout->setSpacing(0);



//        layout->addWidget(cpp14::make_unique<WImage>(WLink("img/up.png")),0,AlignmentFlag::Center)->setMaximumSize(32,32);

//        auto mContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);

//            {
//                std::random_device rd;
//                std::mt19937 mt(rd());
//                std::uniform_real_distribution<double> dist(-100, 100);
//                int random = (dist(mt));
//                if( random <= 0 )
//                {
//                    mContainer->addWidget(cpp14::make_unique<WText>(QString("%1").arg(random).toStdString().c_str()));

//                    mContainer->addStyleClass("RateTextDown");
//                }else
//                {
//                    mContainer->addWidget(cpp14::make_unique<WText>(QString("+%1").arg(random).toStdString().c_str()));

//                    mContainer->addStyleClass("RateTextUp");
//                }

//                {
//                    std::random_device rd;
//                    std::mt19937 mt(rd());
//                    std::uniform_real_distribution<double> dist(0, 100);
//                    int random = (dist(mt));
//                    QString str = QString("%1").arg((int)dist(mt)+random+100);
//                    layout->addWidget(cpp14::make_unique<WText>(str.toStdString().c_str()),0,AlignmentFlag::Center);
//                }

//            }
//        layout->addWidget(cpp14::make_unique<WImage>(WLink("img/down.png")),0,AlignmentFlag::Center)->setMaximumSize(32,32);

//    }



    /// ust Header Bilgileri
    /// Tarih Yorum Sayısı
    /// Trend
    /// Oylama
    {

        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::container_fluid);
        container->setMargin(0,AllSides);
        container->setPadding(0,AllSides);
        auto vLayout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        vLayout->setContentsMargins(0,0,0,0);


        {
            auto lcontainer = vLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Right|AlignmentFlag::Left);
            lcontainer->addStyleClass(Bootstrap::Grid::container_fluid);
            lcontainer->setMargin(0,AllSides);
            lcontainer->setPadding(0,AllSides);

            auto layout = lcontainer->setLayout(cpp14::make_unique<WHBoxLayout>());
            layout->setContentsMargins(0,0,0,0);

            auto tarih = layout->addWidget(cpp14::make_unique<WText>("24/10/2017"),0,AlignmentFlag::Left|AlignmentFlag::Middle);


            {
                auto Container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify);
                Container->addStyleClass(Bootstrap::Grid::container_fluid);
                auto layout_ = Container->setLayout(cpp14::make_unique<WHBoxLayout>());
                layout_->setSpacing(0);
                Container->setPadding(0,AllSides);
                Container->setMargin(0,AllSides);
                Container->setId("containeras");
                layout->setContentsMargins(0,0,0,0);


                layout_->addWidget(cpp14::make_unique<WImage>(WLink("img/up.png")),0,AlignmentFlag::Center)->setMaximumSize(32,32);

                auto mContainer = layout_->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center|AlignmentFlag::Middle);
                mContainer->setPadding(0,AllSides);
                mContainer->setMargin(0,AllSides);

                    {
                        std::random_device rd;
                        std::mt19937 mt(rd());
                        std::uniform_real_distribution<double> dist(-100, 100);
                        int random = (dist(mt));
                        if( random <= 0 )
                        {
                            mContainer->addWidget(cpp14::make_unique<WText>(QString("%1").arg(random).toStdString().c_str()));

                            mContainer->addStyleClass("RateTextDown");
                        }else
                        {
                            mContainer->addWidget(cpp14::make_unique<WText>(QString("+%1").arg(random).toStdString().c_str()));

                            mContainer->addStyleClass("RateTextUp");
                        }

                        {
                            std::random_device rd;
                            std::mt19937 mt(rd());
                            std::uniform_real_distribution<double> dist(0, 100);
                            int random = (dist(mt));
                            QString str = QString("%1").arg((int)dist(mt)+random+100);
                            layout_->addWidget(cpp14::make_unique<WText>(str.toStdString().c_str()),0,AlignmentFlag::Center|AlignmentFlag::Middle);
                        }

                    }
                layout_->addWidget(cpp14::make_unique<WImage>(WLink("img/down.png")),0,AlignmentFlag::Center)->setMaximumSize(32,32);

            }



            {
                std::random_device rd;
                std::mt19937 mt(rd());
                std::uniform_real_distribution<double> dist(0, 100);
                int random = static_cast<int>((dist(mt)));

                auto kategori = layout->addWidget(cpp14::make_unique<WText>("Futbol"),0,AlignmentFlag::Right|AlignmentFlag::Middle);
                kategori->addStyleClass("ForumYorumSayisi");
//                auto cat = layout->addWidget(cpp14::make_unique<WText>(),0,AlignmentFlag::Right|AlignmentFlag::Middle);
//                cat->addItem("Futbol");


                auto yorumsayisi = layout->addWidget(cpp14::make_unique<WText>(QString("%1").arg(random).toStdString().c_str()),0,AlignmentFlag::Right|AlignmentFlag::Middle);
                yorumsayisi->addStyleClass("ForumYorumSayisi");
                yorumsayisi->setMargin(0,AllSides);
                yorumsayisi->setPadding(0,AllSides);
            }

        }



        {
            auto subcontainer = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
            subcontainer->setMargin(0,AllSides);
            subcontainer->setPadding(0,AllSides);
            auto layout = subcontainer->setLayout(cpp14::make_unique<WVBoxLayout>());
            layout->setContentsMargins(0,0,0,0);
            auto title = layout->addWidget(cpp14::make_unique<WText>("Bence Statların Çimleri Kırmızı Olsun"));
            title->addStyleClass("ForumTitle");
        }

        {
            auto subcontainer = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
            subcontainer->setMargin(0,AllSides);
            subcontainer->setPadding(0,AllSides);
            auto layout = subcontainer->setLayout(cpp14::make_unique<WVBoxLayout>());
            layout->setContentsMargins(0,0,0,0);
            auto title = layout->addWidget(cpp14::make_unique<WText>("Daha sonra oluşturduğumuz sayfa eklentisinin Daha sonra oluşturduğumuz sayfa eklentisinin kodunu almak için hemen kodunu almak için hemen ..."),0,AlignmentFlag::Justify);
//            title->addStyleClass("ForumTitle");
        }

        {
//            auto title = vLayout->addWidget(cpp14::make_unique<WText>("cmldmr"),0,AlignmentFlag::Right);
//            title->addStyleClass("ForumTitle");
        }


    }



}

Taraftar::DuyurularWidget::item::item()
{

    addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
    addStyleClass("DuyuruItem");
    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->setContentsMargins(0,0,0,0);
//    setMaximumSize(WLength::Auto,100);
    setMargin(0,AllSides);
    setPadding(0,AllSides);
    setId("item");


    {
        auto container = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setMargin(0,AllSides);
        container->setPadding(0,AllSides);
        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(cpp14::make_unique<WText>("12/12/2017"),0,AlignmentFlag::Left);
        layout->addWidget(cpp14::make_unique<WText>("12/01/2018"),0,AlignmentFlag::Right);
    }

    {
        auto container = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setMargin(0,AllSides);
        container->setPadding(0,AllSides);
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(cpp14::make_unique<WText>("Yaz Okulu Kayıtları Başladı"),0,AlignmentFlag::Center);
        layout->addWidget(cpp14::make_unique<WText>("Edit: I installed Renesis Player as suggested by this answer, but it does not work for me, probably because I have 64-bit system"),0,AlignmentFlag::Justify);
//        layout->addWidget(cpp14::make_unique<WText>("Devamı"),0,AlignmentFlag::Right);
    }

}
