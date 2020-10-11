//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_NAVBARDIALOGFORMBUILDER_H
#define HW1_NAVBARDIALOGFORMBUILDER_H

#include "DialogFormBuilder.h"


class NavbarDialogFormBuilder : public DialogFormBuilder {
public:
    DialogFormBuilder &CreateDialogFormImpl() override;
};


#endif //HW1_NAVBARDIALOGFORMBUILDER_H
