#include "haberlerpage.h"

HaberlerPage::HaberlerPage()
{
    addStyleClass("HaberlerPage");
    setContentAlignment(AlignmentFlag::Center);
    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass("row justify-content-md-justify");
    container->addStyleClass("pink");
//    container->setMaximumSize(1280,WLength::Auto);
    container->addWidget(cpp14::make_unique<LastHaber>())->addStyleClass("col-sm-4");
    container->addWidget(cpp14::make_unique<HaberList>())->addStyleClass("col-sm-8");


}

LastHaber::LastHaber()
{
    setContentAlignment(AlignmentFlag::Justify);
    addStyleClass("LastHaber green");
    addWidget(cpp14::make_unique<WText>("Last Haberasd asd asdf asdf asd"
                                        "f asdf asdf asdf asdf asdf as"
                                        "df asdf asdf asdf asdf asdf asdf "
                                        "asdf asdf asdf asdf asdf asdf asdf "
                                        "asdf asdf asdf asdf asdf asdf asdfa"
                                        "sdf asdf asdf asdf asdf"
                                        " asdf asdf asdf asdf asdf asdf asdf "
                                        "asdf asdf asdf sadf asdf asdf asdf"
                                        " asdf asdf asdf asdf asdf asdf asd"
                                        "f asdf asdf asdf asdf asdf asdf "
                                        "asdf asdf asdf asdf asdf asdf asdf "
                                        "asdf asdf sadfasdf asdf sadf asdf "
                                        "asdf asdf asdf sadfasd fasdf asdf "
                                        "asdf asdf asdf asdf asdf asdf asdf as"
                                        "df fdg sdfg sdfg sdfg sdfgsdfg sdfg sdfg sd"
                                        "sdfg sdfg sdfg sdfg sdfg sdfgsdg sdfg "
                                        "sdfg sdfg sdfg sdfg sdfg cxvb xcvb xcvb xcvb "
                                        "cxvb  sdf sdf sdf sdf sdf sd fsdf  sdf sdf "
                                        "xcvb xcvb cxvb xcvb sdf sdf sdf sdf df "
                                        " xcvb cxvb rdfghn fbn dfgh wesdf sdf sdf "
                                        "tryh wesdghdfghd fgh dfg sdf sdf sdf "
                                        "h ertyh ftgyhjn dfghn xdgba eryt hdfnhs"
                                        "ghdfbn srtg hjfghmj nb xcvbserty fghn xdg"
                                        "hb dcvbn xdgfh weryjhgfbn sdfvg hbdfhnmjrtyj xfcn xcv "
                                        "ndcvb dfgh ertyhje4rty hfnbdgfh bdsfgb cvbn fg"
                                        "n dfnbv xdfgh sdgh"));


}

HaberList::HaberList()
{
    addStyleClass("HaberList");

    auto container1 = addWidget(cpp14::make_unique<WContainerWidget>());
    container1->addStyleClass("row pink");
    container1->addWidget(cpp14::make_unique<HaberWidget>())->addStyleClass("col-sm-4 orange");
    container1->addWidget(cpp14::make_unique<HaberWidget>())->addStyleClass("col-sm-4 orange");
    container1->addWidget(cpp14::make_unique<HaberWidget>())->addStyleClass("col-sm-4 orange");

    auto container2 = addWidget(cpp14::make_unique<WContainerWidget>());
    container2->addStyleClass("row");
    container2->addWidget(cpp14::make_unique<HaberWidget>())->addStyleClass("col-sm-4 red");
    container2->addWidget(cpp14::make_unique<HaberWidget>())->addStyleClass("col-sm-4 red");
    container2->addWidget(cpp14::make_unique<HaberWidget>())->addStyleClass("col-sm-4 red");


}
//317170 43 TL
HaberWidget::HaberWidget(std::string str)
{
    addStyleClass("HaberWidget");
    addWidget(cpp14::make_unique<WText>(str));
}
