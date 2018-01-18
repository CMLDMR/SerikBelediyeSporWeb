#include "body.h"

Body::Body::Body()
    :WContainerWidget()
{


    addStyleClass(Bootstrap::Grid::container_fluid);
    mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->setContentAlignment(AlignmentFlag::Center);



    this->initBody();


}

void Body::Body::initBody()
{
    mainContainer->clear();
    mainContainer->addWidget(cpp14::make_unique<MainHaber>());
    SubContainer = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    SubContainer->setMaximumSize(1200,WLength::Auto);
    SubContainer->addStyleClass(Bootstrap::Grid::row);

    SubContainer->addWidget(cpp14::make_unique<SubHaber>());
    SubContainer->addWidget(cpp14::make_unique<Duyurular>());

    mainContainer->addWidget(cpp14::make_unique<PhotoVideo>());
    mainContainer->addWidget(cpp14::make_unique<Kategoriler>());
    mainContainer->addWidget(cpp14::make_unique<Ozellerimiz>());
}

void Body::Body::initKategoriler()
{

    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<KategorilerWidget>());

}

void Body::Body::initTaraftar()
{

    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<Taraftar::TaraftarWidget>());

}

void Body::Body::initOkullar()
{
    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<Okul::OkullarWidget>());
}

void Body::Body::initStore()
{
    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<Store::StoreWidget>());
}



Body::MainHaber::MainHaber()
    :WContainerWidget()
{
    mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::row);
    this->addHaber("Haber","New Text Flowless Layout Launched","MState, a startup accelerator, aims to invest in blockchain startups globally and ultimately connect them with Fortune 500 customers, co-founder Rob Bailey told Bloomberg.","img/1.jpg");
    this->addHaber("Haber","Detailed Description","By default, a toolbar is rendered as compact leaving no margin between buttons. By adding a separator or a split button, the toolbar also supports separation between buttons.","img/2.jpg");
    this->addHaber("Rapor","Member Function Documentation","When adding a split button, the toolbar automatically becomes non-compact","img/3.jpg");
}


void Body::MainHaber::addHaber(std::string category, std::string title, std::string subTitle, std::string imgpath)
{
    {
        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_6);
//        container->decorationStyle().setBackgroundImage(WLink(imgpath));
        container->setAttributeValue("style","background-image: url("+imgpath+") ; background-repeat: no-repeat; background-size:cover;");

        container->setHeight(350);
        {
            auto contentContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
            contentContainer->addStyleClass("contentContainer");
            {
                auto text1 = contentContainer->addWidget(cpp14::make_unique<WText>(category));
                text1->addStyleClass("text1");
            }
            {
                auto text1 = contentContainer->addWidget(cpp14::make_unique<WText>(title));
                text1->addStyleClass("text2");
            }
            {
                auto text1 = contentContainer->addWidget(cpp14::make_unique<WText>(subTitle));
                text1->addStyleClass("text3");
            }
        }
    }
}

Body::SubHaber::SubHaber()
    :WContainerWidget()
{
    addStyleClass(Bootstrap::Grid::Large::col_lg_8);
    addStyleClass("SubHaberCSS");
//    decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Medium,WColor("rgb(0,255,0)")));
    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());

    mMainContainer->addStyleClass(Bootstrap::Grid::row);

    this->addItem("Ust","3-1 ile Galibilyetle Yine Fark Attı","Spor Toto Süper Lig'in 9. haftasında Galatasaray ve Fenerbahçe derbi maçı oynadı ve maç","img/4.jpg", "Video İzle",Bootstrap::Grid::Large::col_lg_12);

    this->addItem("Alt","Beşiktaş ADO Den Haag hazırlık maçı","Ev sahibi, 33'te Wass ile öne geçti. Bale, 36 ve 38'de attığı gollerle skoru Real Madrid lehine çevirdi. 72'de Celta Vigo'dan Iago Aspas...","img/5.jpg", "Fotoğraflar",Bootstrap::Grid::Large::col_lg_6);

    this->addItem("Alt","Obradovic: Beklediğimiz şekilde bir maç oldu","Maçın ardından düzenlenen basın toplantısında açıklamalarda bulunan Obradovic, THY Avrupa Ligi'nden sonra ligde oynamanın zor olduğunu vurgulayarak...","img/6.jpg", "Video İzle",Bootstrap::Grid::Large::col_lg_6);



}

