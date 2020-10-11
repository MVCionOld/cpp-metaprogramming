//
// Created by mvcibuntu on 11.10.2020.
//

#include "AlertDialogFormBuilder.h"


DialogFormBuilder &AlertDialogFormBuilder::CreateDialogFormImpl() {
    DialogFormBuilder::CreateDialogFormImpl();
    this->pDialogFormImpl_->SetAutoExpirationMSec(/*autoExpirationMSec=*/-1);
    this->pDialogFormImpl_->SetVibrateToNotify(/*vibrateToNotify=*/true);
    return *this;
}
