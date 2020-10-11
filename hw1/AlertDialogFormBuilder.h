//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_ALERTDIALOGFORMBUILDER_H
#define HW1_ALERTDIALOGFORMBUILDER_H

#include "DialogFormBuilder.h"


class AlertDialogFormBuilder : public DialogFormBuilder {
public:
    DialogFormBuilder &CreateDialogFormImpl() override;
};


#endif //HW1_ALERTDIALOGFORMBUILDER_H
