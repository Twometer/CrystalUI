//
// Created by twome on 30/05/2020.
//

#ifndef CRYSTALUI_MESHBUILDER_H
#define CRYSTALUI_MESHBUILDER_H

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class MeshBuilder {
private:
    std::vector<float> vertices;

    std::vector<float> vertexMeta;

    void push_vertex(float x, float y);

    void push_color(float r, float g, float b);

    void push_texture(float u, float v);

public:
    void push_rectangle(float x, float y, float width, float height, glm::vec3 color);

    void push_tex_rectangle(float x, float y, float width, float height);

    float *get_vertices();

    int get_vertex_count() const;

    float *get_meta();

    int get_meta_count() const;

    void clear();

};


#endif //CRYSTALUI_MESHBUILDER_H
