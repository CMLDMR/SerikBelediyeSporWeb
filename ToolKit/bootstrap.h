#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H


#include <string.h>
#include <iostream>


namespace Bootstrap {

namespace Grid {
    static const std::string container {"container "};//                    fixed-width
    static const std::string container_fluid {"container-fluid "};//       full-width
    static const std::string row {"row "};//                                row
    namespace ExtraSmall {
        static const std::string col_xs_1 {"col-xs-1 "};//
        static const std::string col_xs_2 {"col-xs-2 "};//
        static const std::string col_xs_3 {"col-xs-3 "};//
        static const std::string col_xs_4 {"col-xs-4 "};//
        static const std::string col_xs_5 {"col-xs-5 "};//
        static const std::string col_xs_6 {"col-xs-6 "};//
        static const std::string col_xs_7 {"col-xs-7 "};//
        static const std::string col_xs_8 {"col-xs-8 "};//
        static const std::string col_xs_9 {"col-xs-9 "};//
        static const std::string col_xs_10 {"col-xs-10 "};//
        static const std::string col_xs_11 {"col-xs-11 "};//
        static const std::string col_xs_12 {"col-xs-12 "};//
    }

    namespace Small {
        static const std::string col_sm_1 {"col-sm-1 "};//
        static const std::string col_sm_2 {"col-sm-2 "};//
        static const std::string col_sm_3 {"col-sm-3 "};//
        static const std::string col_sm_4 {"col-sm-4 "};//
        static const std::string col_sm_5 {"col-sm-5 "};//
        static const std::string col_sm_6 {"col-sm-6 "};//
        static const std::string col_sm_7 {"col-sm-7 "};//
        static const std::string col_sm_8 {"col-sm-8 "};//
        static const std::string col_sm_9 {"col-sm-9 "};//
        static const std::string col_sm_10 {"col-sm-10 "};//
        static const std::string col_sm_11 {"col-sm-11 "};//
        static const std::string col_sm_12 {"col-sm-12 "};//
    }

    namespace Medium {
        static const std::string col_md_1 {"col-md-1 "};//
        static const std::string col_md_2 {"col-md-2 "};//
        static const std::string col_md_3 {"col-md-3 "};//
        static const std::string col_md_4 {"col-md-4 "};//
        static const std::string col_md_5 {"col-md-5 "};//
        static const std::string col_md_6 {"col-md-6 "};//
        static const std::string col_md_7 {"col-md-7 "};//
        static const std::string col_md_8 {"col-md-8 "};//
        static const std::string col_md_9 {"col-md-9 "};//
        static const std::string col_md_10 {"col-md-10 "};//
        static const std::string col_md_11 {"col-md-11 "};//
        static const std::string col_md_12 {"col-md-12 "};//
    }

    namespace Large {
        static const std::string col_lg_1 {"col-lg-1 "};//
        static const std::string col_lg_2 {"col-lg-2 "};//
        static const std::string col_lg_3 {"col-lg-3 "};//
        static const std::string col_lg_4 {"col-lg-4 "};//
        static const std::string col_lg_5 {"col-lg-5 "};//
        static const std::string col_lg_6 {"col-lg-6 "};//
        static const std::string col_lg_7 {"col-lg-7 "};//
        static const std::string col_lg_8 {"col-lg-8 "};//
        static const std::string col_lg_9 {"col-lg-9 "};//
        static const std::string col_lg_10 {"col-lg-10 "};//
        static const std::string col_lg_11 {"col-lg-11 "};//
        static const std::string col_lg_12 {"col-lg-12 "};//
    }
}


    namespace Typography {

        static const std::string lead{"lead "};//                            Make Paragraph stand out
        static const std::string small{"small "};//                          Indicates smaller text (set to 85% of the size of the parent)
        static const std::string text_left{"text-left "};//                  Indicates left-aligned text
        static const std::string text_center{"text-center "};//              Indicates center-aligned text
        static const std::string text_right{"text-right "};//                Indicates right-aligned text
        static const std::string text_justify{"text-justify "};//            Indicates justified text
        static const std::string text_nowrap{"text-nowrap "};//              Indicates no wrap text
        static const std::string text_lowercase{"text-lowercase "};//        Indicates lowercased text
        static const std::string text_uppercase{"text-uppercase "};//        Indicates uppercased text
        static const std::string text_capitalize{"text-capitalize "};//  	Indicates capitalized text
        static const std::string list_unstyled{"list-unstyled "};//          Removes the default list-style and left margin on list items (works on both <ul> and <ol>). This class only applies to immediate children list items (to remove the default list-style from any nested lists, apply this class to any nested lists as well)
        static const std::string initialism{"initialism "};//                Displays the text inside an <abbr> element in a slightly smaller font size
        static const std::string list_inline{"list-inline "};//              Places all list items on a single line
        static const std::string dl_horizontal{"dl-horizontal "};//          Lines up the terms (<dt>) and descriptions (<dd>) in <dl> elements side-by-side. Starts off like default <dl>s, but when the browser window expands, it will line up side-by-side
        static const std::string pre_scrollable{"pre-scrollable "};//        Makes a <pre> element scrollable

    }


    namespace Test {
        static const std::string red {"red "};//
        static const std::string orange {"orange "};//
        static const std::string blue {"blue "};//
        static const std::string pink {"pink "};//
        static const std::string green {"green "};//
        static const std::string border1px {"border1px "};//
        static const std::string margin10px {"margin10px "};
        static const std::string maxWidth150{"maxWidth150 "};
    }
}

#endif // BOOTSTRAP_H