void Body::SubHaber::addItem(std::string Cat, std::string title, std::string subTitle, std::string imgPath, std::string videoFoto, std::string styleClass)
{


    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(styleClass+" SubHaberContainer");
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());


        {
            auto picContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify);
            picContainer->addStyleClass(Bootstrap::Grid::container_fluid);
            picContainer->setAttributeValue("style","background-image: url("+imgPath+") ; background-repeat: no-repeat; background-size:cover;");
            if(Cat == "Alt" )
            {
                 picContainer->setHeight(250);
            }else{
                picContainer->setHeight(300);
            }

//            picContainer->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Medium,WColor("rgb(0,125,255)")));
        }

        {
            auto textContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
            auto _layout = textContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto CatTitle = _layout->addWidget(cpp14::make_unique<WText>(Cat),0,AlignmentFlag::Left);
            CatTitle->addStyleClass("SubHaberTitleCat");

            auto Title = _layout->addWidget(cpp14::make_unique<WText>(title),0,AlignmentFlag::Left);
            Title->addStyleClass("SubHaberTitle");

            auto explain = _layout->addWidget(cpp14::make_unique<WText>(subTitle),0,AlignmentFlag::Left);

            auto link = _layout->addWidget(cpp14::make_unique<WText>(videoFoto),0,AlignmentFlag::Left);
            link->addStyleClass("SubHaberLink");
        }
    }


}

