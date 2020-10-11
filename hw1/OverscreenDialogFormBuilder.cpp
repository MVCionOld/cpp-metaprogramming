//
// Created by mvcibuntu on 11.10.2020.
//

#include "OverscreenDialogFormBuilder.h"


DialogFormBuilder &OverscreenDialogFormBuilder::CreateDialogFormImpl() {
    DialogFormBuilder::CreateDialogFormImpl();
    this->pDialogFormImpl_->SetAutoExpirationMSec(/*autoExpirationMSec=*/-1);
    this->pDialogFormImpl_->SetVibrateToNotify(/*vibrateToNotify=*/false);
    return *this;
}
