//
// Created by twome on 30/05/2020.
//

#include "MeshBuilder.h"

namespace crystal {
    void MeshBuilder::push_rectangle(float x, float y, float width, float height, glm::vec3 color) {
        push_vertex(x, y);
        push_vertex(x + width, y);
        push_vertex(x, y + height);

        push_vertex(x, y + height);
        push_vertex(x + width, y + height);
        push_vertex(x + width, y);

        push_color(color.r, color.g, color.b);
        push_color(color.r, color.g, color.b);
        push_color(color.r, color.g, color.b);
        push_color(color.r, color.g, color.b);
        push_color(color.r, color.g, color.b);
        push_color(color.r, color.g, color.b);
    }

    void MeshBuilder::push_tex_rectangle(float x, float y, float width, float height) {
        push_vertex(x, y);
        push_vertex(x + width, y);
        push_vertex(x, y + height);

        push_vertex(x, y + height);
        push_vertex(x + width, y + height);
        push_vertex(x + width, y);

        push_texture(0, 0);
        push_texture(1, 0);
        push_texture(0, 1);

        push_texture(0, 1);
        push_texture(1, 1);
        push_texture(1, 0);
    }

    float *MeshBuilder::get_vertices() {
        return &vertices[0];
    }

    int MeshBuilder::get_vertex_count() const {
        return vertices.size();
    }

    float *MeshBuilder::get_meta() {
        return &vertexMeta[0];
    }

    int MeshBuilder::get_meta_count() const {
        return vertexMeta.size();
    }

    void MeshBuilder::clear() {
        vertices.clear();
        vertexMeta.clear();
    }

    void MeshBuilder::push_vertex(float x, float y) {
        vertices.push_back(x);
        vertices.push_back(y);
    }

    void MeshBuilder::push_color(float r, float g, float b) {
        vertexMeta.push_back(r);
        vertexMeta.push_back(g);
        vertexMeta.push_back(b);
    }

    void MeshBuilder::push_texture(float u, float v) {
        vertexMeta.push_back(u);
        vertexMeta.push_back(v);
    }
}