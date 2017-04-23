//
//  Vertex.hpp
//  SoftRenderer
//
//  Created by  lyonlei on 17/4/23.
//  Copyright © 2017年  lyonlei. All rights reserved.
//

#ifndef Vertex_h
#define Vertex_h

#include <stdio.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Color.h"

class Vertex {
public:
    Vector3 position;
    Vector3 normal;
    Vector2 uv1;
    Color color;
    
    Vertex(const Vector3 &position, const Vector3 normal, const Vector2 uv1, const Color &color=Color()) {
        this->position = position;
        this->normal = normal;
        this->uv1 = uv1;
        this->color = color;
    };
    
    Vertex interpolate(const Vertex &vertex, float factor) const {
        auto p = position.interpolate(vertex.position, factor);
        auto n = normal.interpolate(vertex.normal, factor);
        auto uv = uv1.interpolate(vertex.uv1, factor);
        auto c = color.interpolate(vertex.color, factor);
        return Vertex(p, n, uv, c);
    };
};

#endif /* Vertex_h */
