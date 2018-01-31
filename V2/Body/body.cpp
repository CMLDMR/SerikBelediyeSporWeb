#include "body.h"

Body::Body::Body(mongocxx::database *_db)
    :WContainerWidget(),
      db(_db)
{
    addStyleClass(Bootstrap::Grid::container_fluid);
    mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    HaberlerCol = db->collection(DataBaseKeys::Haberler::collection);
    DuyurularCol = db->collection(DataBaseKeys::Duyurular::collection);

    this->initBody();
}

void Body::Body::initBody()
{
    mainContainer->clear();
    mMainHaber = mainContainer->addWidget(cpp14::make_unique<MainHaber>(&HaberlerCol,db));
    mMainHaber->mGetOid().connect(this,&Body::setHaberDetail);


    SubContainer = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    SubContainer->setMaximumSize(1200,WLength::Auto);
    SubContainer->addStyleClass(Bootstrap::Grid::row+"MaincontentContainer");

    SubContainer->addWidget(cpp14::make_unique<SubHaber>(&HaberlerCol,db))->mGetOid().connect(this,&Body::setHaberDetail);;
    mDuyuru = SubContainer->addWidget(cpp14::make_unique<Duyurular>(&DuyurularCol));
    mDuyuru->mGetOid().connect(this,&Body::setDuyuruDetail);

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

void Body::Body::initTesis()
{

    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<Tesis::TesislerimizWidget>());

}

void Body::Body::initHakkimizda()
{

    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<Hakkimizda::HakkimizdaWidget>());

}

void Body::Body::initKupalar()
{

    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<Kupa::KupalarWidget>());

}

void Body::Body::initKurumsal()
{
    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<Kurumsal::KurumsalWidget>());
}

void Body::Body::initBasin()
{
    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<Basin::BasinWidget>());
}

void Body::Body::initSignUp()
{
    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<User::SignUpWidget>());
}

void Body::Body::initSignIn()
{
    mainContainer->clear();

    mainContainer->addWidget(cpp14::make_unique<User::SigninWidget>());
}

