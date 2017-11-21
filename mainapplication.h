#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H



#include <Necessary>




using namespace Wt;


class ContentPage;
class HaberlerPage;


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




private:


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


};

#endif // MAINAPPLICATION_H
