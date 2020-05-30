//
// Created by twome on 10/05/2020.
//

#ifndef CRYSTALUI_DIALOG_H
#define CRYSTALUI_DIALOG_H


#include "Screen.h"

class Dialog : public Screen {
public:
    Dialog(const std::string &id);

    void close();
};


#endif //CRYSTALUI_DIALOG_H