void Body::Body::setHaberDetail(std::string oid)
{

    mainContainer->clear();

    std::cout << "HABER: " << oid << std::endl;

    auto filter = document{};
    auto uptDod = document{};

    try {
        uptDod.append(kvp("$inc",bsoncxx::builder::basic::make_document(kvp(DataBaseKeys::Haberler::okunmasayisi,bsoncxx::types::b_int64{1}))));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error Upt Doc : " << e.what() << std::endl;
    }

    try {

        filter.append(kvp(DataBaseKeys::Haberler::haberid,bsoncxx::oid{oid}));

        try {
            mongocxx::stdx::optional<bsoncxx::document::value> val = HaberlerCol.find_one_and_update(filter.view(),uptDod.view());


            if( val )
            {

                auto mContainer = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                mContainer->setAttributeValue(Style::style,Style::Border::border("1px solid white"));
                mContainer->setMaximumSize(1050,WLength::Auto);
//                mContainer->setHeight(250);
                mContainer->addStyleClass(Bootstrap::Grid::row);

                auto imgContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                imgContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
                imgContainer->setAttributeValue(Style::style,Style::Border::border("1px solid red"));
                imgContainer->setHeight(350);

                std::string imgPath = this->downloadifNotExist(val.get().view()[DataBaseKeys::Haberler::habericon].get_oid().value.to_string());

                imgContainer->setAttributeValue(Style::style,Style::background::url(imgPath)+Style::background::size::cover);
                imgContainer->setPadding(0,AllSides);
                auto textContainer = imgContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                textContainer->setHeight(350);
                textContainer->addStyleClass("HaberDetailTextContainer");
                auto layout = textContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

                auto title = layout->addWidget(cpp14::make_unique<WText>("<h2>"+val.get().view()[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string()+"</h2>"),0,AlignmentFlag::Bottom);
                title->setAttributeValue(Style::style,Style::color::rgb("255,255,255"));

                {
                    auto array = val.get().view()[DataBaseKeys::Haberler::dosyalar].get_array().value;

                    int counter = 0;
                    for( auto it = array.begin() ; it != array.end() ; it++ )
                    {
                        std::cout << "Counter : "<<counter++ << "  -  " <<  it->get_document().view()["{filename}"].get_utf8().value.to_string() << std::endl;
                        this->downloadHtmlimg(it->get_document().view()["{filename}"].get_utf8().value.to_string());
                    }
                }

                {
                    auto bContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                    bContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::LightGray));
                    auto bLayout = bContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
                    auto btn = bLayout->addWidget(cpp14::make_unique<WPushButton>("Geri"),0,AlignmentFlag::Left);
                    btn->clicked().connect(this,&Body::initBody);
                    auto tarih = bLayout->addWidget(cpp14::make_unique<WText>(WString("<h4>Yayın Tarihi: {1}</h4>").arg(val.get().view()[DataBaseKeys::Haberler::eklenmetarihi].get_int64())),0,AlignmentFlag::Left);
                    bLayout->addStretch(1);
                }

                auto htmlContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                htmlContainer->setAttributeValue(Style::style,Style::background::color::rgb("255,255,255"));
                auto htmlLayout = htmlContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

                htmlLayout->addWidget(cpp14::make_unique<WText>(val.get().view()[DataBaseKeys::Haberler::icerik].get_utf8().value.to_string(),TextFormat::UnsafeXHTML),0,AlignmentFlag::Top|AlignmentFlag::Justify);

                {
                    auto bContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                    bContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::LightGray));
                    auto bLayout = bContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
                    auto btn = bLayout->addWidget(cpp14::make_unique<WPushButton>("Geri"),0,AlignmentFlag::Left);

                    btn->clicked().connect(this,&Body::initBody);
                }


            }else{
                std::cout << "No Value" << std::endl;
            }





        } catch (mongocxx::exception &e) {
            mainContainer->addWidget(cpp14::make_unique<WText>(WString("Error: {1}").arg(e.what())));
        }
    } catch (bsoncxx::exception &e) {
        mainContainer->addWidget(cpp14::make_unique<WText>(WString("Error: {1}").arg(e.what())));
    }

}

