//
//  Color.h
//  SoftRenderer
//
//  Created by  lyonlei on 16/5/31.
//  Copyright © 2016年  lyonlei. All rights reserved.
//

#ifndef Color_h
#define Color_h

#include <cstdint>
#include "SFMath.h"

class Color {
public:
    float r;
    float g;
    float b;
    float a;
    
    Color(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);
    Color(uint32_t rgba);
    uint32_t uint32() const;
    
    inline static Color White() {
        return Color(1.0f, 1.0f, 1.0f, 1.0f);
    };
    
    inline static Color Black(){
        return Color(0.0f, 0.0f, 0.0f, 1.0f);
    };
    
    inline static Color Red(){
        return Color(1.0f, 0.0f, 0.0f, 1.0f);
    };
    
    inline static Color Blue(){
        return Color(0.0f, 0.0f, 1.0f, 1.0f);
    };
    
    inline static Color Green(){
        return Color(0.0f, 1.0f, 0.0f,1.0f);
    };
    
    inline Color operator+(const Color &color) const {
        return Color(r + color.r, g + color.g, b + color.b, a + color  .a);
    };
    
    inline Color operator-(const Color &color) const {
        return Color(r - color.r, g - color.g, b - color.b, a - color.a);
    };
    
    inline Color operator*(float factor) const {
        return Color(r * factor, g * factor, b * factor, a * factor);
    };
    
    inline Color operator/(float factor) const {
        return Color(r / factor, g / factor, b / factor, a / factor);
    };

    inline Color Interpolate(const Color &c, float factor) const {
        return *this + (c - *this) * factor;
    };
};


#endif /* Color_h */
