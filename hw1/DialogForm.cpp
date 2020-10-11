//
// Created by mvcibuntu on 11.10.2020.
//

#include "DialogForm.h"

DialogForm::~DialogForm() {
    delete pDialogFormImpl_;
}

void DialogForm::SetDialogFormImpl(DialogFormImpl *pDialogFormImpl) {
    this->pDialogFormImpl_ = pDialogFormImpl;
}

void DialogForm::SetMessageBody(const std::string &msgBody) {
    this->pDialogFormImpl_->SetMessageBody(msgBody);
}

void DialogForm::SetMessageTitle(const std::string &msgTitle) {
    this->pDialogFormImpl_->SetMessageTitle(msgTitle);
}

void DialogForm::Show() {
    this->pDialogFormImpl_->Show();
}
