//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_DIALOGFORM_H
#define HW1_DIALOGFORM_H

#include "DialogFormImpl.h"

class DialogForm {
public:
    ~DialogForm();

    void SetDialogFormImpl(DialogFormImpl *pDialogFormImpl);

    void SetMessageBody(const std::string &msgBody);

    void SetMessageTitle(const std::string &msgTitle);

    void Show();

private:
    DialogFormImpl *pDialogFormImpl_{nullptr};
};


#endif //HW1_DIALOGFORM_H
