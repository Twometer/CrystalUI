//
// Created by twome on 08/05/2020.
//

#ifndef CRYSTALUI_PANEL_H
#define CRYSTALUI_PANEL_H


#include "../base/Container.h"
#include "../gl/Vao.h"
#include "../gl/MeshBuilder.h"

namespace crystal {
    class Panel : public Container {
    public:
        explicit Panel(const std::string &id);

        void draw(Graphics &graphics) override;

    };
}

#endif //CRYSTALUI_PANEL_H
