#include "footer.h"
#include "ToolKit/bootstrap.h"

FooterSpace::Footer::Footer()
{

    addStyleClass(Bootstrap::Grid::container_fluid+"footer "+Bootstrap::Test::border1px);

    auto mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());

    auto mainContainer = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::row);


    {
        mainContainer->addWidget(cpp14::make_unique<Kurumsal>())->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6);
    }

    {
        mainContainer->addWidget(cpp14::make_unique<Branslar>())->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6);
    }

    {
        mainContainer->addWidget(cpp14::make_unique<Aktiviteler>())->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6);
    }

    {
        mainContainer->addWidget(cpp14::make_unique<Okullar>())->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6);
    }

    {
        mainContainer->addWidget(cpp14::make_unique<Arsiv>())->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6);
    }

    {
        mainContainer->addWidget(cpp14::make_unique<Hakkimizda>())->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_6);
    }


    {
        mLayout->addSpacing(50);
        {
            mLayout->addWidget(cpp14::make_unique<WText>("<p>Serik Belediyesi Spor İşleri Müdürlüğü © 2017</p>"),0,AlignmentFlag::Center);
            mLayout->addWidget(cpp14::make_unique<WText>("<p>Bu Web Sayfası Serik Belediyesi Bilgi İşlem Müdürlüğü Tarafından</p>"),0,AlignmentFlag::Center);
            mLayout->addWidget(cpp14::make_unique<WText>("<p>Açık Kaynak Kodlu Olarak Geliştirilmektekdir.</p>"),0,AlignmentFlag::Center);

            auto container = mLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);

            auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());



            WLink wLink = Wt::WLink("https://www.webtoolkit.eu/wt");
            wLink.setTarget(Wt::LinkTarget::NewWindow);

            WLink qLink = Wt::WLink("https://www.qt.io/");
            wLink.setTarget(Wt::LinkTarget::NewWindow);

            WLink mLink = Wt::WLink("https://www.mongodb.com/");
            wLink.setTarget(Wt::LinkTarget::NewWindow);


            WLink gLink = Wt::WLink("https://github.com/CMLDMR/SerikBelediyeSporWeb");
            wLink.setTarget(Wt::LinkTarget::NewWindow);

            layout->addWidget(cpp14::make_unique<Wt::WAnchor>(wLink,
                                    "Wt "),0,AlignmentFlag::Center);

            layout->addWidget(cpp14::make_unique<Wt::WAnchor>(qLink,
                                    "Qt "),0,AlignmentFlag::Center);

            layout->addWidget(cpp14::make_unique<Wt::WAnchor>(mLink,
                                    "MongoDB "),0,AlignmentFlag::Center);

            layout->addWidget(cpp14::make_unique<Wt::WText>("& "));

            layout->addWidget(cpp14::make_unique<Wt::WAnchor>(gLink,
                                    "github "),0,AlignmentFlag::Center);

        }
    }
    mLayout->setSpacing(0);
}