void Body::Body::setDuyuruDetail(std::string oid)
{



    mainContainer->clear();

    std::cout << "Duyuru: " << oid << std::endl;

    auto filter = document{};
    auto uptDod = document{};

    try {
        uptDod.append(kvp("$inc",bsoncxx::builder::basic::make_document(kvp(DataBaseKeys::Duyurular::okunmasayisi,bsoncxx::types::b_int64{1}))));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error Upt Doc : " << e.what() << std::endl;
    }

    try {

        filter.append(kvp(DataBaseKeys::Duyurular::duyuruid,bsoncxx::oid{oid}));

        try {
            mongocxx::stdx::optional<bsoncxx::document::value> val = DuyurularCol.find_one_and_update(filter.view(),uptDod.view());


            if( val )
            {

                auto mContainer = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                mContainer->setAttributeValue(Style::style,Style::Border::border("1px solid white"));
                mContainer->setMaximumSize(1050,WLength::Auto);
//                mContainer->setHeight(250);
                mContainer->addStyleClass(Bootstrap::Grid::row);

//                auto imgContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
//                imgContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_12);
//                imgContainer->setAttributeValue(Style::style,Style::Border::border("1px solid red"));
//                imgContainer->setHeight(350);

//                std::string imgPath = this->downloadifNotExist(val.get().view()[DataBaseKeys::Haberler::habericon].get_oid().value.to_string());

//                imgContainer->setAttributeValue(Style::style,Style::background::url(imgPath)+Style::background::size::cover);
//                imgContainer->setPadding(0,AllSides);
                auto textContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
//                textContainer->setHeight(350);
                textContainer->addStyleClass("HaberDetailTextContainer");
                auto layout = textContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

                auto title = layout->addWidget(cpp14::make_unique<WText>("<h2>"+val.get().view()[DataBaseKeys::Duyurular::baslik].get_utf8().value.to_string()+"</h2>"),0,AlignmentFlag::Bottom);
                title->setAttributeValue(Style::style,Style::color::rgb("255,255,255"));

//                {
//                    auto array = val.get().view()[DataBaseKeys::Haberler::dosyalar].get_array().value;

//                    int counter = 0;
//                    for( auto it = array.begin() ; it != array.end() ; it++ )
//                    {
//                        std::cout << "Counter : "<<counter++ << "  -  " <<  it->get_document().view()["{filename}"].get_utf8().value.to_string() << std::endl;
//                        this->downloadHtmlimg(it->get_document().view()["{filename}"].get_utf8().value.to_string());
//                    }
//                }

                {
                    auto bContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                    bContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::LightGray));
                    auto bLayout = bContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
                    auto btn = bLayout->addWidget(cpp14::make_unique<WPushButton>("Geri"),0,AlignmentFlag::Left);
                    btn->clicked().connect(this,&Body::initBody);
                    auto tarih = bLayout->addWidget(cpp14::make_unique<WText>(WString("<h4>Yayın Tarihi: {1}</h4>").arg(val.get().view()[DataBaseKeys::Haberler::eklenmetarihi].get_int64())),0,AlignmentFlag::Left);
                    bLayout->addStretch(1);
                }

                auto htmlContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                htmlContainer->setAttributeValue(Style::style,Style::background::color::rgb("255,255,255"));
                auto htmlLayout = htmlContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

                htmlLayout->addWidget(cpp14::make_unique<WText>(val.get().view()[DataBaseKeys::Duyurular::icerik].get_utf8().value.to_string(),TextFormat::UnsafeXHTML),0,AlignmentFlag::Top|AlignmentFlag::Justify);

                {
                    auto bContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                    bContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::LightGray));
                    auto bLayout = bContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
                    auto btn = bLayout->addWidget(cpp14::make_unique<WPushButton>("Geri"),0,AlignmentFlag::Left);

                    btn->clicked().connect(this,&Body::initBody);
                }


            }else{
                std::cout << "No Value" << std::endl;
            }





        } catch (mongocxx::exception &e) {
            mainContainer->addWidget(cpp14::make_unique<WText>(WString("Error: {1}").arg(e.what())));
        }
    } catch (bsoncxx::exception &e) {
        mainContainer->addWidget(cpp14::make_unique<WText>(WString("Error: {1}").arg(e.what())));
    }

}

std::string Body::Body::downloadifNotExist(std::string oid)
{

    auto filter = document{};
    filter.append(kvp(DataBaseKeys::Haberler::habericon,bsoncxx::oid{oid.c_str()}));


    bsoncxx::types::value val = filter.view()[DataBaseKeys::Haberler::habericon].get_value();


    auto bucket = db->gridfs_bucket();

    auto downloader = bucket.open_download_stream(val);
    auto file_length = downloader.file_length();
    auto bytes_counter = 0;

    QFileInfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

    QString fullFilename = QString("tempfile/%2.%1").arg(info.suffix())
            .arg(downloader.files_document()["md5"].get_utf8().value.to_string().c_str());


    if( QFile::exists("docroot/"+fullFilename) )
    {
        return fullFilename.toStdString();
    }


    auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
    auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));
    QByteArray mainArray;
    while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
        bytes_counter += static_cast<std::int32_t>( length_read );
        QByteArray ar((const char*)buffer.get(),bytes_counter);
        mainArray+= ar;
    }
    QFile file( "docroot/"+fullFilename );
    if( file.open(QIODevice::WriteOnly) )
    {
        file.write( mainArray );
        file.close();
    }
    return fullFilename.toStdString();
}

