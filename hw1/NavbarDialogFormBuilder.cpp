//
// Created by mvcibuntu on 11.10.2020.
//

#include "NavbarDialogFormBuilder.h"


DialogFormBuilder &NavbarDialogFormBuilder::CreateDialogFormImpl() {
    DialogFormBuilder::CreateDialogFormImpl();
    this->pDialogFormImpl_->SetAutoExpirationMSec(/*autoExpirationMSec=*/10'000);
    this->pDialogFormImpl_->SetVibrateToNotify(/*vibrateToNotify=*/true);
    return *this;
}
