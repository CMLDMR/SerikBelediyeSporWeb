#ifndef FOOTER_H
#define FOOTER_H

#include <QtCore/qglobal.h>


#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WMenu.h>
#include <Wt/WMenuItem.h>
#include <Wt/WText.h>
#include <Wt/WBootstrapTheme.h>
#include <Wt/WPushButton.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WAnchor.h>
#include <Wt/WLink.h>




#include <vector>

using namespace Wt;


namespace FooterSpace {
    class Kurumsal;
    class Branslar;
    class Aktiviteler;
    class Okullar;

    class Footer : public WContainerWidget
    {
    public:
        Footer();
    };



    class Kurumsal : public WContainerWidget
    {
    public:
        Kurumsal();
    };


    class Branslar : public WContainerWidget
    {
    public:
        Branslar ();
    };



    class Aktiviteler : public WContainerWidget
    {
    public:
        Aktiviteler();
    };


    class Okullar : public WContainerWidget
    {
    public:
        Okullar();
    };


    class Arsiv : public WContainerWidget
    {
    public:
        Arsiv();
    };

    class Hakkimizda : public WContainerWidget
    {
    public:
        Hakkimizda();
    };
}



#endif // FOOTER_H
