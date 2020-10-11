#include "AlertDialogFormBuilder.h"
#include "DialogFormImpl.h"
#include "Director.h"
#include "NavbarDialogFormBuilder.h"
#include "OverscreenDialogFormBuilder.h"
#include "StyleSheetDefinition.h"


int main() {

    Director dialogFormDirector;

    AlertDialogFormBuilder alertDialogFormBuilder;
    NavbarDialogFormBuilder navbarDialogFormBuilder;
    OverscreenDialogFormBuilder overscreenDialogFormBuilder;

    StyleSheetDefinition alertStyleSheetDefinition;
    StyleSheetDefinition navbarStyleSheetDefinition;
    StyleSheetDefinition overscreenStyleSheetDefinition;

    DialogForm *alertDialogForm = dialogFormDirector.CreateDialogForm(
            /*builder=*/alertDialogFormBuilder,
            /*sSDef=*/alertStyleSheetDefinition
    );
    DialogForm *navbarDialogForm = dialogFormDirector.CreateDialogForm(
            /*builder=*/navbarDialogFormBuilder,
            /*sSDef=*/navbarStyleSheetDefinition
    );
    DialogForm *overscreenDialogForm = dialogFormDirector.CreateDialogForm(
            /*builder=*/overscreenDialogFormBuilder,
            /*sSDef=*/overscreenStyleSheetDefinition
    );

    std::cout << std::endl;

    alertDialogForm->SetMessageTitle(/*msgTitle=*/"Title \"Alert\" ");
    alertDialogForm->SetMessageBody(/*msgBody=*/"message");
    alertDialogForm->Show();

    std::cout << std::endl;

    navbarDialogForm->SetMessageTitle(/*msgTitle=*/"Title \"Navbar\" ");
    navbarDialogForm->SetMessageBody(/*msgBody=*/"message");
    navbarDialogForm->Show();

    std::cout << std::endl;

    overscreenDialogForm->SetMessageTitle(/*msgTitle=*/"Title \"Overscreen\" ");
    overscreenDialogForm->SetMessageBody(/*msgBody=*/"message");
    overscreenDialogForm->Show();

    return 0;
}









