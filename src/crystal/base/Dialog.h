//
// Created by twome on 10/05/2020.
//

#ifndef CRYSTALUI_DIALOG_H
#define CRYSTALUI_DIALOG_H


#include "Screen.h"

namespace crystal {
    class Dialog : public Screen {
    public:
        explicit Dialog(const std::string &id);

        void close();
    };
};

#endif //CRYSTALUI_DIALOG_H