FooterSpace::Kurumsal::Kurumsal()
{

    setContentAlignment(AlignmentFlag::Center);
    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    auto kurumsal = addWidget(cpp14::make_unique<WText>("Kurumsal"));

    WFont font;
    font.setFamily(FontFamily::Default,"Tahoma");
    font.setSize(FontSize::Large);
    font.setWeight(FontWeight::Lighter);

    kurumsal->decorationStyle().setFont(font);
    kurumsal->addStyleClass(Bootstrap::Test::Display::block+Bootstrap::TextDecoration::underline+Bootstrap::Test::Padding::Padding10px);

    //Hakkımızda
    {
        addWidget(cpp14::make_unique<WText>("► Hakkımızda"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Yönetim
    {
        addWidget(cpp14::make_unique<WText>("► Yönetim"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Tarihçe
    {
        addWidget(cpp14::make_unique<WText>("► Tarihçe"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //İletişim
    {
        addWidget(cpp14::make_unique<WText>("► İletişim"))->addStyleClass(Bootstrap::Test::Display::block);
    }
}

FooterSpace::Branslar::Branslar()
{

    setContentAlignment(AlignmentFlag::Center);
    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    auto kurumsal = addWidget(cpp14::make_unique<WText>("Branşlar"));
    WFont font;
    font.setFamily(FontFamily::Default,"Tahoma");
    font.setSize(FontSize::Large);
    font.setWeight(FontWeight::Lighter);

    kurumsal->decorationStyle().setFont(font);
    kurumsal->addStyleClass(Bootstrap::Test::Display::block+Bootstrap::TextDecoration::underline+Bootstrap::Test::Padding::Padding10px);

    //Futbol
    {
        addWidget(cpp14::make_unique<WText>("Futbol"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Basketbol
    {
        addWidget(cpp14::make_unique<WText>("Basketbol"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Hentbol
    {
        addWidget(cpp14::make_unique<WText>("Hentbol"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Güreş
    {
        addWidget(cpp14::make_unique<WText>("Güreş"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Voleybol
    {
        addWidget(cpp14::make_unique<WText>("Voleybol"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Tenis
    {
        addWidget(cpp14::make_unique<WText>("Tenis"))->addStyleClass(Bootstrap::Test::Display::block);
    }
}

FooterSpace::Aktiviteler::Aktiviteler()
{

    setContentAlignment(AlignmentFlag::Center);
    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    auto kurumsal = addWidget(cpp14::make_unique<WText>("Aktiviteler"));
    WFont font;
    font.setFamily(FontFamily::Default,"Tahoma");
    font.setSize(FontSize::Large);
    font.setWeight(FontWeight::Lighter);

    kurumsal->decorationStyle().setFont(font);
    kurumsal->addStyleClass(Bootstrap::Test::Display::block+Bootstrap::TextDecoration::underline+Bootstrap::Test::Padding::Padding10px);

    //Futbol
    {
        addWidget(cpp14::make_unique<WText>("Traking"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Basketbol
    {
        addWidget(cpp14::make_unique<WText>("Turnuva"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Hentbol
    {
        addWidget(cpp14::make_unique<WText>("Yürüyüş"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Güreş
    {
        addWidget(cpp14::make_unique<WText>("Bisiklet"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Voleybol
    {
        addWidget(cpp14::make_unique<WText>("Gezi"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Tenis
    {
        addWidget(cpp14::make_unique<WText>("Tenis"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Hentbol
    {
        addWidget(cpp14::make_unique<WText>("Yürüyüş"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Güreş
    {
        addWidget(cpp14::make_unique<WText>("Bisiklet"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Hentbol
    {
        addWidget(cpp14::make_unique<WText>("Yürüyüş"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Güreş
    {
        addWidget(cpp14::make_unique<WText>("Bisiklet"))->addStyleClass(Bootstrap::Test::Display::block);
    }

}

FooterSpace::Okullar::Okullar()
{

    setContentAlignment(AlignmentFlag::Center);
    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    auto kurumsal = addWidget(cpp14::make_unique<WText>("Okullar"));
    WFont font;
    font.setFamily(FontFamily::Default,"Tahoma");
    font.setSize(FontSize::Large);
    font.setWeight(FontWeight::Lighter);

    kurumsal->decorationStyle().setFont(font);
    kurumsal->addStyleClass(Bootstrap::Test::Display::block+Bootstrap::TextDecoration::underline+Bootstrap::Test::Padding::Padding10px);

    //Futbol
    {
        addWidget(cpp14::make_unique<WText>("Jimnastik"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Basketbol
    {
        addWidget(cpp14::make_unique<WText>("Santranç"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Hentbol
    {
        addWidget(cpp14::make_unique<WText>("Futbol"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Güreş
    {
        addWidget(cpp14::make_unique<WText>("Basketbol"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Voleybol
    {
        addWidget(cpp14::make_unique<WText>("Hentbol"))->addStyleClass(Bootstrap::Test::Display::block);
    }



}

FooterSpace::Arsiv::Arsiv()
{
    setContentAlignment(AlignmentFlag::Center);
    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    auto kurumsal = addWidget(cpp14::make_unique<WText>("Arşiv"));
    WFont font;
    font.setFamily(FontFamily::Default,"Tahoma");
    font.setSize(FontSize::Large);
    font.setWeight(FontWeight::Lighter);

    kurumsal->decorationStyle().setFont(font);
    kurumsal->addStyleClass(Bootstrap::Test::Display::block+Bootstrap::TextDecoration::underline+Bootstrap::Test::Padding::Padding10px);

    //Futbol
    {
        addWidget(cpp14::make_unique<WText>("Fotoğraflar"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Basketbol
    {
        addWidget(cpp14::make_unique<WText>("Videolar"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Hentbol
    {
        addWidget(cpp14::make_unique<WText>("Basında"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Güreş
    {
        addWidget(cpp14::make_unique<WText>("Medya"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Voleybol
    {
        addWidget(cpp14::make_unique<WText>("Dergiler"))->addStyleClass(Bootstrap::Test::Display::block);
    }
}


FooterSpace::Hakkimizda::Hakkimizda()
{

    setContentAlignment(AlignmentFlag::Center);
    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container);
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    auto kurumsal = addWidget(cpp14::make_unique<WText>("Hakkımızda"));
    WFont font;
    font.setFamily(FontFamily::Default,"Tahoma");
    font.setSize(FontSize::Large);
    font.setWeight(FontWeight::Lighter);

    kurumsal->decorationStyle().setFont(font);
    kurumsal->addStyleClass(Bootstrap::Test::Display::block+Bootstrap::TextDecoration::underline+Bootstrap::Test::Padding::Padding10px);


    //Futbol
    {
        addWidget(cpp14::make_unique<WText>("Nostalji"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Basketbol
    {
        addWidget(cpp14::make_unique<WText>("Tesisler"))->addStyleClass(Bootstrap::Test::Display::block);
    }


    //Güreş
    {
        addWidget(cpp14::make_unique<WText>("İletişim"))->addStyleClass(Bootstrap::Test::Display::block);
    }

    //Voleybol
    {
        addWidget(cpp14::make_unique<WText>("Adres"))->addStyleClass(Bootstrap::Test::Display::block);
    }

}
