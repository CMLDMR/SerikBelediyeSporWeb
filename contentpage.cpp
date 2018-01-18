#include "contentpage.h"

ContentPage::ContentPage()
{
    setContentAlignment(AlignmentFlag::Center);
    this->initLayout();
}

WContainerWidget *ContentPage::getContentLayout()
{
    return mContentContainer;
}

WContainerWidget *ContentPage::getFooterLayout()
{
    return  mMainContainer;
}




void ContentPage::initLayout()
{
    mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());

    mMainContainer = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->setId("mMainContainer");

    mContentContainer = mLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    mContentContainer->setId("mContentContainer");
}



void ContentPage::setHaber(std::string oid)
{
    mMainContainer->clear();
    std::cout << "clear Layout : " << oid << std::endl;
}