void Body::Body::downloadHtmlimg(std::string oid)
{
    auto filter = document{};
    filter.append(kvp(DataBaseKeys::Haberler::habericon,bsoncxx::oid{oid.c_str()}));


    bsoncxx::types::value val = filter.view()[DataBaseKeys::Haberler::habericon].get_value();


    auto bucket = db->gridfs_bucket();

    auto downloader = bucket.open_download_stream(val);
    auto file_length = downloader.file_length();
    auto bytes_counter = 0;

//    QFileInfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

    QString fullFilename = QString("tempfile/%1").arg(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());


    if( QFile::exists("docroot/"+fullFilename) )
    {
        return;
    }


    auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
    auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));
    QByteArray mainArray;
    while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
        bytes_counter += static_cast<std::int32_t>( length_read );
        QByteArray ar((const char*)buffer.get(),bytes_counter);
        mainArray+= ar;
    }
    QFile file( "docroot/"+fullFilename );
    if( file.open(QIODevice::WriteOnly) )
    {
        file.write( mainArray );
        file.close();
    }
}



Body::MainHaber::MainHaber(mongocxx::collection *_collection, mongocxx::database *_db)
    :WContainerWidget(),
      collection(_collection),
      db(_db)
{
    mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::row+"MaincontentContainer");


    this->initHaberList();

    for( decltype (this->itemList.size()) i = 0 ; i < this->itemList.size() ; i++ )
    {

        auto _item = this->itemList.at(i);

        if( _item.title.size() > 46 )
        {
            _item.title.resize(44);
            _item.title.resize(44+3,'.');
        }

        if( _item.explain.size() > 250 )
        {
            _item.explain.resize(247);
            _item.explain.resize(247+3,'.');
        }

        this->addHaber("Haber",_item.title,_item.explain,_item.imgPath,_item.oid);

    }


//    this->addHaber("Haber","New Text Flowless Layout Launched","MState, a startup accelerator, aims to invest in blockchain startups globally and ultimately connect them with Fortune 500 customers, co-founder Rob Bailey told Bloomberg.","img/1.jpg");
//    this->addHaber("Haber","Detailed Description","By default, a toolbar is rendered as compact leaving no margin between buttons. By adding a separator or a split button, the toolbar also supports separation between buttons.","img/2.jpg");
//    this->addHaber("Rapor","Member Function Documentation","When adding a split button, the toolbar automatically becomes non-compact","img/3.jpg");
}


void Body::MainHaber::addHaber(std::string category, std::string title, std::string subTitle, std::string imgpath, std::string oid)
{
    {
        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
//        container->decorationStyle().setBackgroundImage(WLink(imgpath));
        container->setAttributeValue("style","background-image: url("+imgpath+") ; background-repeat: no-repeat; background-size:cover;");
        container->setAttributeValue("data-"+DataBaseKeys::Haberler::haberid,oid);

        container->clicked().connect([=](){
            oidClicked.emit(container->attributeValue("data-"+DataBaseKeys::Haberler::haberid).toUTF8());
        });

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

Signal<std::string> &Body::MainHaber::mGetOid()
{
    return this->oidClicked;
}

void Body::MainHaber::initHaberList()
{
    itemList.clear();
    auto filter = document{};
    try {
        filter.append(kvp(DataBaseKeys::Haberler::yayinda,bsoncxx::types::b_bool{DataBaseKeys::Haberler::yayin::yayinda}));
        mongocxx::options::find findOptions;
        findOptions.limit(3);

        auto sortDoc = document{};
        try {
            sortDoc.append(kvp(DataBaseKeys::Haberler::haberid,-1));

        } catch (bsoncxx::exception &e) {
            std::cout << "bson sort Error: " << e.what() << std::endl;
        }
        findOptions.sort(sortDoc.view());
        try {
            auto cursor = collection->find(filter.view(),findOptions);
            for( auto doc : cursor )
            {
                item _item;
                _item.explain = doc[DataBaseKeys::Haberler::icerikPlain].get_utf8().value.to_string();
                _item.title = doc[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string();
                _item.imgPath = this->downloadifNotExist(doc[DataBaseKeys::Haberler::habericon].get_oid().value.to_string());
                _item.oid = doc[DataBaseKeys::Haberler::haberid].get_oid().value.to_string();
                _item.type = "Haber";
                itemList.push_back(_item);
            }
        } catch (mongocxx::exception &e) {
            std::cout << "mongo Error: " << e.what() << std::endl;
        }
    } catch (bsoncxx::exception &e) {
        std::cout << "bson Error: " << e.what() << std::endl;
    }
}

std::string Body::MainHaber::downloadifNotExist(std::string oid)
{

    auto filter = document{};
    filter.append(kvp(DataBaseKeys::Haberler::habericon,bsoncxx::oid{oid.c_str()}));


    bsoncxx::types::value val = filter.view()[DataBaseKeys::Haberler::habericon].get_value();


    auto bucket = db->gridfs_bucket();

    auto downloader = bucket.open_download_stream(val);
    auto file_length = downloader.file_length();
    auto bytes_counter = 0;

    QFileInfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

    QString fullFilename = QString("tempfile/%2.%1").arg(info.suffix())
            .arg(downloader.files_document()["md5"].get_utf8().value.to_string().c_str());


    if( QFile::exists("docroot/"+fullFilename) )
    {
        return fullFilename.toStdString();
    }


    auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
    auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));
    QByteArray mainArray;
    while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
        bytes_counter += static_cast<std::int32_t>( length_read );
        QByteArray ar((const char*)buffer.get(),bytes_counter);
        mainArray+= ar;
    }
    QFile file( "docroot/"+fullFilename );
    if( file.open(QIODevice::WriteOnly) )
    {
        file.write( mainArray );
        file.close();
    }
    return fullFilename.toStdString();
}

