#include "mainapplication.h"



#include "databasekeys.h"


MainApplication::MainApplication(const Wt::WEnvironment &env)
    :WApplication(env),whChanged(this,"whChanged"),_OrientationChanged(this,"_OrientationChanged"),
      _PixelRatio(this,"_PixelRatio")
{

    try {
        mClient = new mongocxx::client(mongocxx::uri("mongodb://spor:Aa<05358564091@192.168.0.215:27018/?authSource=SerikSpor"));
    } catch (mongocxx::exception& e) {
        con << "MongoDB Connection Error: " << e.what() << std::endl;
    }

    db = mClient->database(DataBaseKeys::DataBase::SerikSpor);

    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();

    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);

    p_wtTheme.get()->setResponsive(true);

    Wt::WApplication::instance()->setTheme(p_wtTheme);

    Wt::WApplication::instance()->setTitle("Serik BelediyeSpor Resmi Web Sayfası");

    WApplication::useStyleSheet(WLink("css/mainPage.css"));
    WApplication::useStyleSheet(WLink("css/Kategoriler.css"));
    WApplication::useStyleSheet(WLink("css/test.css")); // Remove After Released

    Wt::WApplication::instance()->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");

    Wt::WApplication::instance()->setBodyClass("introMain");


    WApplication::instance()->addMetaHeader("viewport","width=device-width, initial-scale=1.0");

    this->init();
    Wt::WApplication::require("script/script.js");

}

void MainApplication::init()
{
    root()->clear();


    header = root()->addWidget(cpp14::make_unique<Header::Header>());
    body = root()->addWidget(cpp14::make_unique<Body::Body>(&db));
    footer = root()->addWidget(cpp14::make_unique<Footer::Footer>());

    header->mGetAnaSayfa().connect(body,&Body::Body::initBody);
    header->mGetKategoriler().connect(body,&Body::Body::initKategoriler);
    header->mGetTaraftar().connect(body,&Body::Body::initTaraftar);
    header->mGetOkullar().connect(body,&Body::Body::initOkullar);
    header->mGetStore().connect(body,&Body::Body::initStore);
    header->mGetTesis().connect(body,&Body::Body::initTesis);
    header->mGetHakkimizda().connect(body,&Body::Body::initHakkimizda);
    header->mGetKupalar().connect(body,&Body::Body::initKupalar);
    header->mGetKurumsal().connect(body,&Body::Body::initKurumsal);
    header->mGetBasin().connect(body,&Body::Body::initBasin);
    header->mGetSignUp().connect(body,&Body::Body::initSignUp);
    header->mGetSignIn().connect(body,&Body::Body::initSignIn);

    body->mGetSiginSuccess().connect(header,&Header::Header::UserId);





    auto device0 = root()->addWidget(cpp14::make_unique<WText>("col-lg--->"));
    auto device1 = root()->addWidget(cpp14::make_unique<WText>("col-md--->"));
    auto device2 = root()->addWidget(cpp14::make_unique<WText>("col-sm--->"));
    auto device3 = root()->addWidget(cpp14::make_unique<WText>("col-ssm--->"));
    auto device4 = root()->addWidget(cpp14::make_unique<WText>("col-xs--->"));

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

void MainApplication::f_Scrolled(WScrollEvent event)
{

    std::cout << event.scrollX() << event.scrollY() << std::endl;

}
