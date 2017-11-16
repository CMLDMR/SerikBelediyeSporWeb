#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H



#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WEnvironment.h>
#include <Wt/WJavaScript.h>

#include <Wt/WBootstrapTheme>




#include "singleton.h"

#include <iostream>
#include <memory>



using namespace Wt;

#include <QtCore/qglobal.h>

///
/// \brief The MainApplication class
/// This is Web Application Server. Contruct and Manage Page. Deliver the some neccessary variabla from platform or host
class MainApplication : public WApplication
{
public:
    MainApplication(const WEnvironment& env);


    ///
    /// \brief start initializing www.mogat.eu web.
    ///
    void initMogat();

    ///
    /// \brief ViewPortDimension
    /// \return
    /// Emit Signal that captured browserviewport Dimensions like Width and Height.
    JSignal<int,int,double>& ViewPortDimension();



    JSignal<int>& OrientationChanged();


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


};

#endif // MAINAPPLICATION_H
