#include "mainapplication.h"


///https://www.flaticon.com/packs/essential-collection
/// https://codepen.io/asfarmed/pen/cfslr

int main(int argc, char *argv[])
{
    return Wt::WRun(argc,argv,[](const Wt::WEnvironment &env){
        return Wt::cpp14::make_unique<MainApplication>(env);
    });
}
