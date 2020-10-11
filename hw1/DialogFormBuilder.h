//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_DIALOGFORMBUILDER_H
#define HW1_DIALOGFORMBUILDER_H

#include "DialogFormImpl.h"
#include "DialogFormBuilder.h"

#ifdef IOS

#include "IOSDialogFormImpl.h"

#elif ANDROID
#include "AndroidDialogFormImpl.h"
#elif HARMONYOS
#include "HarmonyOSDialogFormImpl.h"
#endif


class DialogFormBuilder {
protected:
    DialogFormImpl *pDialogFormImpl_;
public:
    DialogFormBuilder() : pDialogFormImpl_(nullptr) {}

    ~DialogFormBuilder();

    DialogFormBuilder &SetUpStyleSheetDef(const StyleSheetDefinition &sSDef);

    virtual DialogFormBuilder &CreateDialogFormImpl();

    virtual DialogFormBuilder &AttachToUserActivity();

    virtual DialogFormImpl *GetDialogFormImp();
};


#endif //HW1_DIALOGFORMBUILDER_H
