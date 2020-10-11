//
// Created by mvcibuntu on 11.10.2020.
//

#include "DialogFormBuilder.h"


DialogFormBuilder::~DialogFormBuilder() {
    delete pDialogFormImpl_;
}

DialogFormBuilder &DialogFormBuilder::SetUpStyleSheetDef(const StyleSheetDefinition &sSDef) {
    this->pDialogFormImpl_->SetStyleSheet(sSDef);
    return *this;
}

DialogFormBuilder &DialogFormBuilder::CreateDialogFormImpl() {
#ifdef IOS
    this->pDialogFormImpl_ = new IOSDialogFormImpl;
#elif ANDROID
    this->pDialogFormImpl_ = new AndroidDialogFormImpl;
#elif HARMONYOS
    this->pDialogFormImpl_ = new HarmonyOSDialogFormImpl;
#endif
    return *this;
}

DialogFormImpl *DialogFormBuilder::GetDialogFormImp() {
    return pDialogFormImpl_;
}

DialogFormBuilder &DialogFormBuilder::AttachToUserActivity() {
    pDialogFormImpl_->AttachToUserActivity();
    return *this;
}
