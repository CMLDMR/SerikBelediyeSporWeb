#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H



#include <Necessary>

using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;


using namespace Wt;


class ContentPage;
class HaberlerPage;
class StorePage;
class FikturPage;
class Footer;


namespace Okullar {
    class SporOkullariWidget;
}


namespace Taraftar{
    class TaraftarPage;
};

namespace FotoVideo {
    class FotoVideoWidget;
};


namespace Medya {
    class MedyaWidget;
    class MedyaPage;
};

#define con std::cout

///
/// \brief The MainApplication class
/// This is Web Application Server. Contruct and Manage Page. Deliver the some neccessary variabla from platform or host
class MainApplication : public WApplication
{
public:
    MainApplication(const WEnvironment& env);


    ///
    /// \brief start initializing www.serikbelediyesi.com
    ///
    void init();

    ///
    /// \brief ViewPortDimension
    /// \return
    /// Emit Signal that captured browserviewport Dimensions like Width and Height.
    JSignal<int,int,double>& ViewPortDimension();



    ///
    /// \brief OrientationChanged
    /// \return
    /// emit if orientation changed page
    JSignal<int>& OrientationChanged();


    ///
    /// \brief PixelRatio
    /// \return
    /// detect device pixel ratio
    JSignal<float>& PixelRatio();


    ///
    /// \brief f_whChanged
    /// \param w
    /// \param h
    /// Slot for Capturing Dimension of the Browser.
    void f_whChanged(int w, int h, double r);


    ///
    /// \brief run Javascript code for get browser dimension
    ///
    void getDimensionfBrowser();


    ///
    /// \brief f_OrientationChanged
    /// Get Orientation changed in screen
    void f_OrientationChanged();



    ///
    /// \brief Sayfa Scroll Edildiği Zaman Signal ile Tetiklenen Function
    /// \param event
    ///
    void f_Scrolled(WScrollEvent event);




private:


    mongocxx::client* mClient;

    mongocxx::database db;


    ///
    /// \brief p_wtTheme
    /// Bootstrap Theme
    std::shared_ptr<Wt::WBootstrapTheme> p_wtTheme;


    int viewPortWidth, viewPortHeight;
    double viewPortPixelRatio;

    JSignal<int,int, double> whChanged;

    JSignal<int> _OrientationChanged;

    JSignal<float> _PixelRatio;


    ///
    /// \brief mMainPage
    ///
    ContentPage* mMainPage;

    ///
    /// \brief mHaberlerPage
    ///
    HaberlerPage* mHaberlerPage;

    ///
    /// \brief mStorePage
    /// Mağaza
    StorePage* mStorePage;



    ///
    /// \brief mFiksturPage
    ///
    FikturPage* mFiksturPage;


    ///
    /// \brief Taraftar Sayfası ve İçeriği
    ///
    Taraftar::TaraftarPage* mTaraftarPage;


};

#endif // MAINAPPLICATION_H
