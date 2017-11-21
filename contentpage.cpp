#include "contentpage.h"

ContentPage::ContentPage()
{
    addStyleClass("content");
    setContentAlignment(AlignmentFlag::Center);
    mLayout = setLayout(cpp14::make_unique<WVBoxLayout>());

}

WVBoxLayout *ContentPage::getContentLayout()
{

    return mLayout;

}
