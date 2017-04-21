//
//  Rect.hpp
//  SoftRenderer
//
//  Created by  lyonlei on 17/4/18.
//  Copyright © 2017年  lyonlei. All rights reserved.
//

#ifndef Rect_hpp
#define Rect_hpp

#include "Vector2.h"

#include <stdio.h>

class Rect {
public:
    float width,height;
    float xMax, xMin;
    float yMax, yMin;
    Vector2 center;
    Vector2 max;
    Vector2 min;
    Vector2 position;
    Vector2 size;
    
    
    
    Rect(float x = 0.0f, float y = 0.0f, float width = 0.0f, float height = 0.0f) {
        this->xMin = x;
        this->yMin = y;
        this->width = width;
        this->height = height;
        this->xMax = x + width;
        this->yMax = y + height;
    };
    
    inline static Rect zero() {
        return Rect();
    }
    
    bool Contains(Vector2 point) const {
        return true;
    }
    
};
#endif /* Rect_hpp */
