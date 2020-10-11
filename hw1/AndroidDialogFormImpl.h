//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_ANDROIDDIALOGFORMIMPL_H
#define HW1_ANDROIDDIALOGFORMIMPL_H

#include <iostream>

#include "DialogFormImpl.h"


class AndroidDialogFormImpl : public DialogFormImpl {
public:
    void AttachToUserActivity() override;

    void Show() override;
};


#endif //HW1_ANDROIDDIALOGFORMIMPL_H
