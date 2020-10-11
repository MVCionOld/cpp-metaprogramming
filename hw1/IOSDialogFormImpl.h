//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_IOSDIALOGFORMIMPL_H
#define HW1_IOSDIALOGFORMIMPL_H

#include <iostream>

#include "DialogFormImpl.h"


class IOSDialogFormImpl : public DialogFormImpl {
public:
    void AttachToUserActivity() override;

    void Show() override;
};


#endif //HW1_IOSDIALOGFORMIMPL_H
