#include "signupwidget.h"



User::SignUpWidget::SignUpWidget(mongocxx::collection *_collection)
    :WContainerWidget(),Collection(_collection)
{
    addStyleClass(Bootstrap::Grid::container_fluid);
    setContentAlignment(AlignmentFlag::Center);


    {
        auto titleContainer = addWidget(cpp14::make_unique<WContainerWidget>());
        titleContainer->setMargin(100,Side::Top);
        auto layout = titleContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto title = layout->addWidget(cpp14::make_unique<WText>("Üye Ol"),0,AlignmentFlag::Center);
        title->setAttributeValue(Style::style,Style::color::color(Style::color::White::Snow));
    }


    auto mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->setMaximumSize(800,WLength::Auto);

    mMainContainer->setMargin(0,Side::Bottom);

    auto gridLayout = mMainContainer->setLayout(cpp14::make_unique<WGridLayout>());


    {
        auto text1 = gridLayout->addWidget(cpp14::make_unique<WText>("Adınız"),0,0,AlignmentFlag::Center);
        text1->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        ad = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),0,1,AlignmentFlag::Left);
        ad->setPlaceholderText("Adınızı Giriniz");
    }

    {
        auto text1 = gridLayout->addWidget(cpp14::make_unique<WText>("Soyadınızı"),1,0,AlignmentFlag::Center);
        text1->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        soyadi = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),1,1,AlignmentFlag::Left);
        soyadi->setPlaceholderText("Soyadınızı Giriniz");
    }

    {
        auto text1 = gridLayout->addWidget(cpp14::make_unique<WText>("Cep Telefon"),2,0,AlignmentFlag::Center);
        text1->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        verifyTel = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),2,1,AlignmentFlag::Left);
        verifyTel->setPlaceholderText("Telefon Numaranız - 05321234567");
    }

    {
        auto text1 = gridLayout->addWidget(cpp14::make_unique<WText>("Yaşınız"),3,0,AlignmentFlag::Center);
        text1->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        yas = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),3,1,AlignmentFlag::Left);
        yas->setPlaceholderText("Yaşınız");
    }

    {
        auto text1 = gridLayout->addWidget(cpp14::make_unique<WText>("Şifreniz"),4,0,AlignmentFlag::Center);
        text1->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        Sifre = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),4,1,AlignmentFlag::Left);
        Sifre->setPlaceholderText("Şifreniz");
    }


    {
        auto btnContainer = addWidget(cpp14::make_unique<WContainerWidget>());
        auto layout = btnContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
        startSignUpBtn = layout->addWidget(cpp14::make_unique<WPushButton>("Üyeliği Başlat"),0,AlignmentFlag::Center);
        startSignUpBtn->clicked().connect(this,&SignUpWidget::sendVerificationCode);
    }

    {
        auto btnContainer = addWidget(cpp14::make_unique<WContainerWidget>());
        btnContainer->setMaximumSize(500,WLength::Auto);
        auto layout = btnContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
        verifyCode = layout->addWidget(cpp14::make_unique<WLineEdit>(),0,AlignmentFlag::Center);
        verifyCode->setPlaceholderText("Cep Telefonunuza Gelen Doğrulama Kodunu Giriniz");
        verifyCode->setEnabled(false);
        mDogrulabtn = layout->addWidget(cpp14::make_unique<WPushButton>("Doğrula"),0,AlignmentFlag::Center);
        mDogrulabtn->setEnabled(false);
        mDogrulabtn->clicked().connect(this,&SignUpWidget::Save);
    }

    setMargin(150,Side::Bottom);

}

Signal<NoClass> &User::SignUpWidget::mGetSuccessSignUp()
{

    return this->mSuccessSignup;

}

