#include "fikturpage.h"

FikturPage::FikturPage()
{


    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::container+"Lavender ");
    container->setContentAlignment(AlignmentFlag::Center);

    container->addWidget(cpp14::make_unique<WText>("Fikstür"))->addStyleClass("Haberler");


    Wt::WTabWidget *tabW = container->addWidget(Wt::cpp14::make_unique<Wt::WTabWidget>());


    {
        WMenuItem* item = tabW->addTab(Wt::cpp14::make_unique<PuanDurumu>(),
                     "Puan Durumu", Wt::ContentLoading::Eager);

        item->addStyleClass(Bootstrap::Test::font16px + Bootstrap::Test::Color::white );
    }

    {
        WMenuItem* item = tabW->addTab(Wt::cpp14::make_unique<GelecekMaclar>(),
                     "Takvim", Wt::ContentLoading::Eager);

        item->addStyleClass(Bootstrap::Test::font16px + Bootstrap::Test::Color::white);
    }


//    {
//        WMenuItem* item = tabW->addTab(Wt::cpp14::make_unique<Wt::WTextArea>("Geçmişte Oynanan Maçlarla ilgili Detay."),
//                     "Geçmiş Müsabalar", Wt::ContentLoading::Eager);

//        item->addStyleClass(Bootstrap::Test::font16px + Bootstrap::Test::Color::white );
//    }

//    tabW->decorationStyle().setBackgroundColor(WColor(125,150,175));




//    tabW->addTab(Wt::cpp14::make_unique<Wt::WTextArea>("The contents of the tabs are pre-loaded in"
//                       " the browser to ensure swift switching."),
//                 "Preload", Wt::ContentLoading::Eager);
//    tabW->addTab(Wt::cpp14::make_unique<Wt::WTextArea>("You could change any other style attribute of the"
//                       " tab widget by modifying the style class."
//                       " The style class 'trhead' is applied to this tab."),
//                 "Style", Wt::ContentLoading::Eager)->setStyleClass("trhead");

//    Wt::WMenuItem *tab
//        = tabW->addTab(Wt::cpp14::make_unique<Wt::WTextArea>("You can close this tab"
//                         " by clicking on the close icon."),
//               "Close");
//    tab->setCloseable(true);

//    tabW->setStyleClass("tabwidget");






}

PuanDurumu::PuanDurumu()
{

    auto mainContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mainContainer->addStyleClass(Bootstrap::Grid::container_fluid);

    {
        auto container = mainContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::row);
        container->addWidget(cpp14::make_unique<PuanDurumu::item>(true));
    }





}