Body::SubHaber::SubHaber(mongocxx::collection* _collection,mongocxx::database* _db)
    :WContainerWidget(),
      collection(_collection),
      db(_db)
{
    addStyleClass(Bootstrap::Grid::Large::col_lg_8);
    addStyleClass("SubHaberCSS");
    setId("SubHaberLayout");
//    decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Medium,WColor("rgb(0,255,0)")));
    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());

    mMainContainer->addStyleClass(Bootstrap::Grid::row);

    this->initHaberList();

    for( decltype (itemList.size()) i = 0 ; i < itemList.size() ; i++ )
    {
        item _item = itemList.at(i);
        if( i == 0 )
        {
            this->addItem("Ust",_item.title,_item.explain,_item.imgPath, "Detay",
                          Bootstrap::Grid::Large::col_lg_12+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12,_item.oid);
        }

        if( i == 1 || i == 2 )
        {
            this->addItem("Alt",_item.title,_item.explain,_item.imgPath, "Detay",
                          Bootstrap::Grid::Large::col_lg_6+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12,_item.oid);

//            this->addItem("Alt","Obradovic: Beklediğimiz şekilde bir maç oldu","Maçın ardından düzenlenen basın toplantısında açıklamalarda bulunan Obradovic, THY Avrupa Ligi'nden sonra ligde oynamanın zor olduğunu vurgulayarak...","img/6.jpg", "Video İzle",
//                          Bootstrap::Grid::Large::col_lg_6+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
        }

        if( i > 2 )
        {
            this->addItem("Alt",_item.title,_item.explain,_item.imgPath, "Detay",Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12,_item.oid);
//            this->addItem("Alt","Obradovic: Beklediğimiz şekilde bir maç oldu","Maçın ardından düzenlenen basın toplantısın...","img/6.jpg", "Video İzle",Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
//            this->addItem("Alt","Obradovic: Beklediğimiz şekilde bir maç oldu","Maçın ardından düzenlenen basın toplantısın...","img/6.jpg", "Video İzle",Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);

        }
    }







}

