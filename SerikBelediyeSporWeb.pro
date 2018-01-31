QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

CONFIG += no_keywords

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    mainapplication.cpp \
    main.cpp \
    mainapplication.cpp \
    frontpagewidget.cpp \
    ToolKit/wjavascriptslider.cpp \
    contentpage.cpp \
    src/haberlerpage.cpp \
    src/storepage.cpp \
    src/fikturpage.cpp \
    src/sporokullari.cpp \
    src/fotovideopage.cpp \
    src/basinpage.cpp \
    V2/Header/header.cpp \
    V2/Body/body.cpp \
    V2/Footer/footer.cpp \
    V2/Body/SubWidget/kategorilerwidget.cpp \
    V2/Body/SubWidget/taraftarwidget.cpp \
    V2/Body/SubWidget/okullarwidget.cpp \
    V2/Body/SubWidget/storewidget.cpp \
    V2/Body/SubWidget/tesislerimizwidget.cpp \
    V2/Body/SubWidget/hakkimizdawidget.cpp \
    V2/Body/SubWidget/kupalarwidget.cpp \
    V2/Body/SubWidget/kurumsalwidget.cpp \
    V2/Body/SubWidget/basinwidget.cpp \
    V2/Body/SubWidget/signupwidget.cpp

HEADERS += \
    mainapplication.h \
    mainapplication.h \
    frontpagewidget.h \
    ToolKit/wjavascriptslider.h \
    contentpage.h \
    src/haberlerpage.h \
    src/storepage.h \
    ToolKit/bootstrap.h \
    src/fikturpage.h \
    src/sporokullari.h \
    src/fotovideopage.h \
    src/basinpage.h \
    ../../Comman/databasekeys.h \
    ../../Comman/bootstrap.h \
    V2/Header/header.h \
    V2/Body/body.h \
    V2/Footer/footer.h \
    V2/Body/SubWidget/kategorilerwidget.h \
    V2/Body/SubWidget/taraftarwidget.h \
    V2/Body/SubWidget/okullarwidget.h \
    V2/Body/SubWidget/storewidget.h \
    V2/Body/SubWidget/tesislerimizwidget.h \
    ../../Comman/inlinestyle.h \
    V2/Body/SubWidget/hakkimizdawidget.h \
    V2/Body/SubWidget/kupalarwidget.h \
    V2/Body/SubWidget/kurumsalwidget.h \
    V2/Body/SubWidget/basinwidget.h \
    V2/Body/SubWidget/signupwidget.h




win32: LIBS += -L$$PWD/../../Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/lib/ -lwt

INCLUDEPATH += $$PWD/../../Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/include
DEPENDPATH += $$PWD/../../Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/include

INCLUDEPATH += $$PWD/../../Comman
DEPENDPATH += $$PWD/../../Comman

win32: LIBS += -L$$PWD/../../Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/lib/ -lwthttp

INCLUDEPATH += $$PWD/../../Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/include
DEPENDPATH += $$PWD/../../Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/include

DISTFILES += \
    approot/wt_config.xml \
    Necessary \
    ../build-SerikBelediyeSporWeb-Desktop_Qt_5_9_1_MSVC2015_64bit2-Release/docroot/css/mainPage.css \
    ../build-SerikBelediyeSporWeb-Desktop_Qt_5_9_1_MSVC2015_64bit2-Release/docroot/css/Kategoriler.css



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lbsoncxx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lbsoncxxd
else:unix: LIBS += -L$$PWD/lib/ -lbsoncxx

INCLUDEPATH += $$PWD/include/bsoncxx/v_noabi
DEPENDPATH += $$PWD/include/bsoncxx/v_noabi



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lmongocxx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lmongocxxd
else:unix: LIBS += -L$$PWD/lib/ -lmongocxx

INCLUDEPATH += $$PWD/include/mongocxx/v_noabi
DEPENDPATH += $$PWD/include/mongocxx/v_noabi


INCLUDEPATH += $$PWD/../../Boost/boost/
DEPENDPATH += $$PWD/../../Boost/boost/
