#include "taraftarpage.h"



Taraftar::TaraftarPage::TaraftarPage()
{

}

Taraftar::TaraftarWidget::TaraftarWidget()
{

//    addWidget(cpp14::make_unique<WText>("Sizden Gelenler..."));
    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::container_fluid);

    for( int i = 0 ; i < 5 ; i++ )
    {
        auto row = container->addWidget(cpp14::make_unique<WContainerWidget>());
        row->addStyleClass(Bootstrap::Grid::row);
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


    for( int i = 0 ; i < 6 ; i++ )
    {
        auto row = container->addWidget(cpp14::make_unique<WContainerWidget>());
        row->addStyleClass(Bootstrap::Grid::row);
        row->addWidget(cpp14::make_unique<item>());
        row->setMaximumSize(WLength::Auto,120);
    }
}

Taraftar::TaraftarWidget::Event::Event()
{

    addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
    addStyleClass(Bootstrap::Test::Shadow::boxshadow2p2p4pGray+"ForumTitleWidget");
    auto mLayout = setLayout(cpp14::make_unique<WHBoxLayout>());
    setMaximumSize(650,120);
    setMargin(0,AllSides);


    /// Trend
    /// Doğrulama
    /// Okunma
    {
        auto Container = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
        Container->setMaximumSize(75,WLength::Auto);
        auto layout = Container->setLayout(cpp14::make_unique<WVBoxLayout>());
        layout->setSpacing(0);



        layout->addWidget(cpp14::make_unique<WImage>(WLink("img/up.png")),0,AlignmentFlag::Center)->setMaximumSize(32,32);

        auto mContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);

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
                    layout->addWidget(cpp14::make_unique<WText>(str.toStdString().c_str()),0,AlignmentFlag::Center);
                }

            }
        layout->addWidget(cpp14::make_unique<WImage>(WLink("img/down.png")),0,AlignmentFlag::Center)->setMaximumSize(32,32);

    }



    /// ust Header Bilgileri
    /// Tarih Yorum Sayısı
    /// Trend
    /// Oylama
    {

        auto container = mLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify);
//        container->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
//        container->setMargin(WLength::Auto,AllSides);
        auto vLayout = container->setLayout(cpp14::make_unique<WVBoxLayout>());

        {
            auto layout = vLayout->addLayout(cpp14::make_unique<WHBoxLayout>(),0,AlignmentFlag::Justify);
            auto tarih = layout->addWidget(cpp14::make_unique<WText>("24/10/2017"),0,AlignmentFlag::Left);
            {
                std::random_device rd;
                std::mt19937 mt(rd());
                std::uniform_real_distribution<double> dist(0, 100);
                int random = static_cast<int>((dist(mt)));
                auto yorumsayisi = layout->addWidget(cpp14::make_unique<WText>(QString("%1").arg(random).toStdString().c_str()),0,AlignmentFlag::Right);
                yorumsayisi->addStyleClass("ForumYorumSayisi");
            }

        }



        {
            auto title = vLayout->addWidget(cpp14::make_unique<WText>("Bence Statların Çimleri Kırmızı Olsun"),0,AlignmentFlag::Justify);
            title->addStyleClass("ForumTitle");
        }

        {
            auto title = vLayout->addWidget(cpp14::make_unique<WText>("Daha sonra oluşturduğumuz sayfa eklentisinin kodunu almak için hemen ..."),0,AlignmentFlag::Justify);
//            title->addStyleClass("ForumTitle");
        }

        {
            auto title = vLayout->addWidget(cpp14::make_unique<WText>("cmldmr"),0,AlignmentFlag::Right);
//            title->addStyleClass("ForumTitle");
        }


    }



}

Taraftar::DuyurularWidget::item::item()
{

    addStyleClass(Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_12+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
    addStyleClass(Bootstrap::Test::Shadow::boxshadow2p2p4pGray+"DuyuruItem");
    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());
    mLayout->setContentsMargins(0,0,0,0);
    setMaximumSize(WLength::Auto,100);
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