Body::Duyurular::Duyurular()
    :WContainerWidget()
{
//    decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thick,WColor("rgb(0,0,255)")));
    setPadding(0,AllSides);
    addStyleClass(Bootstrap::Grid::Large::col_lg_4+"DuyurularWidget");
    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());

    mMainContainer->setPadding(0,AllSides);

    auto layout = mMainContainer->setLayout(cpp14::make_unique<WVBoxLayout>());
    layout->setContentsMargins(0,0,0,0);

    //Last Event
    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue("style","background-image: url(img/7.jpg) ; background-repeat: no-repeat; background-size:cover;");
        container->setPadding(10,AllSides);

        auto _container = container->addWidget(cpp14::make_unique<WContainerWidget>());
        _container->decorationStyle().setBackgroundColor(WColor("rgba(25,25,25,0.65)"));
        _container->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thin,WColor("rgb(255,255,255)")));
        _container->addStyleClass("DuyuruLastEvent");
        auto _Layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());

        _Layout->addStretch(1);
        auto img = _Layout->addWidget(cpp14::make_unique<WImage>(WLink("icon/3.png")),0,AlignmentFlag::Center);
        img->setMaximumSize(70,70);
        auto text = _Layout->addWidget(cpp14::make_unique<WText>("Serik Belediye Spor"),0,AlignmentFlag::Center);
        auto explain = _Layout->addWidget(cpp14::make_unique<WText>("Serik Belediye Spor - Kepez Belediye Spor"),0,AlignmentFlag::Center);
        auto Tarih = _Layout->addWidget(cpp14::make_unique<WText>("17/02/2018 Çarşamba - Saat: 16:00"),0,AlignmentFlag::Center);
        auto Yer = _Layout->addWidget(cpp14::make_unique<WText>("İsmail Oğan Stadyumu"),0,AlignmentFlag::Center);

        _Layout->addStretch(1);

    }


    layout->addSpacing(25);

    {

        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());

        auto title = container->addWidget(cpp14::make_unique<WText>("Takvim"));

        auto _container = container->addWidget(cpp14::make_unique<WContainerWidget>());

        auto _layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());


        // DUYURULAR
        {
            auto sContainer = _layout->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass("DuyuruEvent");
            auto sLayout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto title = sLayout->addWidget(cpp14::make_unique<WText>("Grup Maçı"));
            sLayout->addWidget(cpp14::make_unique<WText>("Futbol"));
            sLayout->addWidget(cpp14::make_unique<WText>("Serik Belediye Spor - Aksu Belediye Spor"));
            sLayout->addWidget(cpp14::make_unique<WText>("12/03/2018 Perşembe Saat: 10:00"));
            sLayout->addWidget(cpp14::make_unique<WText>("Murat Paşa Stadyumu"));
        }


        {
            auto sContainer = _layout->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass("DuyuruEvent");
            auto sLayout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());


            auto title = sLayout->addWidget(cpp14::make_unique<WText>("Final"));
            sLayout->addWidget(cpp14::make_unique<WText>("Basketbol"));
            sLayout->addWidget(cpp14::make_unique<WText>("Serik Belediye Spor - Alanya Spor"));
            sLayout->addWidget(cpp14::make_unique<WText>("12/04/2018 Perşembe Saat: 12:00"));
            sLayout->addWidget(cpp14::make_unique<WText>("Konya Altı Kapalı Spor Salonu"));
        }

        {
            auto sContainer = _layout->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass("DuyuruEvent");
            auto sLayout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto title = sLayout->addWidget(cpp14::make_unique<WText>("Çeyrek Final"));
            sLayout->addWidget(cpp14::make_unique<WText>("Futbol"));
            sLayout->addWidget(cpp14::make_unique<WText>("Manavgat Spor - Serik Belediye Spor"));
            sLayout->addWidget(cpp14::make_unique<WText>("15/04/2018 Cuma Saat: 18:00"));
            sLayout->addWidget(cpp14::make_unique<WText>("Kepez Stadyumu"));
        }


        {
            auto sContainer = _layout->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass("DuyuruEvent");
            auto sLayout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto title = sLayout->addWidget(cpp14::make_unique<WText>("Duyuru"));
            sLayout->addWidget(cpp14::make_unique<WText>("Transfer"));
            sLayout->addWidget(cpp14::make_unique<WText>("Ronaldo, Serik Belediye Spora Transferi"));
            sLayout->addWidget(cpp14::make_unique<WText>("19/04/2018 Cuma Saat: 18:00"));
            sLayout->addWidget(cpp14::make_unique<WText>("Konferans Salonu"));
            sLayout->addWidget(cpp14::make_unique<WText>("Basın Açıklaması Yapılacak"));
        }

    }


}

Body::Kategoriler::Kategoriler()
    :WContainerWidget()
{
    setContentAlignment(AlignmentFlag::Center);
    setMargin(0,AllSides);
    addStyleClass(Bootstrap::Grid::container_fluid + "Kategoriler");
    mMainContainerWidget = addWidget(cpp14::make_unique<WContainerWidget>());

//        mMainContainerWidget->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Medium,WColor("rgb(255,0,0)")));

    mMainContainerWidget->addStyleClass(Bootstrap::Grid::row);
    mMainContainerWidget->setContentAlignment(AlignmentFlag::Center);
    mMainContainerWidget->setPadding(5,AllSides);

    addItem("Futbol","img/7.jpg","Tarihimiz");
//    addItem("Futbol","img/8.jpg","Oyuncularımız");
    addItem("Basketbol","img/9.jpg","Tarihimiz");
//    addItem("Basketbol","img/8.jpg","Kupalarımız");
//    addItem("Voleybol","img/9.jpg","Tarihimiz");
    addItem("Hentbol","img/8.jpg","Tarihimiz");
    addItem("Diğer","img/9.jpg","Tarihimiz");

}

