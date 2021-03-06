//
//  Color.cpp
//  SoftRenderer
//
//  Created by  lyonlei on 16/5/31.
//  Copyright © 2016年  lyonlei. All rights reserved.
//
#include <iostream>
#include "Color.h"

Color::Color(float red, float green, float blue, float alpha) {
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

Color::Color(uint32_t rgba) {
    r = ((rgba & 0xff000000) >> 24) / 255.0f;
    g = ((rgba & 0x00ff0000) >> 16) / 255.0f;
    b = ((rgba & 0x0000ff00) >> 8) / 255.0f;
    a = (rgba & 0x000000ff) / 255.0f;
}

uint32_t Color::uint32() const {
    uint32_t R = (uint32_t)(r * 255.0f * a);
    uint32_t G = (uint32_t)(g * 255.0f * a);
    uint32_t B = (uint32_t)(b * 255.0f * a);
    uint32_t A = (uint32_t)(a * 255.0f);
    //自己实现alpha.
    uint32_t value = (A << 24) | (R << 16) | (G << 8) | B;
    //std::cout<< "R : "<< R <<"G: "<<G<<"B"<<B<<"value"<<value<<std::endl;
    return value;
}