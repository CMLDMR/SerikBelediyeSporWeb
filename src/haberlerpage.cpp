#include "haberlerpage.h"
#include "databasekeys.h"

HaberlerPage::HaberlerPage(mongocxx::database *_db)
    :WContainerWidget(),
      db(_db)
{

    addStyleClass(Bootstrap::Grid::container_fluid + "HaberlerPage");

    setContentAlignment(AlignmentFlag::Center);
    addWidget(cpp14::make_unique<WText>("Haberler"))->addStyleClass("Haberler");


    auto collection = db->collection(DataBaseKeys::Haberler::collection);

    auto bucket = db->gridfs_bucket();

    {
        using namespace Bootstrap::Test;

        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->setContentAlignment(AlignmentFlag::Center);

        mLastHaber = container->addWidget(cpp14::make_unique<LastHaber>(&collection,&bucket));
        mLastHaber->addStyleClass( Bootstrap::Grid::Large::col_lg_4);

        mHaberList = container->addWidget(cpp14::make_unique<HaberList>(&collection,&bucket));
        mHaberList->addStyleClass(Bootstrap::Grid::Large::col_lg_8);
    }

}

Signal<std::string> &HaberlerPage::ClickLastHaber()
{
    return mLastHaber->mClicked;
}

LastHaber::LastHaber(mongocxx::collection *_col,mongocxx::gridfs::bucket* _bucket)
    :WContainerWidget(),
      collection(_col),
      bucket(_bucket)
{
    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container_fluid+ "LastHaber");
    mainContainer->setContentAlignment(AlignmentFlag::Center);

    addStyleClass(Bootstrap::Grid::row  );

    {

        try {

            auto option = mongocxx::options::find{};

            auto sortDoc = document{};
            sortDoc.append(kvp(DataBaseKeys::Haberler::haberid,bsoncxx::types::b_int32{-1}));

            option.sort(sortDoc.view());

            auto filter = document{};

            filter.append(kvp(DataBaseKeys::Haberler::yayinda,bsoncxx::types::b_bool{DataBaseKeys::Haberler::yayin::yayinda}));

            try {
                mongocxx::stdx::optional<bsoncxx::document::value> val = collection->find_one(filter.view(),option);

                if( val )
                {
                    {
                        this->oid = val.get().view()[DataBaseKeys::Haberler::haberid].get_oid().value.to_string();
                        bsoncxx::types::value id = val.get().view()[DataBaseKeys::Haberler::habericon].get_value();

                        auto downloader = bucket->open_download_stream(id);
                        auto file_length = downloader.file_length();
                        auto bytes_counter = 0;

                        auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
                        auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));


                        QByteArray mainArray;
                        while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
                            bytes_counter += static_cast<std::int32_t>( length_read );
                            QByteArray ar((const char*)buffer.get(),bytes_counter);
                            mainArray+= ar;
                        }

                        QString returnFileName = "NULL";

                        QFileInfo info(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());

                        QString suffix = info.suffix();


                        QString filename = "docroot/tempfile/"+ QString::fromStdString(id.get_oid().value.to_string()) +"."+ suffix;
                        QString link = "tempfile/"+ QString::fromStdString(id.get_oid().value.to_string()) +"."+ suffix;

                        std::cout << filename.toStdString() << std::endl;

                        {
                            QFile file( filename );

                            if( file.open(QIODevice::WriteOnly) )
                            {
                                file.write( mainArray );
                                returnFileName = filename;
                                file.close();

                                auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                                container->addWidget(cpp14::make_unique<WImage>(WLink(link.toStdString().c_str())))->addStyleClass("LastHaberimg");

                            }
                        }

                    }

                    {
                        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                        container->addStyleClass(Bootstrap::Grid::row);
                        container->addWidget(cpp14::make_unique<WText>(WString::fromUTF8(val.get().view()[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string().c_str())))->addStyleClass("LastHaberTitle");
                    }

                    {
                        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                        container->addStyleClass(Bootstrap::Grid::row);
                        QString str = QString::fromStdString(val.get().view()[DataBaseKeys::Haberler::icerik].get_utf8().value.to_string());
                        str.remove(QRegExp("<[^>]*>"));
                        container->addWidget(cpp14::make_unique<WText>(WString::fromUTF8(str.mid(0,400).toStdString().c_str())));
                    }

                    this->clicked().connect([=](){
                        mClicked.emit(this->oid);
                        std::cout << "emit clicled" << std::endl;
                    });



                }else{
                    auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                    container->addStyleClass(Bootstrap::Grid::row);
                    container->addWidget(cpp14::make_unique<WText>(WString("No Data Queried")));
                }

            } catch (mongocxx::exception &e) {
                auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                container->addStyleClass(Bootstrap::Grid::row);
                container->addWidget(cpp14::make_unique<WText>(WString("db Error: {1}").arg(e.what())));
            }


        } catch (bsoncxx::exception &e) {
            auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            container->addStyleClass(Bootstrap::Grid::row);
            container->addWidget(cpp14::make_unique<WText>(WString("item Error: {1}").arg(e.what())));
        }
    }

}