void Body::SubHaber::addItem(std::string Cat, std::string title, std::string subTitle, std::string imgPath, std::string videoFoto, std::string styleClass, std::string oid)
{


    {
        auto container = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setMargin(WLength::Auto,AllSides);
        container->addStyleClass(styleClass+" SubHaberContainer");
        container->decorationStyle().setCursor(Cursor::PointingHand);
        container->clicked().connect([=](){
            oidClicked.emit(oid);
        });
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());


        {
            auto picContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify);
            picContainer->addStyleClass(Bootstrap::Grid::container_fluid);
            picContainer->setAttributeValue("style","background-image: url("+imgPath+") ; background-repeat: no-repeat; background-size:cover;");
            if(Cat == "Alt" )
            {
                 picContainer->setHeight(130);
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

Signal<std::string> &Body::SubHaber::mGetOid()
{
    return oidClicked;
}

void Body::SubHaber::initHaberList()
{
    itemList.clear();
    auto filter = document{};
    try {
        filter.append(kvp(DataBaseKeys::Haberler::yayinda,bsoncxx::types::b_bool{DataBaseKeys::Haberler::yayin::yayinda}));
        mongocxx::options::find findOptions;
        findOptions.limit(6);
        findOptions.skip(3);

        auto sortDoc = document{};
        sortDoc.append(kvp(DataBaseKeys::Haberler::haberid,-1));
        findOptions.sort(sortDoc.view());
        try {
            auto cursor = collection->find(filter.view(),findOptions);
            for( auto doc : cursor )
            {
                item _item;
                _item.explain = doc[DataBaseKeys::Haberler::icerikPlain].get_utf8().value.to_string();
                if( _item.explain.size() > 107 ){
                    _item.explain.resize(107+3,'.');
                }
                _item.title = doc[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string();
                _item.imgPath = this->downloadifNotExist(doc[DataBaseKeys::Haberler::habericon].get_oid().value.to_string());
                _item.oid = doc[DataBaseKeys::Haberler::haberid].get_oid().value.to_string();
                _item.type = "Haber";
                itemList.push_back(_item);
            }
        } catch (mongocxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}



std::string Body::SubHaber::downloadifNotExist(std::string oid)
{
    auto filter = document{};
    filter.append(kvp(DataBaseKeys::Haberler::habericon,bsoncxx::oid{oid.c_str()}));


    bsoncxx::types::value val = filter.view()[DataBaseKeys::Haberler::habericon].get_value();


    auto bucket = db->gridfs_bucket();

    auto downloader = bucket.open_download_stream(val);
    auto file_length = downloader.file_length();
    auto bytes_counter = 0;

    QFileInfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

    QString fullFilename = QString("tempfile/%2.%1").arg(info.suffix())
            .arg(downloader.files_document()["md5"].get_utf8().value.to_string().c_str());


    if( QFile::exists("docroot/"+fullFilename) )
    {
        return fullFilename.toStdString();
    }


    auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
    auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));
    QByteArray mainArray;
    while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
        bytes_counter += static_cast<std::int32_t>( length_read );
        QByteArray ar((const char*)buffer.get(),bytes_counter);
        mainArray+= ar;
    }
    QFile file( "docroot/"+fullFilename );
    if( file.open(QIODevice::WriteOnly) )
    {
        file.write( mainArray );
        file.close();
    }
    return fullFilename.toStdString();
}






Body::Duyurular::Duyurular(mongocxx::collection *_collection)
    :WContainerWidget(),
      collection(_collection)
{
//    decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thick,WColor("rgb(0,0,255)")));
    setPadding(0,AllSides);
    addStyleClass(Bootstrap::Grid::Large::col_lg_4+"DuyurularWidget");
    mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());

    mMainContainer->setPadding(0,AllSides);

    auto layout = mMainContainer->setLayout(cpp14::make_unique<WVBoxLayout>());
    layout->setContentsMargins(0,0,0,0);

    // Son Maçı Görüntüle
    this->addLastMatch(layout);

    layout->addSpacing(10);

    this->initList(layout);

}

Signal<std::string> &Body::Duyurular::mGetOid()
{

    return this->_oid;

}

void Body::Duyurular::addLastMatch(WVBoxLayout *_layout)
{

    //Last Event

    auto container = _layout->addWidget(cpp14::make_unique<WContainerWidget>());
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
    auto text = _Layout->addWidget(cpp14::make_unique<WText>("..."),0,AlignmentFlag::Center);
    auto explain = _Layout->addWidget(cpp14::make_unique<WText>("...."),0,AlignmentFlag::Center);
    auto Tarih = _Layout->addWidget(cpp14::make_unique<WText>("....."),0,AlignmentFlag::Center);
    auto Yer = _Layout->addWidget(cpp14::make_unique<WText>("......."),0,AlignmentFlag::Center);
    _Layout->addStretch(1);


    // Last Matching ---
    {



        auto filter = document{};
        mongocxx::options::find findOptions;

        auto sortDoc = document{};

        try {
            sortDoc.append(kvp(DataBaseKeys::Duyurular::Musabaka::Tarih,1));
        } catch (bsoncxx::exception &e) {
            text->setText(WString("sortDoc Error: {1}").arg(e.what()));
        }

        findOptions.sort(sortDoc.view());

        try {
            filter.append(kvp(DataBaseKeys::Duyurular::tipi,bsoncxx::types::b_utf8{DataBaseKeys::Duyurular::tip::Musabaka}));
            filter.append(kvp(DataBaseKeys::Duyurular::yayinda,bsoncxx::types::b_utf8{DataBaseKeys::Duyurular::yayin::yayinda}));

            int t = QDate::currentDate().toString("yyyyMMdd").toInt();
            std::cout << "Current Tarih : " << t << std::endl;
            filter.append(kvp(DataBaseKeys::Duyurular::Musabaka::Tarih,make_document(kvp("$gte",bsoncxx::types::b_int64{t}))));
            std::cout << "FILTER: " << bsoncxx::to_json(filter.view()) << std::endl;
        } catch (bsoncxx::exception& e) {
            text->setText(WString("Filter Error: {1}").arg(e.what()));
        }

        try {
            mongocxx::stdx::optional<bsoncxx::document::value> val = collection->find_one(filter.view(),findOptions);

            if( val )
            {
                text->setText(val->view()[DataBaseKeys::Duyurular::baslik].get_utf8().value.to_string().c_str());
                explain->setText(WString("{1} - {2}").arg(val->view()[DataBaseKeys::Duyurular::Musabaka::Takim1].get_utf8().value.to_string().c_str()).arg(val->view()[DataBaseKeys::Duyurular::Musabaka::Takim2].get_utf8().value.to_string().c_str()));
                QString tarih = QString::number(val->view()[DataBaseKeys::Duyurular::Musabaka::Tarih].get_int64().value);
                std::string saat = (val->view()[DataBaseKeys::Duyurular::Musabaka::Saat].get_utf8().value.to_string());
                QDate date = QDate::fromString((tarih),"yyyyMMdd");
                Tarih->setText(WString("{1} - {2}").arg(date.toString("dd/MM/yyyy dddd").toStdString()).arg(saat));
                Yer->setText(val->view()[DataBaseKeys::Duyurular::Musabaka::Yer].get_utf8().value.to_string().c_str());
            }else{
                text->setText(WString("No Document"));
            }
        } catch (mongocxx::exception &e) {
             text->setText(WString("Query Error: {1}").arg(e.what()));
        }
    }
}

void Body::Duyurular::initList(WVBoxLayout *layout)
{
    auto title = layout->addWidget(cpp14::make_unique<WText>("Takvim & Duyuru"));
    auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());

    container->addStyleClass("DuyurularWidgetSliderWidget");

    auto _container = container->addWidget(cpp14::make_unique<WContainerWidget>());

    _container->addStyleClass("DuyurularWidgetSliderArea");

    auto _layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());

    auto filter = document{};

    try {
        filter.append(kvp(DataBaseKeys::Duyurular::yayinda,bsoncxx::types::b_utf8{DataBaseKeys::Duyurular::yayin::yayinda}));
    } catch (bsoncxx::exception& e) {
        _layout->addWidget(cpp14::make_unique<WText>(WString("Bsoncxx Error: {1}").arg(e.what())));
    }

    try {
        auto cursor = collection->find(filter.view());

        for( auto doc : cursor )
        {
            if( doc[DataBaseKeys::Duyurular::tipi].get_utf8().value.to_string() == DataBaseKeys::Duyurular::tip::Duyuru )
            {
                this->addDuyuru(_layout,doc[DataBaseKeys::Duyurular::baslik].get_utf8().value.to_string(),doc[DataBaseKeys::Duyurular::icerikPlain].get_utf8().value.to_string(),doc[DataBaseKeys::Duyurular::duyuruid].get_oid().value.to_string());
            }else{
                QString str = QDate::fromString(   QString::number(doc[DataBaseKeys::Duyurular::Musabaka::Tarih].get_int64().value)  ,"yyyyMMdd").toString("dd/MM/yyyy dddd");
                this->addMatch(_layout,
                               doc[DataBaseKeys::Duyurular::baslik].get_utf8().value.to_string(),
                        "--",
                        doc[DataBaseKeys::Duyurular::Musabaka::Takim1].get_utf8().value.to_string(),
                        doc[DataBaseKeys::Duyurular::Musabaka::Takim2].get_utf8().value.to_string(),
                        str.toStdString(),
                        doc[DataBaseKeys::Duyurular::Musabaka::Saat].get_utf8().value.to_string(),
                        doc[DataBaseKeys::Duyurular::Musabaka::Yer].get_utf8().value.to_string());
            }
        }
    } catch (mongocxx::exception &e) {
        _layout->addWidget(cpp14::make_unique<WText>(WString("mongocxx Error: {1}").arg(e.what())));
    }

}

