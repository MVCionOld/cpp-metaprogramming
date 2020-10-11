//
// Created by mvcibuntu on 11.10.2020.
//

#include "AndroidDialogFormImpl.h"


void AndroidDialogFormImpl::AttachToUserActivity() {
    std::cout << "Andoid DialogFormImpl attached" << std::endl;
}

void AndroidDialogFormImpl::Show() {
    std::cout << "[Android Mobile Device]"
              << std::endl
              << "\"" << this->msgTitle_ << "\""
              << std::endl
              << "->" << this->msgBody_ << "<-"
              << std::endl;
}