HaberList::HaberList(mongocxx::collection* _col, mongocxx::gridfs::bucket *_bucket)
    :WContainerWidget(),
      collection(_col),
      bucket(_bucket)
{

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::container_fluid);

    {

        auto container1 = container->addWidget(cpp14::make_unique<WContainerWidget>());
        container1->addStyleClass(Bootstrap::Grid::row);

        try {
            auto filter = document{};
            filter.append(kvp(DataBaseKeys::Haberler::yayinda,bsoncxx::types::b_bool{DataBaseKeys::Haberler::yayin::yayinda}));

            mongocxx::options::find findOption;
            findOption.limit(3);
            findOption.skip(1);

            auto sortDoc = document{};
            try {
                sortDoc.append(kvp(DataBaseKeys::Haberler::haberid,bsoncxx::types::b_int32{-1}));
            } catch (bsoncxx::exception &e) {
                container->addWidget(cpp14::make_unique<WText>(WString( "sortDoc builder Error: {1}").arg(e.what())));
            }

            findOption.sort(sortDoc.view());
            try {
                auto cursor = collection->find(filter.view(),findOption);
                for( auto doc : cursor )
                {

                    {
                        bsoncxx::types::value id = doc[DataBaseKeys::Haberler::habericon].get_value();

                        auto downloader = bucket->open_download_stream(id);
                        QFileInfo info(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());
                        QString suffix = info.suffix();
                        QString filename = "docroot/tempfile/"+ QString::fromStdString(id.get_oid().value.to_string()) +"."+ suffix;
                        QString link = "tempfile/"+ QString::fromStdString(id.get_oid().value.to_string()) +"."+ suffix;
                        QFile file( filename );

                        if( file.exists() )
                        {
                            container1->addWidget(cpp14::make_unique<HaberWidget>(doc[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string().c_str(),link.toStdString()))
                                    ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
                        }else{
                            auto file_length = downloader.file_length();
                            auto bytes_counter = 0;
                            auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
                            auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));
                            QByteArray mainArray;
                            while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
                                bytes_counter += static_cast<std::int32_t>( length_read );
                                QByteArray ar((const char*)buffer.get(),bytes_counter);
                                mainArray+= ar;
                            }
                            QString returnFileName = "NULL";
                            {
                                if( file.open(QIODevice::WriteOnly) )
                                {
                                    file.write( mainArray );
                                    returnFileName = filename;
                                    file.close();
                                    container1->addWidget(cpp14::make_unique<HaberWidget>(doc[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string().c_str(),link.toStdString()))
                                            ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
                                }
                            }
                        }
                    }
                }
            } catch (mongocxx::exception &e) {
                container->addWidget(cpp14::make_unique<WText>(WString("db query Error: {1}").arg(e.what())));
            }
        } catch (bsoncxx::exception& e) {
            container->addWidget(cpp14::make_unique<WText>(WString(" builder Error: {1}").arg(e.what())));
        }
    }


    {

        auto container1 = container->addWidget(cpp14::make_unique<WContainerWidget>());
        container1->addStyleClass(Bootstrap::Grid::row);

        try {
            auto filter = document{};
            filter.append(kvp(DataBaseKeys::Haberler::yayinda,bsoncxx::types::b_bool{DataBaseKeys::Haberler::yayin::yayinda}));

            mongocxx::options::find findOption;
            findOption.limit(3);
            findOption.skip(4);

            auto sortDoc = document{};
            try {
                sortDoc.append(kvp(DataBaseKeys::Haberler::haberid,bsoncxx::types::b_int32{-1}));
            } catch (bsoncxx::exception &e) {
                container->addWidget(cpp14::make_unique<WText>(WString( "sortDoc builder Error: {1}").arg(e.what())));
            }

            findOption.sort(sortDoc.view());
            try {
                auto cursor = collection->find(filter.view(),findOption);
                for( auto doc : cursor )
                {

                    {
                        bsoncxx::types::value id = doc[DataBaseKeys::Haberler::habericon].get_value();

                        auto downloader = bucket->open_download_stream(id);
                        QFileInfo info(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());
                        QString suffix = info.suffix();
                        QString filename = "docroot/tempfile/"+ QString::fromStdString(id.get_oid().value.to_string()) +"."+ suffix;
                        QString link = "tempfile/"+ QString::fromStdString(id.get_oid().value.to_string()) +"."+ suffix;
                        QFile file( filename );

                        if( file.exists() )
                        {
                            container1->addWidget(cpp14::make_unique<HaberWidget>(doc[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string().c_str(),link.toStdString()))
                                    ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
                        }else{
                            auto file_length = downloader.file_length();
                            auto bytes_counter = 0;
                            auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
                            auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));
                            QByteArray mainArray;
                            while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
                                bytes_counter += static_cast<std::int32_t>( length_read );
                                QByteArray ar((const char*)buffer.get(),bytes_counter);
                                mainArray+= ar;
                            }
                            QString returnFileName = "NULL";
                            {
                                if( file.open(QIODevice::WriteOnly) )
                                {
                                    file.write( mainArray );
                                    returnFileName = filename;
                                    file.close();
                                    container1->addWidget(cpp14::make_unique<HaberWidget>(doc[DataBaseKeys::Haberler::baslik].get_utf8().value.to_string().c_str(),link.toStdString()))
                                            ->addStyleClass(Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::Large::col_lg_4);
                                }
                            }
                        }
                    }
                }
            } catch (mongocxx::exception &e) {
                container->addWidget(cpp14::make_unique<WText>(WString("db query Error: {1}").arg(e.what())));
            }
        } catch (bsoncxx::exception& e) {
            container->addWidget(cpp14::make_unique<WText>(WString(" builder Error: {1}").arg(e.what())));
        }
    }

}

HaberWidget::HaberWidget(std::string str, std::string iconPath )
{
    setContentAlignment(AlignmentFlag::Center);
    addStyleClass(Bootstrap::Grid::container_fluid + " HaberWidget");
    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass("row");
        auto img = container->addWidget(cpp14::make_unique<WImage>(WLink(iconPath.c_str())));
//        img->setMaximumSize(130,130);
        img->addStyleClass("Haberimg");
    }

    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass("row");
        container->addWidget(cpp14::make_unique<WText>(str))->addStyleClass(Bootstrap::Test::maxWidth150);
    }
}
