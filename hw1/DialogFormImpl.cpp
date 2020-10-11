//
// Created by mvcibuntu on 11.10.2020.
//

#include "DialogFormImpl.h"


void DialogFormImpl::SetAutoExpirationMSec(int autoExpirationMSec) {
    this->autoExpirationMSec_ = autoExpirationMSec;
}

void DialogFormImpl::SetVibrateToNotify(bool vibrateToNotify) {
    this->vibrateToNotify_ = vibrateToNotify;
}

void DialogFormImpl::SetMessageBody(const std::string &msgBody) {
    this->msgBody_ = msgBody;
}

void DialogFormImpl::SetMessageTitle(const std::string &msgTitle) {
    this->msgTitle_ = msgTitle;
}

void DialogFormImpl::SetStyleSheet(const StyleSheetDefinition &sSDef) {
    this->sSDef_ = sSDef;
}
