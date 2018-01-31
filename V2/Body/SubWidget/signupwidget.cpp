#include "signupwidget.h"



User::SignUpWidget::SignUpWidget()
    :WContainerWidget()
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
        auto text2 = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),0,1,AlignmentFlag::Left);
        text2->setPlaceholderText("Adınızı Giriniz");
    }

    {
        auto text1 = gridLayout->addWidget(cpp14::make_unique<WText>("Soyadınızı"),1,0,AlignmentFlag::Center);
        text1->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        auto text2 = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),1,1,AlignmentFlag::Left);
        text2->setPlaceholderText("Soyadınızı Giriniz");
    }

    {
        auto text1 = gridLayout->addWidget(cpp14::make_unique<WText>("Cep Telefon"),2,0,AlignmentFlag::Center);
        text1->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        auto text2 = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),2,1,AlignmentFlag::Left);
        text2->setPlaceholderText("Telefon Numaranız - 05321234567");
    }

    {
        auto text1 = gridLayout->addWidget(cpp14::make_unique<WText>("Yaşınız"),3,0,AlignmentFlag::Center);
        text1->setAttributeValue(Style::style,Style::color::color(Style::color::White::White));
        auto text2 = gridLayout->addWidget(cpp14::make_unique<WLineEdit>(),3,1,AlignmentFlag::Left);
        text2->setPlaceholderText("Yaşınız");
    }


    {
        auto btnContainer = addWidget(cpp14::make_unique<WContainerWidget>());
        auto layout = btnContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto btn = layout->addWidget(cpp14::make_unique<WPushButton>("Üyeliği Başlat"),0,AlignmentFlag::Center);
    }

    {
        auto btnContainer = addWidget(cpp14::make_unique<WContainerWidget>());
        btnContainer->setMaximumSize(500,WLength::Auto);
        auto layout = btnContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto lineEdit = layout->addWidget(cpp14::make_unique<WLineEdit>(),0,AlignmentFlag::Center);
        lineEdit->setPlaceholderText("Cep Telefonunuza Gelen Doğrulama Kodunu Giriniz");
        lineEdit->setEnabled(false);
        auto btn = layout->addWidget(cpp14::make_unique<WPushButton>("Doğrula"),0,AlignmentFlag::Center);
        btn->setEnabled(false);
    }

    setMargin(150,Side::Bottom);

}



User::SigninWidget::SigninWidget()
    :WContainerWidget()
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
            auto lineEdit = _layout->addWidget(cpp14::make_unique<WLineEdit>(),0,1,AlignmentFlag::Center);
            lineEdit->setPlaceholderText("Telefon Numaranız (05321234567)");
        }
        {
            auto text = _layout->addWidget(cpp14::make_unique<WText>("Şifreniz  "),1,0,AlignmentFlag::Center|AlignmentFlag::Middle);
            text->setAttributeValue(Style::style,Style::color::rgb("255,255,255"));
            auto lineEdit = _layout->addWidget(cpp14::make_unique<WLineEdit>(),1,1,AlignmentFlag::Center);
            lineEdit->setPlaceholderText("Şifreniz");
        }

    }
    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        auto __layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        auto btn = __layout->addWidget(cpp14::make_unique<WPushButton>("Giriş"),0,AlignmentFlag::Center);
    }

    setMargin(200,Side::Bottom);

}
