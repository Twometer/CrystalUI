//
// Created by twome on 08/05/2020.
//

#include <numeric>
#include "Container.h"
#include "../components/Button.h"
#include "../components/Label.h"

Container::Container(const std::string &id) : Component(id) {
}

void Container::draw(Graphics &graphics) {
    Graphics nextGraphics = graphics.create_offset(get_origin());
    for (auto component : components) {
        component->draw(nextGraphics);
    }
}

void Container::layout() {
    // Yay, grid layout engine :)
    std::vector<float> rowHeights;
    std::vector<float> colWidths;

    // First, run a layout pass on all child components
    // so that they have correct minimum sizes
    for (auto component : components) {
        component->layout();
    }

    // Compute row heights
    build_rows(rowHeights);

    // Compute column widths
    build_cols(colWidths);

    // Apply layout constraints
    for (auto component : components) {
        // Calculate position of the usable content area of the cell
        // This excludes the margin of the component within the cell
        float xCoord = std::accumulate(colWidths.begin(), colWidths.begin() + component->get_col(), 0.f) +
                       component->get_margin().x;
        float yCoord = std::accumulate(rowHeights.begin(), rowHeights.begin() + component->get_row(), 0.f) +
                       component->get_margin().y;

        // Calculate the size of the mentioned usable content area
        float cellWidth = std::accumulate(colWidths.begin() + component->get_col(),
                                          colWidths.begin() + component->get_col() + component->get_col_span(), 0.f) -
                          component->get_margin().x * 2;

        float cellHeight = std::accumulate(rowHeights.begin() + component->get_row(),
                                           rowHeights.begin() + component->get_row() + component->get_row_span(), 0.f) -
                           component->get_margin().y * 2;

        // Calculate component size based on whether it is set to fill the cell or not
        float width = component->get_horizontal_alignment() == Alignment::STRETCH ? cellWidth
                                                                                  : component->get_minimum_size().x;

        float height = component->get_vertical_alignment() == Alignment::STRETCH ? cellHeight
                                                                                   : component->get_minimum_size().y;

        // Account for CENTER and END alignments
        if (component->get_horizontal_alignment() == Alignment::CENTER) {
            xCoord += cellWidth / 2 - (component->get_minimum_size().x + component->get_margin().x * 2) / 2;
        } else if (component->get_horizontal_alignment() == Alignment::END) {
            xCoord += cellWidth - (component->get_minimum_size().x + component->get_margin().x * 2);
        }

        if (component->get_vertical_alignment() == Alignment::CENTER) {
            yCoord += cellHeight / 2 - (component->get_minimum_size().y + component->get_margin().y * 2) / 2;
        } else if (component->get_vertical_alignment() == Alignment::END) {
            yCoord += cellHeight - (component->get_minimum_size().y + component->get_margin().y * 2);
        }

        // Apply computed bounds to the component
        component->set_position(glm::vec2(xCoord, yCoord));
        component->set_size(glm::vec2(width, height));
    }

    // Finally, calculate size of current component (the container)
    // This is simply the maximum space the component may fill if it is
    // set to stretch. Otherwise, this consists of the accumulated size
    // of all grid cells
    bool fillX = this->get_horizontal_alignment() == Alignment::STRETCH;
    bool fillY = this->get_vertical_alignment() == Alignment::STRETCH;

    float totalWidth = fillX ? maximumSize.x : std::accumulate(colWidths.begin(), colWidths.end(), 0.f);
    float totalHeight = fillY ? maximumSize.y : std::accumulate(rowHeights.begin(), rowHeights.end(), 0.f);
    this->minimumSize = glm::vec2(totalWidth, totalHeight);
}

void Container::set_cols(int c) {
    this->columns = c;
}

void Container::set_rows(int r) {
    this->rows = r;
}


void Container::add_component(Component *component) {
    this->components.push_back(component);
}

void Container::on_mouse_down(glm::vec2 position) {
    for (auto component : components)
        component->on_mouse_down(position - get_origin());
}

void Container::on_mouse_up(glm::vec2 position) {
    for (auto component : components)
        component->on_mouse_up(position - get_origin());
}

glm::vec2 Container::get_origin() const {
    return position + padding;
}

void Container::on_mouse_move(glm::vec2 position) {
    for (auto component : components)
        component->on_mouse_move(position - get_origin());
}

void Container::on_character_typed(uint32_t codepoint) {
    for (auto component : components)
        component->on_character_typed(codepoint);
}

void Container::on_key_event(int key, int action) {
    for (auto component : components)
        component->on_key_event(key, action);
}

Component *Container::find_component(int row, int col) const {
    for (auto component : components)
        if (component->get_row() == row && component->get_col() == col)
            return component;
    return nullptr;
}

void Container::build_rows(std::vector<float> &rowHeights) const {
    // Iterate all rows
    for (int r = 0; r < rows; r++) {
        // Find the tallest component in each row
        float maxHeight = 0.0f;
        for (int c = 0; c < columns; c++) {
            Component *component = find_component(r, c);
            if (component == nullptr)
                continue;

            // Virtual component height basically just means minimum height + vertical margin
            float virtualComponentHeight = component->get_minimum_size().y + component->get_margin().y * 2;
            if (virtualComponentHeight > maxHeight && component->get_row_span() == 1)
                maxHeight = virtualComponentHeight;
        }
        // Add that to our list of rows
        rowHeights.push_back(maxHeight);
    }

    // If our container is set to fill the parent container, we
    // cannot just use the sizes of the components inside the grid
    // because each cell is now larger. Therefore we have to scale it up.
    if (verticalAlignment == Alignment::STRETCH) {
        // Calculate the height of all unstretched rows
        float totalHeight = std::accumulate(rowHeights.begin(), rowHeights.end(), 0.f);

        for (float &rowHeight : rowHeights) {
            // Stretch each row to the maximum height
            rowHeight = (rowHeight / totalHeight * maximumSize.y);
        }
    }
}

void Container::build_cols(std::vector<float> &colWidths) const {
    // Iterate all columns
    for (int c = 0; c < columns; c++) {
        // Find the widest component in each column
        float maxWidth = 0.0f;
        for (int r = 0; r < rows; r++) {
            Component *component = find_component(r, c);
            if (component == nullptr)
                continue;

            // Virtual component width basically just means minimum width + horizontal margin
            float virtualComponentWidth = component->get_minimum_size().x + component->get_margin().x * 2;
            if (virtualComponentWidth > maxWidth && component->get_col_span() == 1)
                maxWidth = virtualComponentWidth;
        }
        // Add that to our list of columns
        colWidths.push_back(maxWidth);
    }

    // Basically the same thing as above, just for columns this time
    if (horizontalAlignment == Alignment::STRETCH) {
        // Calculate the height of all unstretched cols
        float totalWidth = std::accumulate(colWidths.begin(), colWidths.end(), 0.f);

        for (float &colWidth : colWidths) {
            // Stretch each column to the maximum width
            colWidth = (colWidth / totalWidth * maximumSize.x);
        }
    }
}