void User::SignUpWidget::sendVerificationCode()
{

    {
        if( Sifre->text().toUTF8().size() < 5 )
        {
            this->ShowMessageBox("HATA","Şifreniz Minumum 5 Haneli Olmalı",Icon::Critical);
            return;
        }
    }

    {
        int32_t yasint;
        bool conversation;
        yasint = QString::fromStdString(yas->text().toUTF8()).toInt(&conversation,10);
        if( !conversation )
        {
            this->ShowMessageBox("HATA","Yaşınızı Hatalı Girdiniz",Icon::Critical);
            return;
        }
    }

    {
        qlonglong yasint;
        bool conversation;
        QString numara = QString::fromStdString(verifyTel->text().toUTF8());
        yasint = numara.toLongLong(&conversation,10);

//        std::cout << "NU: " << numara.count() << " " << yasint <<" " << numara.toStdString() << " " << numara.toLongLong() << std::endl;
        if( !conversation || numara.count() != 11 )
        {
            this->ShowMessageBox("HATA",WString("<p>Telefon Numarası Hatalı.</p>"
                                                "<p>Lütfen Numaranızı Başında <b>0</b> Kullanarak Giriniz</p>"
                                                "<p>Error: {1} </p>").arg(verifyTel->text().toUTF8()).toUTF8(),Icon::Critical);
            return;
        }

    }

    std::uniform_int_distribution<int> d(1000, 9999);
    std::random_device rd1;
    verificationCode = std::to_string(d(rd1));

    QByteArray ar;

    ar.clear();

    QXmlStreamWriter stream(&ar);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    stream.writeStartElement("MainmsgBody");

    stream.writeTextElement("Command", "0");
    stream.writeTextElement("PlatformID", "1");
    stream.writeTextElement("ChannelCode", "474");
    stream.writeTextElement("UserName", "serikbel");
    stream.writeTextElement("PassWord", "nisan2012");
    stream.writeTextElement("Mesgbody", QString("Doğrulama Kodu: ") + verificationCode.c_str() + QString(" .Bu İsteği Siz Bulunmadıysanız Dikkate Almayınız"));
    stream.writeTextElement("Numbers", verifyTel->text().toUTF8().c_str());
    stream.writeTextElement("Type", "1");
    stream.writeTextElement("Concat", "1");
    stream.writeTextElement("Originator", "SERiK BLD");

    stream.writeEndElement();

    stream.writeEndDocument();

    auto httpclient = addChild(std::make_unique<Http::Client>());

    Http::Message msg;
    msg.setHeader("Content-Type","application/json");

    msg.addBodyText(ar.toStdString());

    httpclient->setSslCertificateVerificationEnabled(false);

    httpclient->done().connect([=](AsioWrapper::error_code code, Http::Message message){
        std::cout << "HTTP DONE: " << code.message().c_str() << message.body().c_str() << std::endl;

    });

    mDogrulabtn->setEnabled(true);
    verifyCode->setEnabled(true);
    startSignUpBtn->setEnabled(false);
    httpclient->post("http://processor.smsorigin.com/xml/process.aspx",msg);

}

void User::SignUpWidget::Save()
{
    if( verificationCode == verifyCode->text().toUTF8() )
    {
        auto doc = document{};
        try {
            int32_t yasint;
            bool conversation;
            yasint = QString::fromStdString(yas->text().toUTF8()).toInt(&conversation,10);
            if( conversation )
            {
                doc.append(kvp(DataBaseKeys::Userinfo::Ad,bsoncxx::types::b_utf8{ad->text().toUTF8().c_str()}));
                doc.append(kvp(DataBaseKeys::Userinfo::Soyad,bsoncxx::types::b_utf8{soyadi->text().toUTF8().c_str()}));
                doc.append(kvp(DataBaseKeys::Userinfo::Yas,bsoncxx::types::b_int32{yasint}));
                doc.append(kvp(DataBaseKeys::Userinfo::Tel,bsoncxx::types::b_utf8{verifyTel->text().toUTF8().c_str()}));
                doc.append(kvp(DataBaseKeys::Userinfo::Sifre,bsoncxx::types::b_utf8{Sifre->text().toUTF8().c_str()}));
                mongocxx::stdx::optional<mongocxx::result::insert_one> ins = Collection->insert_one(doc.view());
                if( ins )
                {
                    if( !ins.get().result().inserted_count() )
                    {
                        this->ShowMessageBox("HATA","Üyelik Kaydı Oluşturulamadı.");
                    }else{
//
                        auto messageBox = addChild(
                                    Wt::cpp14::make_unique<Wt::WMessageBox>
                                    ("Üyelik Kaydı",
                                     Wt::WString("Kaydınız Başarılı Bir Şekilde Oluşturuldu.\nGiriş Yapabilirsiniz"),
                                     Wt::Icon::Information, Wt::StandardButton::Ok));

                            messageBox->buttonClicked().connect([=] {
                                removeChild(messageBox);
                                mSuccessSignup.emit(NoClass());
                            });

                            messageBox->show();
                    }
                }
            }else{
                this->ShowMessageBox("HATA","Yaşınızı Hatalı Girdiniz",Icon::Critical);
            }
        } catch (bsoncxx::exception &e) {
            this->ShowMessageBox("HATA",WString("{1}").arg(e.what()).toUTF8(),Icon::Critical);
        }
    }else{
        this->ShowMessageBox("HATA",WString("Doğrulama Kodu Hatalı").toUTF8(),Icon::Critical);
    }
}

void User::SignUpWidget::ShowMessageBox(std::string title, std::string mesaj, Wt::Icon type)
{

    auto messageBox = addChild(
                Wt::cpp14::make_unique<Wt::WMessageBox>
                (title,
                 Wt::WString(mesaj),
                 type, Wt::StandardButton::Ok));

        messageBox->buttonClicked().connect([=] {
            removeChild(messageBox);
        });

        messageBox->show();

}



