#ifndef HEADER_H
#define HEADER_H

#include <QtCore/qglobal.h>

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WMenu.h>
#include <Wt/WMenuItem.h>
#include <Wt/WPopupMenu.h>
#include <Wt/WPopupMenuItem.h>
#include <Wt/WMessageBox.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WToolBar.h>
#include <Wt/WPushButton.h>
#include <Wt/WSignal.h>


#include "databasekeys.h"
#include "bootstrap.h"


using namespace Wt;


namespace Header {
    class Header : public WContainerWidget
    {
    public:
        Header();


            void fLoadMenu();

            Signal<NoClass> &mGetAnaSayfa();
            Signal<NoClass> &mGetKategoriler();
            Signal<NoClass> &mGetTaraftar();
            Signal<NoClass> &mGetOkullar();
            Signal<NoClass> &mGetStore();
            Signal<NoClass> &mGetTesis();
            Signal<NoClass> &mGetHakkimizda();
            Signal<NoClass> &mGetKupalar();
            Signal<NoClass> &mGetKurumsal();
            Signal<NoClass> &mGetBasin();
            Signal<NoClass> &mGetSignUp();
            Signal<NoClass> &mGetSignIn();



    private:

        Wt::WNavigationBar *navigation;

        Signal<NoClass> mAnaSayfa;
        Signal<NoClass> mKategoriSignal;
        Signal<NoClass> mTaraftarSignal;
        Signal<NoClass> mOkullarSignal;

        Signal<NoClass> mStoreSignal;
        Signal<NoClass> mTesislerimiz;
        Signal<NoClass> mHakkimizda;

        Signal<NoClass> mKupalar;
        Signal<NoClass> mKurumsal;
        Signal<NoClass> mBasin;

        Signal<NoClass> mSignUp;
        Signal<NoClass> mSignin;


    };


}


#endif // HEADER_H
