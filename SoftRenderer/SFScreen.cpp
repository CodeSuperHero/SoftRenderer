//
//  SFScreen.cpp
//  SoftRenderer
//
//  Created by  lyonlei on 16/5/31.
//  Copyright © 2016年  lyonlei. All rights reserved.
//

#include "SFScreen.h"
#include <cstring>
#include <cmath>
#include <cfloat>
#include <cstdio>
#include <iostream>

//#include <string>

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
    //std::cout<<"x : "<<x<<" y : "<<y<<std::endl;
    if(x >=0 && y >=0 && x < _width && y < _height)
        PutPixel(x, y, z, color);
}

void SFScreen::DrawPoint(const Vector3 &position, const Color &color){
    if(position.x >= 0 && position.y >= 0 && position.x < _width && position.y < _height){
        PutPixel(position.x, position.y, position.z, color);
    }
}

void SFScreen::DrawLine(const Vector3 &start, const Vector3 &end, const Color &color){
    if(start == end){
        this->DrawPoint(start, color);
        return;
    }
    
    int x1 = (int)start.x;
    int x2 = (int)end.x;
    int y1 = (int)start.y;
    int y2 = (int)end.y;
    
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    if (abs(dx) > abs(dy))
    {
        int sign = dx > 0 ? 1 : -1;
        float ratio = (float)dy / dx;
        
        for (int x = x1; x != x2; x+=sign) {
            int y = y1 + (x - x1) * ratio;
            this->DrawPoint(Vector3(x,y), color);
        }
    }
    else
    {
        int sign = dy > 0 ? 1 : -1;
        float ratio = (float)dx / dy;
        
        for (int y = y1; y != y2; y+=sign) {
            int x = x1 + (y - y1) * ratio;
            this->DrawPoint(Vector3(x,y), color);
        }
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
    //float error = 0.0f;
    //float derr = dy * 1.0f / dx;
    int ystep = 0;
    int y = y0;
    ystep = y0 < y1 ? 1 : -1;
    for (int x = x0; x <= x1; x++) {
        if(steep)
            DrawPoint(y, x, 0, color);
        else
            DrawPoint(x, y, 0, color);
        
        //error += derr;
        if(d >= 0) {
            y += ystep;
            d -= dx;
        }
        d += dy;
    }
    
    std::cout<<"--end"<<std::endl;
}