PuanDurumu::item::item(bool listtitle)
{

    setContentAlignment(AlignmentFlag::Justify);
    Wt::WTable *table = addWidget(std::make_unique<Wt::WTable>());
    table->addStyleClass("table form-inline table-bordered table-hover table-condensed table-striped");
    table->setHeaderCount(1);
    table->elementAt(0, 0)->addWidget(std::make_unique<Wt::WText>("Takım"));
    table->elementAt(0, 1)->addWidget(std::make_unique<Wt::WText>("O"));
    table->elementAt(0, 2)->addWidget(std::make_unique<Wt::WText>("G"));
    table->elementAt(0, 3)->addWidget(std::make_unique<Wt::WText>("B"));
    table->elementAt(0, 4)->addWidget(std::make_unique<Wt::WText>("M"));
    table->elementAt(0, 5)->addWidget(std::make_unique<Wt::WText>("A"));
    table->elementAt(0, 6)->addWidget(std::make_unique<Wt::WText>("Y"));
    table->elementAt(0, 7)->addWidget(std::make_unique<Wt::WText>("AV"));
    table->elementAt(0, 8)->addWidget(std::make_unique<Wt::WText>("P"));

    int row = 1;

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("SERIK BELEDIYE SPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("ISPARTA DAVRAZ SPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("SARAYÖNÜ BELEDİYESPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("KARAMAN BELEDİYESPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("MUT İDMAN YURDU BELEDİYE SPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("MANAVGAT BELEDİYESPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("MEDCEM SİLİFKE BELEDİYE SPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("KEPEZ BELEDİYESPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("AKŞEHİR SPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("ANAMUR BELEDİYESPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("BUCAK BELEDİYE OĞUZHANSPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("KONYA EREĞLİSPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("MANAVGATSPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("GÖLHİSARSPOR"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("9"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("1"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("0"));
    table->elementAt(row, 5)->addWidget(std::make_unique<Wt::WText>("27"));
    table->elementAt(row, 6)->addWidget(std::make_unique<Wt::WText>("8"));
    table->elementAt(row, 7)->addWidget(std::make_unique<Wt::WText>("19"));
    table->elementAt(row++, 8)->addWidget(std::make_unique<Wt::WText>("25"));


}

GelecekMaclar::GelecekMaclar()
{

    setContentAlignment(AlignmentFlag::Justify);
    Wt::WTable *table = addWidget(std::make_unique<Wt::WTable>());
    table->addStyleClass("table form-inline table-bordered table-hover table-condensed table-striped");
    table->setHeaderCount(1);
    table->elementAt(0, 0)->addWidget(std::make_unique<Wt::WText>("Tarih"));
    table->elementAt(0, 1)->addWidget(std::make_unique<Wt::WText>("Ev Sahibi"));
    table->elementAt(0, 2)->addWidget(std::make_unique<Wt::WText>("Skor"));
    table->elementAt(0, 3)->addWidget(std::make_unique<Wt::WText>("Misafir"));
    table->elementAt(0, 4)->addWidget(std::make_unique<Wt::WText>("Hafta"));
    table->elementAt(0, 5)->addWidget(std::make_unique<Wt::WText>("Adres"));

    int row = 1;

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("17/10/2017"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("Serik BelediyeSpor"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("* - *"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("Kepez Belediye Spor"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("3. Hafta"));
    table->elementAt(row++, 5)->addWidget(std::make_unique<Wt::WText>("İsmail Oğan Stadyumu Serik/Antalya"));

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("17/10/2017"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("Serik BelediyeSpor"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("* - *"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("Kepez Belediye Spor"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("3. Hafta"));
    table->elementAt(row++, 5)->addWidget(std::make_unique<Wt::WText>("İsmail Oğan Stadyumu Serik/Antalya"));

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("17/10/2017"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("Serik BelediyeSpor"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("* - *"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("Kepez Belediye Spor"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("3. Hafta"));
    table->elementAt(row++, 5)->addWidget(std::make_unique<Wt::WText>("İsmail Oğan Stadyumu Serik/Antalya"));

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("17/10/2017"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("Serik BelediyeSpor"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("* - *"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("Kepez Belediye Spor"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("3. Hafta"));
    table->elementAt(row++, 5)->addWidget(std::make_unique<Wt::WText>("İsmail Oğan Stadyumu Serik/Antalya"));

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("17/10/2017"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("Serik BelediyeSpor"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("* - *"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("Kepez Belediye Spor"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("3. Hafta"));
    table->elementAt(row++, 5)->addWidget(std::make_unique<Wt::WText>("İsmail Oğan Stadyumu Serik/Antalya"));

    table->elementAt(row, 0)->addWidget(std::make_unique<Wt::WText>("17/10/2017"));
    table->elementAt(row, 1)->addWidget(std::make_unique<Wt::WText>("Serik BelediyeSpor"));
    table->elementAt(row, 2)->addWidget(std::make_unique<Wt::WText>("* - *"));
    table->elementAt(row, 3)->addWidget(std::make_unique<Wt::WText>("Kepez Belediye Spor"));
    table->elementAt(row, 4)->addWidget(std::make_unique<Wt::WText>("3. Hafta"));
    table->elementAt(row++, 5)->addWidget(std::make_unique<Wt::WText>("İsmail Oğan Stadyumu Serik/Antalya"));
}
