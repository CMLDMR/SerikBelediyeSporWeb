#include "hakkimizdawidget.h"

Hakkimizda::HakkimizdaWidget::HakkimizdaWidget()
    :WContainerWidget()
{

    addStyleClass(Bootstrap::Grid::container_fluid);

    auto mMainContainer = addWidget(cpp14::make_unique<WContainerWidget>());

    auto text = mMainContainer->addWidget(cpp14::make_unique<WText>("Hakkımızda"));

    text->setAttributeValue(Style::style,Style::color::color(Style::color::White::AliceBlue)+
                            Style::font::size::s20px);

}