User::SigninWidget::SigninWidget(mongocxx::collection *_collection)
    :WContainerWidget(),Collection(_collection)
{

    setMargin(200,Side::Top);
    setContentAlignment(AlignmentFlag::Center);
    auto mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->setMaximumSize(500,WLength::Auto);



    mMainContainer->setAttributeValue(Style::style,Style::Border::border("1px solid white")+Style::Border::borderRardius("20","20","20","20"));
    auto layout = mMainContainer->setLayout(cpp14::make_unique<WVBoxLayout>());
    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto text = _layout->addWidget(cpp14::make_unique<WText>("Giriş"),0,AlignmentFlag::Center);
        text->setAttributeValue(Style::style,Style::color::rgb("255,255,255"));
    }

    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto _layout = container->setLayout(cpp14::make_unique<WGridLayout>());

        {
            auto text = _layout->addWidget(cpp14::make_unique<WText>("Telefon  "),0,0,AlignmentFlag::Center|AlignmentFlag::Middle);
            text->setAttributeValue(Style::style,Style::color::rgb("255,255,255"));
            tel = _layout->addWidget(cpp14::make_unique<WLineEdit>(),0,1,AlignmentFlag::Center);
            tel->setPlaceholderText("Telefon Numaranız (05321234567)");
        }
        {
            auto text = _layout->addWidget(cpp14::make_unique<WText>("Şifreniz  "),1,0,AlignmentFlag::Center|AlignmentFlag::Middle);
            text->setAttributeValue(Style::style,Style::color::rgb("255,255,255"));
            sifre = _layout->addWidget(cpp14::make_unique<WLineEdit>(),1,1,AlignmentFlag::Center);
            sifre->setPlaceholderText("Şifreniz");
            sifre->setEchoMode(EchoMode::Password);
        }

    }
    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto __layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto btn = __layout->addWidget(cpp14::make_unique<WPushButton>("Giriş"),0,AlignmentFlag::Center);
        btn->clicked().connect(this,&SigninWidget::Giris);
    }

    setMargin(200,Side::Bottom);

}

Signal<DataBaseKeys::Userinfo::User> &User::SigninWidget::mGetSiginSuccess()
{
    return this->mSigninSuccess;
}



void User::SigninWidget::Giris()
{
    auto filter = document{};
    try {
        filter.append(kvp(DataBaseKeys::Userinfo::Tel,bsoncxx::types::b_utf8{tel->text().toUTF8().c_str()}));
        filter.append(kvp(DataBaseKeys::Userinfo::Sifre,bsoncxx::types::b_utf8{sifre->text().toUTF8().c_str()}));
    } catch (bsoncxx::exception &e) {
        this->ShowMessageBox("HATA",WString("Filter Error: {1}").arg(e.what()).toUTF8(),Icon::Warning);
        return;
    }

    try {
        mongocxx::stdx::optional<bsoncxx::document::value> val = Collection->find_one(filter.view());
        if( val )
        {
            if( val.get().view()[DataBaseKeys::Userinfo::Tel].get_utf8().value.to_string() == tel->text().toUTF8() )
            {
                if( val.get().view()[DataBaseKeys::Userinfo::Sifre].get_utf8().value.to_string() == sifre->text().toUTF8() )
                {
                    auto messageBox = addChild(
                                Wt::cpp14::make_unique<Wt::WMessageBox>
                                ("Bilgi",
                                 Wt::WString(WString("Giriş Başarılı").toUTF8()),
                                 Icon::Information, Wt::StandardButton::Ok));
                        messageBox->buttonClicked().connect([=] {
                            removeChild(messageBox);
                            DataBaseKeys::Userinfo::User user;
                            user.ad = val.get().view()[DataBaseKeys::Userinfo::Ad].get_utf8().value.to_string();
                            user.soyad = val.get().view()[DataBaseKeys::Userinfo::Soyad].get_utf8().value.to_string();
                            user.tel = val.get().view()[DataBaseKeys::Userinfo::Tel].get_utf8().value.to_string();
                            mSigninSuccess.emit(user);
                        });
                        messageBox->show();
                }
            }
        }else{
            this->ShowMessageBox("HATA",WString("No Document!").toUTF8(),Icon::Warning);
        }
    } catch (mongocxx::exception &e) {
        this->ShowMessageBox("HATA",WString("Query Error: {1}").arg(e.what()).toUTF8(),Icon::Warning);
        return;
    }
}


void User::SigninWidget::ShowMessageBox(std::string title, std::string mesaj, Wt::Icon type)
{

    auto messageBox = addChild(
                Wt::cpp14::make_unique<Wt::WMessageBox>
                (title,
                 Wt::WString(mesaj),
                 type, Wt::StandardButton::Ok));

        messageBox->buttonClicked().connect([=] {
            removeChild(messageBox);
        });

        messageBox->show();

}
