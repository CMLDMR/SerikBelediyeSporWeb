#include "mainapplication.h"

#include "contentpage.h"
#include "ToolKit/wjavascriptslider.h"
#include "src/haberlerpage.h"
#include "src/storepage.h"


MainApplication::MainApplication(const Wt::WEnvironment &env)
    :WApplication(env),whChanged(this,"whChanged"),_OrientationChanged(this,"_OrientationChanged"),
      _PixelRatio(this,"_PixelRatio")
{

    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();

    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);

    p_wtTheme.get()->setResponsive(true);

    Wt::WApplication::instance()->setTheme(p_wtTheme);

    Wt::WApplication::instance()->setTitle("Serik BelediyeSpor Resmi Web Sayfası");

    WApplication::useStyleSheet(WLink("css/mainPage.css"));
    WApplication::useStyleSheet(WLink("css/test.css"));

    Wt::WApplication::instance()->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");
    Wt::WApplication::require("script/script.js");

    Wt::WApplication::instance()->setBodyClass("introMain");

    WApplication::instance()->addMetaHeader("viewport","width=device.width, initial-scale=1.0");

    this->init();



}

void MainApplication::init()
{

    root()->clear();


    root()->addStyleClass("container-fluid");


    mMainPage = root()->addWidget(cpp14::make_unique<ContentPage>());

    mMainPage->getContentLayout()->setContentsMargins(0,0,0,0);

//    auto mLayout = root()->setLayout(cpp14::make_unique<WVBoxLayout>());




    {
        mMainPage->getContentLayout()->addWidget(cpp14::make_unique<FrontPageWidget>(),1,AlignmentFlag::Justify);
    }



//    root()->addWidget(cpp14::make_unique<WBreak>());
    mMainPage->getContentLayout()->addSpacing(50);
    {
        mHaberlerPage = mMainPage->getContentLayout()->addWidget(cpp14::make_unique<HaberlerPage>());
    }

//    root()->addWidget(cpp14::make_unique<WBreak>());
    mMainPage->getContentLayout()->addSpacing(50);
    {
        mStorePage = mMainPage->getContentLayout()->addWidget(cpp14::make_unique<StorePage>());
    }



//    mHaberlerPage->setWidth(WLength::Auto);






//    auto slider = mLayout->addWidget(cpp14::make_unique<WJavaScriptSlider>(),1,AlignmentFlag::Center);



    auto device0 = mMainPage->getContentLayout()->addWidget(cpp14::make_unique<WText>("col-lg--->"));
    auto device1 = mMainPage->getContentLayout()->addWidget(cpp14::make_unique<WText>("col-md--->"));
    auto device2 = mMainPage->getContentLayout()->addWidget(cpp14::make_unique<WText>("col-sm--->"));
    auto device3 = mMainPage->getContentLayout()->addWidget(cpp14::make_unique<WText>("col-sm--->"));
    auto device4 = mMainPage->getContentLayout()->addWidget(cpp14::make_unique<WText>("col-xs--->"));

    device0->addStyleClass("device0");
    device1->addStyleClass("device1");
    device2->addStyleClass("device2");
    device3->addStyleClass("device3");
    device4->addStyleClass("device4");

}

JSignal<int, int, double> &MainApplication::ViewPortDimension()
{
    return whChanged;
}

JSignal<int> &MainApplication::OrientationChanged()
{
    return _OrientationChanged;
}

JSignal<float> &MainApplication::PixelRatio()
{

    return _PixelRatio;
}

void MainApplication::f_whChanged(int w, int h, double r)
{

    std::cout << "W: " << w << " H: " << h << " R: " << r << std::endl;
    this->viewPortHeight = h;
    this->viewPortWidth = w;
    this->viewPortPixelRatio = r;
    this->init();

}

void MainApplication::getDimensionfBrowser()
{

    this->ViewPortDimension().connect(this,&MainApplication::f_whChanged);

    root()->doJavaScript(""
                         "var w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);"
                         "var h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);"
                         "var ratio = 1;"
                         "if( window.screen.systemXDPI !== undefined && window.screen.logicalXDPI !== undefined && window.screen.systemXDPI > window.screen.logicalXDPI) {"
                         "ratio = window.screen.systemXDPI / window.screen.logicalXDPI;"
                         "}"
                         "else if (window.devicePixelRatio !== undefined) {"
                         "ratio = window.devicePixelRatio;"
                         "}"
                         +whChanged.createCall({"w,h,ratio"})+
                         ";");


}

void MainApplication::f_OrientationChanged()
{

}
