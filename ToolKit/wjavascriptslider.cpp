#include "wjavascriptslider.h"

WJavaScriptSlider::WJavaScriptSlider()
{
//    addStyleClass("headerback");

    auto mainLayout = setLayout(cpp14::make_unique<WHBoxLayout>());

    auto mainContainer = mainLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);


//    mainContainer->addStyleClass("scriptSlider");

    auto mLayout = mainContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

    imgcontainer = mLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify);

    dotContainer = mLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center);

    dotLayout = dotContainer->setLayout(cpp14::make_unique<WHBoxLayout>());

    appendimg("Reesim 1","sliders/1.jpg");

    appendimg("Reesim 2","sliders/2.jpg");

    appendimg("Reesim 3","sliders/3.jpg");

    appendimg("Reesim 4","sliders/4.jpg");

    doJavaScript("showSlides(\"0\")");

}

void WJavaScriptSlider::appendimg(std::string title, std::string link)
{

    auto container = imgcontainer->addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass("mySlides fade");
    container->setContentAlignment(AlignmentFlag::Center);


    auto subContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
    subContainer->setContentAlignment(AlignmentFlag::Center);

    auto layout = subContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

    auto img = layout->addWidget(cpp14::make_unique<WImage>(WLink(link)),0,AlignmentFlag::Center);
    img->addStyleClass("imgpos");

    layout->addWidget(cpp14::make_unique<WText>("Lorem Ipsum, dizgi ve baskı endüstrisinde kullanılan mıgır metinlerdir. Lorem Ipsum, adı bilinmeyen "));

    auto dot = dotLayout->addWidget(cpp14::make_unique<WText>(""),0,AlignmentFlag::Center);
    dot->addStyleClass("dot");

    imgItem item;

    item.link = link;
    item.title = title;
    item.widgetid = img->id();
    item.dotid = dot->id();
    imgList.push_back(item);

    dot->clicked().connect([=](){
        int i = 0 ;
        for( imgItem id : imgList )
        {
            if( id.dotid == dot->id() )
            {
                dot->doJavaScript(QString("currentSlide(%1)").arg(i).toStdString());
                break;
            }
            i++;
        }
    });

}
