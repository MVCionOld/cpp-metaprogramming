//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_HARMONYOSDIALOGFORMIMPL_H
#define HW1_HARMONYOSDIALOGFORMIMPL_H

#include <iostream>

#include "DialogFormImpl.h"


class HarmonyOSDialogFormImpl : public DialogFormImpl {
public:
    void AttachToUserActivity() override;

    void Show() override;
};


#endif //HW1_HARMONYOSDIALOGFORMIMPL_H