void Body::Duyurular::addMatch(WVBoxLayout* _layout, std::string _title, std::string catTitle, std::string takim1, std::string takim2, std::string tarih, std::string saat, std::string yer)
{

    auto sContainer = _layout->addWidget(cpp14::make_unique<WContainerWidget>());
    sContainer->addStyleClass("MatchEvent");
    auto sLayout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

    auto title = sLayout->addWidget(cpp14::make_unique<WText>(_title));
    sLayout->addWidget(cpp14::make_unique<WText>(catTitle));
    sLayout->addWidget(cpp14::make_unique<WText>(takim1+" - "+takim2));
    sLayout->addWidget(cpp14::make_unique<WText>(tarih + " Saat: "+saat));
    sLayout->addWidget(cpp14::make_unique<WText>(yer));
}

void Body::Duyurular::addDuyuru(WVBoxLayout* layout , std::string title , std::string icerik , std::string oid)
{
    auto sContainer = layout->addWidget(cpp14::make_unique<WContainerWidget>());
    sContainer->setAttributeValue("data-oid",oid);
    sContainer->clicked().connect([=](){
        _oid.emit(oid);
    });
    sContainer->addStyleClass("DuyuruEvent");
    auto sLayout = sContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

    auto title_ = sLayout->addWidget(cpp14::make_unique<WText>("Duyuru"));
    sLayout->addWidget(cpp14::make_unique<WText>(title));
    if( icerik.size() > 100 )
    {
        icerik.resize(103,'.');
    }
    sLayout->addWidget(cpp14::make_unique<WText>(icerik));
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

        auto sContainer = titleContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        sContainer->addStyleClass(Bootstrap::Grid::container_fluid);

//        auto layout = titleContainer->setLayout(cpp14::make_unique<WHBoxLayout>());

//        layout->addStretch(1);
        {
            auto container = sContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            container->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
            auto title = container->addWidget(cpp14::make_unique<WText>("Fotoğraflar ve Videolar"));
            title->addStyleClass("PhotoVideoContainerTitle");
        }
//        layout->addSpacing(20);
        {
            auto container = sContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            container->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
            auto title = container->addWidget(cpp14::make_unique<WText>("Daha Fazla Fotoğraf"));
            title->addStyleClass("SubPhotoVideoTitle");
        }
//        layout->addSpacing(20);
        {
            auto container = sContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            container->addStyleClass(Bootstrap::Grid::Large::col_lg_4+Bootstrap::Grid::Medium::col_md_4+Bootstrap::Grid::Small::col_sm_12+Bootstrap::Grid::ExtraSmall::col_xs_12);
            auto title = container->addWidget(cpp14::make_unique<WText>("Daha Fazla Video"));
            title->addStyleClass("SubPhotoVideoTitle");
        }
//        layout->addStretch(1);

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
