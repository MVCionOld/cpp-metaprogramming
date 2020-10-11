//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_OVERSCREENDIALOGFORMBUILDER_H
#define HW1_OVERSCREENDIALOGFORMBUILDER_H

#include "DialogFormBuilder.h"


class OverscreenDialogFormBuilder : public DialogFormBuilder {
public:
    DialogFormBuilder &CreateDialogFormImpl() override;
};


#endif //HW1_OVERSCREENDIALOGFORMBUILDER_H
