//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_DIRECTOR_H
#define HW1_DIRECTOR_H

#include "DialogForm.h"
#include "DialogFormBuilder.h"


class Director {
public:
    DialogForm *CreateDialogForm(DialogFormBuilder &builder, const StyleSheetDefinition &sSDef);
};


#endif //HW1_DIRECTOR_H