void Body::Kategoriler::addItem(std::string title,std::string imgPath, std::string subTitle)
{

    auto container = mMainContainerWidget->addWidget(cpp14::make_unique<WContainerWidget>());
    container->setHeight(400);
//    container->setWidth(250);
    container->setPadding(0,AllSides);
    container->setMargin(10,AllSides);
    container->addStyleClass(Bootstrap::Grid::Large::col_lg_3+"KategoriItem");

    container->setAttributeValue("style","background-image: url("+imgPath+"); background-repeat: no-repeat; background-size:cover;");

    auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
    layout->setContentsMargins(0,0,0,0);

    {
        auto titleContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        titleContainer->setMargin(0,AllSides);
        titleContainer->addStyleClass("KategoriBackground KategoriItemTitle");
        titleContainer->addWidget(cpp14::make_unique<WText>(title));
    }
    layout->addStretch(1);

    {
        auto titleContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        titleContainer->addStyleClass("KategoriBackground KategoriItemSubTitle");
        titleContainer->setMargin(0,AllSides);
        titleContainer->addWidget(cpp14::make_unique<WText>(subTitle));
    }


}

Body::PhotoVideo::PhotoVideo()
    :WContainerWidget()
{

    addStyleClass(Bootstrap::Grid::container_fluid+"PhotoVideoContainer");

    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->addStyleClass(Bootstrap::Grid::row);

    {
        auto titleContainer = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        titleContainer->setMaximumSize(1200,WLength::Auto);
        titleContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_12);

        auto layout = titleContainer->setLayout(cpp14::make_unique<WHBoxLayout>());

        layout->addStretch(1);
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>("Fotoğraflar ve Videolar"),0,AlignmentFlag::Left|AlignmentFlag::Middle);
            title->addStyleClass("PhotoVideoContainerTitle");
        }
        layout->addSpacing(20);
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>("Daha Fazla Fotoğraf"),0,AlignmentFlag::Left|AlignmentFlag::Middle);
            title->addStyleClass("SubPhotoVideoTitle");
        }
        layout->addSpacing(20);
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>("Daha Fazla Video"),0,AlignmentFlag::Left|AlignmentFlag::Middle);
            title->addStyleClass("SubPhotoVideoTitle");
        }
        layout->addStretch(1);

    }


    {
        SliderContainer = addWidget(cpp14::make_unique<WContainerWidget>());
        SliderContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
        SliderContainer->setOverflow(Overflow::Hidden);

        SliderSubContainer = SliderContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        SliderSubContainer->setHeight(250);
        SliderSubContainer->addStyleClass("SubVideoPhotoSlider");

        fLayout = SliderSubContainer->setLayout(cpp14::make_unique<WHBoxLayout>());


        this->addItem("img/4.jpg",false,"Animation Shorthand Property");
        this->addItem("img/5.jpg",true,"The same animation");
        this->addItem("img/4.jpg",false,"The example below uses");
        this->addItem("img/8.jpg",true,"element get the style");
        this->addItem("img/5.jpg",true,"during the animation-delay period");
        this->addItem("img/9.jpg",false,"Specify the fill-mode");
        this->addItem("img/1.jpg",false,"For an Animation");
        this->addItem("img/2.jpg",true,"The following example shows");
        this->addItem("img/3.jpg",true,"Specify the Speed");
        this->addItem("img/4.jpg",false,"Curve of the Animation");
        this->addItem("img/5.jpg",true,"alternate-reverse");
        this->addItem("img/6.jpg",false,"animation run forwards");
        this->addItem("img/7.jpg",true,"Reverse Direction");
        this->addItem("img/6.jpg",false,"Set How Many Times");
        this->addItem("img/4.jpg",true,"Animation Should Run");
        this->addItem("img/7.jpg",false,"Negative values are also");

    }





}

