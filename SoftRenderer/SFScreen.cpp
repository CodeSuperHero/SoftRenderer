//
//  SFScreen.cpp
//  SoftRenderer
//
//  Created by  lyonlei on 16/5/31.
//  Copyright © 2016年  lyonlei. All rights reserved.
//
#include "SFMath.h"
#include "SFScreen.h"
#include <cstring>
#include <cfloat>
#include <cstdio>
#include <iostream>

void SFScreen::Clear() {
    memset(_pixels, 0, _size);
    std::fill(_depthBuffer, _depthBuffer + _bufferSize, FLT_MAX);
}

void SFScreen::PutPixel(int x, int y, float z, const Color &color){
    int index = _width * y + x;
    
    float depth = _depthBuffer[index];
    
    if(depth < z){
        return;
    }
    
    _depthBuffer[index] = z;
    _pixels[index] = color.uint32();
}

void SFScreen::DrawPoint(const int &x, const int &y, const float &z, const Color &color){
    if(x >=0 && y >=0 && x < _width && y < _height)
        PutPixel(x, y, z, color);
}

void SFScreen::DrawPoint(const Vector3 &position, const Color &color){
    if(position.x >= 0 && position.y >= 0 && position.x < _width && position.y < _height){
        PutPixel(position.x, position.y, position.z, color);
    }
}

void SFScreen::DrawLineBresenham(const Vector3 &start, const Vector3 &end, const Color &color) {
    int x0 = (int)start.x;
    int y0 = (int)start.y;
    int x1 = (int)end.x;
    int y1 = (int)end.y;
    
    bool steep = abs(y1 - y0) > abs(x1 - x0);
    if(steep){
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    
    if(x0 > x1){
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    
    int dx = x1 - x0;
    int dy = abs(y1 - y0);
    int d = dy - dx;
    int ystep = 0;
    int y = y0;
    ystep = y0 < y1 ? 1 : -1;
    for (int x = x0; x <= x1; x++) {
        if(steep)
            DrawPoint(y, x, 0, color);
        else
            DrawPoint(x, y, 0, color);
        
        if(d >= 0) {
            y += ystep;
            d -= dx;
        }
        d += dy;
    }
}

void SFScreen::DrawLine(const Vector3 &start, const Vector3 &end, const Color &color, const Rect rect)
{
    float p[4], q[4];

    // x_min <= x_1 + u * Delta_x <= x_max
    // y_min <= y_1 + u * Delta_y <= y_MAX
    // u * p_k <= q_k
    
    float delta_x = start.x - end.x;
    float delta_y = start.y - end.y;
    
    p[0] = delta_x;                 // p_0 = x_1 - x_2
    q[0] = start.x - rect.xMin;     // q_0 = x_1 - x_min
    
    p[1] = -delta_x;                // p_1 = -(x_1 - x_2);
    q[1] = rect.xMax - start.x;     // q_2 = x_max - x_1
    
    p[2] = delta_y;                 // p_2 = y_1 - y_2
    q[2] = start.y - rect.yMin;     // q_2 = y_1 - y_min
    
    p[3] = -delta_y;                // p_3 = Delta_y = -(y_1 - y_2);
    q[3] = rect.yMax - start.y;     // q_3 = y_max - y_1;
    
    float u1 = 0, u2 = 1;
    float r;
    bool flag = false;
    for (int i = 0; i < 4; i ++) {
        r = q[i] / p[i];
        if (p[i] < 0) {
            u1 = SFMath::FloatMAX(u1, r);
            if (u1 > u2) {
                flag = true;
            }
        } else if (p[i] > 0) {
            u2 = SFMath::FloatMin(u2, r);
            if(u1 > u2)
                flag = true;
        } else if (q[i] < 0) {
            flag = true;
        }
    }
    
    if (flag)
        return;
    
    Vector3 s,e;
    
    s.x = start.x - u1*delta_x;
    s.y = start.y - u1*delta_y;
    s.z = start.z;
    
    e.x = start.x - u2*delta_x;
    e.y = start.y - u2*delta_y;
    e.z = end.z;
    
    DrawLineBresenham(s, e, color);
}

void SFScreen::DrawRect(const Rect rect, const Color &color) {
    _rect = rect;
    
    int x0 = (int)rect.xMin;
    int y0 = (int)rect.yMin;
    int x1 = (int)rect.xMax;
    int y1 = (int)rect.yMax;
    while(y1 >= y0)
    {
        Vector3 v0 = Vector3(x0, y0);
        Vector3 v1 = Vector3(x1, y0);
        DrawLineBresenham(v0, v1, color);
        y0++;
    }
}
