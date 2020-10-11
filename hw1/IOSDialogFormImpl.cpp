//
// Created by mvcibuntu on 11.10.2020.
//

#include "IOSDialogFormImpl.h"


void IOSDialogFormImpl::AttachToUserActivity() {
    std::cout << "Apple Iphone DialogFormImpl attached" << std::endl;
}

void IOSDialogFormImpl::Show() {
    std::cout << "[ISO Mobile Device]"
              << std::endl
              << "\"" << this->msgTitle_ << "\""
              << std::endl
              << "->" << this->msgBody_ << "<-"
              << std::endl;
}
