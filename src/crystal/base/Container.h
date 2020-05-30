//
// Created by twome on 08/05/2020.
//

#ifndef CRYSTALUI_CONTAINER_H
#define CRYSTALUI_CONTAINER_H

#include <vector>
#include "Component.h"

namespace crystal {

/**
 * The Container is a special component that
 * implements a simple grid-based container for components
 */
    class Container : public Component {
    protected:
        std::vector<Component *> components;

        int rows = 1;
        int columns = 1;

    public:
        explicit Container(const std::string &id);

        void draw(Graphics &graphics) override;

        void layout() override;

        void set_rows(int r);

        void set_cols(int c);

        void add_component(Component *component);

        void on_mouse_down(glm::vec2 position) override;

        void on_mouse_up(glm::vec2 position) override;

        void on_mouse_move(glm::vec2 position) override;

        void on_character_typed(uint32_t codepoint) override;

        void on_key_event(int key, int action) override;

        // We have to define this method here instead of in the .cpp
        // because template functions have to be defined in the header
        // if we want to have ANY objects as template typename
        // See: https://stackoverflow.com/q/115703
        template<typename T>
        T *find_component(const std::string &id) const {
            for (auto component : components)
                if (component->get_id() == id)
                    return dynamic_cast<T *>(component);
                else if (auto container = dynamic_cast<Container *>(component)) {
                    Component *found = container->find_component<T>(id);
                    if (found != nullptr)
                        return dynamic_cast<T *>(found);
                }
            return nullptr;
        }

    private:
        Component *find_component(int row, int col) const;

        void build_rows(std::vector<float> &rowWidths) const;

        void build_cols(std::vector<float> &colHeights) const;

        inline glm::vec2 get_origin() const;
    };
}
#endif //CRYSTALUI_CONTAINER_H
