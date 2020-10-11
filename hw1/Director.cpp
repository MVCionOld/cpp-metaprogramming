//
// Created by mvcibuntu on 11.10.2020.
//

#include "Director.h"


DialogForm *Director::CreateDialogForm(
        DialogFormBuilder &builder,
        const StyleSheetDefinition &sSDef
) {
    auto *dialogForm = new DialogForm;
    DialogFormImpl *dialogFormImpl = builder
            .CreateDialogFormImpl()
            .SetUpStyleSheetDef(/*sSDef=*/sSDef)
            .AttachToUserActivity()
            .GetDialogFormImp();
    dialogForm->SetDialogFormImpl(dialogFormImpl);
    return dialogForm;
}
