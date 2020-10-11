//
// Created by mvcibuntu on 11.10.2020.
//

#include "HarmonyOSDialogFormImpl.h"


void HarmonyOSDialogFormImpl::AttachToUserActivity() {
    std::cout << "Huawei Phone DialogFormImpl attached" << std::endl;
}

void HarmonyOSDialogFormImpl::Show() {
    std::cout << "[Huawei Phone Device]"
              << std::endl
              << "\"" << this->msgTitle_ << "\""
              << std::endl
              << "->" << this->msgBody_ << "<-"
              << std::endl;
}
