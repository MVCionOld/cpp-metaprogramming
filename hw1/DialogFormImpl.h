//
// Created by mvcibuntu on 11.10.2020.
//

#ifndef HW1_DIALOGFORMIMPL_H
#define HW1_DIALOGFORMIMPL_H

#include "iostream"
#include <string>

#include "StyleSheetDefinition.h"


class DialogFormImpl {
public:
    virtual void Show() = 0;

    virtual void AttachToUserActivity() = 0;

    void SetAutoExpirationMSec(int autoExpirationMSec);

    void SetVibrateToNotify(bool vibrateToNotify);

    void SetMessageBody(const std::string &msgBody);

    void SetMessageTitle(const std::string &msgTitle);

    void SetStyleSheet(const StyleSheetDefinition &sSDef);

protected:
    int autoExpirationMSec_{-1};
    bool vibrateToNotify_{false};
    std::string msgTitle_;
    std::string msgBody_;
    StyleSheetDefinition sSDef_;
};


#endif //HW1_DIALOGFORMIMPL_H
