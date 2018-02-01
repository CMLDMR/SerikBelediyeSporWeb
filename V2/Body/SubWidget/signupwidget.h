#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QtCore/qglobal.h>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QXmlStreamWriter>
#include <QByteArray>
#include <QFileInfo>

#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WBreak.h>
#include <Wt/WMenu.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WTextArea.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WGridLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>
#include <Wt/Http/Client.h>
#include <Wt/WMessageBox.h>


#include <random>


#include "bootstrap.h"
#include "databasekeys.h"
#include "inlinestyle.h"

#include "bsoncxx/builder/basic/document.hpp"
#include "bsoncxx/builder/basic/array.hpp"
#include "bsoncxx/builder/basic/kvp.hpp"
#include "bsoncxx/types.hpp"
#include "bsoncxx/document/value.hpp"
#include "bsoncxx/exception/exception.hpp"
#include "bsoncxx/json.hpp"
#include "bsoncxx/document/element.hpp"
#include <bsoncxx/stdx/make_unique.hpp>

#include "mongocxx/collection.hpp"
#include "mongocxx/exception/exception.hpp"



using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;


using namespace Wt;


namespace User {



    class SignUpWidget : public WContainerWidget
    {
    public:
        SignUpWidget(mongocxx::collection *_collection);

        Signal<NoClass> &mGetSuccessSignUp();

    private:
        mongocxx::collection *Collection;

        void sendVerificationCode();

        void Save();

        std::string verificationCode;

        WLineEdit* ad,*soyadi,*yas;

        void ShowMessageBox(std::string title, std::string mesaj, Icon type = Wt::Icon::Information);


        WLineEdit* verifyTel;
        WLineEdit* verifyCode;
        WLineEdit* Sifre;
        WPushButton* mDogrulabtn,*startSignUpBtn;

        Signal<NoClass> mSuccessSignup;
    };





    class SigninWidget : public WContainerWidget
    {
    public:
        SigninWidget(mongocxx::collection *_collection);

        Signal<DataBaseKeys::Userinfo::User> &mGetSiginSuccess();

    private:
        mongocxx::collection* Collection;

        Signal<DataBaseKeys::Userinfo::User> mSigninSuccess;

        WLineEdit* tel, *sifre;

        void Giris();
        void ShowMessageBox(std::string title, std::string mesaj, Wt::Icon type = Icon::Information);
    };

}


#endif // SIGNUPWIDGET_H
