//
// Created by twome on 10/05/2020.
//

#include "Dialog.h"
#include "../CrystalUI.h"

Dialog::Dialog(const std::string &id) : Screen(id) {}

void Dialog::close() {
    CrystalUI::get_instance()->get_gui_renderer()->show_dialog(nullptr);
}