void Body::PhotoVideo::addItem(std::string imgPath, bool video, std::string title )
{


    auto container = fLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    container->setAttributeValue("style","background-image: url("+imgPath+") ; background-repeat: no-repeat; background-size:cover;");
    container->addStyleClass("SubVideoContainerItem");
    container->setMinimumSize(300,WLength::Auto);
    container->setHeight(200);
    container->setWidth(300);
    container->setOverflow(Overflow::Hidden);
    {
        auto _container = container->addWidget(cpp14::make_unique<WContainerWidget>());
        auto titleWidget = _container->addWidget(cpp14::make_unique<WText>(title));
        _container->addStyleClass("SubVideoPhotoWidgetTitle");
    }


    if( video )
    {
        auto img = container->addWidget(cpp14::make_unique<WImage>(WLink("img/video.png")));
        img->setMaximumSize(60,60);
        img->addStyleClass("SubPhotoVideoLogo");
    }else{
        auto img = container->addWidget(cpp14::make_unique<WImage>(WLink("img/resim.png")));
        img->setMaximumSize(70,70);
        img->addStyleClass("SubPhotoVideoLogo");
    }



}

Body::Ozellerimiz::Ozellerimiz()
    :WContainerWidget()
{



    addStyleClass(Bootstrap::Grid::container_fluid);
//    setMargin(50,Side::Bottom);



    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->addStyleClass(Bootstrap::Grid::row);
    mMainContainer->addStyleClass("OzellerimizMainWidget");
//    mMainContainer->setHeight(600);

    auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    container->setAttributeValue("style","background-image: url(icon/4.png); background-repeat: no-repeat; background-size:contain;background-position: center; ");
//    container->setHeight(600);
    container->addStyleClass("OzellerimizContainerWidget");





    auto _Container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _Container->addStyleClass("OzelliklerimizForeGround");
    auto layout = _Container->setLayout(cpp14::make_unique<WVBoxLayout>());



    {
        layout->addWidget(cpp14::make_unique<WImage>(WLink("icon/3.png")),0,AlignmentFlag::Center|AlignmentFlag::TextTop)->setMaximumSize(100,100);
        {
            auto title = layout->addWidget(cpp14::make_unique<WText>("En İyi"),0,AlignmentFlag::Center|AlignmentFlag::Top);
            title->addStyleClass("OzelliklerTitle");
        }
    }




    auto ContentContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
    ContentContainer->addStyleClass(Bootstrap::Grid::row+"OzelliklerimizForeGround");

    {
        auto sContainer = ContentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        sContainer->setHeight(350);
        sContainer->setAttributeValue("style","background-image: url(img/4.jpg); background-repeat: no-repeat; background-size:contain;background-position: center; ");
        sContainer->setOverflow(Overflow::Hidden);
        auto _layout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

        _layout->addWidget(cpp14::make_unique<WText>("Zaferlerimiz"),0,AlignmentFlag::Center|AlignmentFlag::Top);

    }

    {
        auto sContainer = ContentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        sContainer->setHeight(350);
        sContainer->setAttributeValue("style","background-image: url(img/2.jpg); background-repeat: no-repeat; background-size:contain;background-position: center; ");
        sContainer->setOverflow(Overflow::Hidden);
        auto _layout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

        _layout->addWidget(cpp14::make_unique<WText>("Gollerimiz"),0,AlignmentFlag::Center|AlignmentFlag::Top);

    }

    {
        auto sContainer = ContentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        sContainer->setHeight(350);
        sContainer->setAttributeValue("style","background-image: url(img/6.jpg); background-repeat: no-repeat; background-size:contain;background-position: center; ");
        sContainer->setOverflow(Overflow::Hidden);
        auto _layout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

        _layout->addWidget(cpp14::make_unique<WText>("Yılımız"),0,AlignmentFlag::Center|AlignmentFlag::Top);

    }

    {
        auto sContainer = ContentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        sContainer->setHeight(350);
        sContainer->setAttributeValue("style","background-image: url(img/7.jpg); background-repeat: no-repeat; background-size:contain;background-position: center; ");
        sContainer->setOverflow(Overflow::Hidden);

        auto _layout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

        _layout->addWidget(cpp14::make_unique<WText>("Taraftarlarımız"),0,AlignmentFlag::Center|AlignmentFlag::Top);

    }



}
