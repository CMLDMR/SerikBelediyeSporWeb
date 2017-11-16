#include "mainapplication.h"

MainApplication::MainApplication(const Wt::WEnvironment &env)
    :WApplication(env),whChanged(this,"whChanged"),_OrientationChanged(this,"_OrientationChanged"),
      _PixelRatio(this,"_PixelRatio")

{



    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();
    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);
    p_wtTheme.get()->setResponsive(true);
    Wt::WApplication::instance()->setTheme(p_wtTheme);
    Wt::WApplication::instance()->setTitle("Mogat Official Page");

    WApplication::useStyleSheet(WLink("css/mainPage.css"));

    Wt::WApplication::instance()->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");

    Wt::WApplication::instance()->setBodyClass("introMain");

//    std::cout << "instance id: " << Wt::WApplication::instance()->id() << std::endl;

//    root()->addStyleClass("borderLine");



    WApplication::instance()->addMetaHeader("viewport","width=device.width, initial-scale=1.0");


    this->initMogat();


//    this->getDimensionfBrowser();


//    this->OrientationChanged().connect(this,&MainApplication::getDimensionfBrowser);

//    root()->doJavaScript("window.addEventListener(\"orientationchange\",function(){" + _OrientationChanged.createCall({"4"}) + "},false);");



}

void MainApplication::initMogat()
{
    root()->clear();
    root()->addWidget(Wt::cpp14::make_unique<Singleton>(this->viewPortWidth,this->viewPortHeight,viewPortPixelRatio));
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
    this->initMogat();

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
