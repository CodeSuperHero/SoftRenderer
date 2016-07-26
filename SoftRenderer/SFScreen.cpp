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
    std::cout<<" init x0 :"<<x0<<" y0 : "<<y0<<" x1: "<<x1<<"  y1 : "<<y1<<std::endl;
    
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int yy = 0;
    
    if(dy < dx){
        yy = 1;
//        std::swap(x0, y0);
//        std::swap(x1, y1);
        std::swap(dx, dy);
    }
    
    std::cout<<"x0:"<<x0<<" y0:"<<y0<<"  x1:"<<x1<<"  y1:"<<y1<<"  dx :"<<dx<<"  dy: "<<dy<<std::endl;
    
    int ix = x1 > x0 ? 1 : -1;
    int iy = y1 > y0 ? 1 : -1;
    
//    int x = x0;
    int y = y0;
    int de = 2 * dy;
    int d = de - dx;
    int dne = de - 2 * dx;
    
    std::cout<<"--start"<<" d:"<<d<<" de:"<<de<<" dne:"<<dne<<" yy : "<<yy<<std::endl;
//    std::cout<<"-- x1 :"<<x1<<" y1:"<<y1<<" x : "<<x<<" y : "<<y<<std::endl;
    int index = 0;
    if(yy){
//        std::cout<<"index : "<<index++<<"  y : "<<y<<"  x : "<<x<<"  x1 : "<<x1<<" d : "<<d<<std::endl;
        
        for (int x = x0; x <= x1; x++) {
            DrawPoint(x, y, start.z, color);
//            if(d < 0)
        }
//        while (x != x1) {
//            if (d < 0) {
//                d += de;
//            } else {
//                y += iy;
//                d += dne;
//            }
//            x += ix;
//            std::cout<<"index : "<<index++<<"  y : "<<y<<"  x : "<<x<<"  x1 : "<<x1<<" d : "<<d<< "d < 0 : "<<(d < 0)<<std::endl;
//            DrawPoint(y, x, start.z, color);
//        }
    }
    else{
//        DrawPoint(x, y, start.z, color);
//        while (x != x1) {
//            if (d < 0) {
//                d += de;
//            } else {
//                y += iy;
//                d += dne;
//            }
//            x += ix;
//            DrawPoint(x, y, start.z, color);
//        }
    }
    std::cout<<"--end"<<std::endl;
}

//void SFScreen::DrawLineBresenham(const Vector3 &start, const Vector3 &end, const Color &color){
//    int x1 = (int)start.x;
//    int y1 = (int)start.y;
//    int x2 = (int)end.x;
//    int y2 = (int)end.y;
//    
//    int dx = abs(x2 - x1);
//    int dy = abs(y2 - y1);
//    int yy = 0;
//    if(dx < dy){
//        yy = 1;
//        std::swap(x1, x2);
//        std::swap(x2, y2);
//        std::swap(dx, dy);
//    }
//    
//    int ix = (x2 - x1) > 0 ? 1 : -1;
//    int iy = (y2 - y1) > 0 ? 1 : -1;
//    int cx = x1;
//    int cy = y1;
//    int n2dy = dy * 2;
//    int n2dydx = (dy - dx) * 2;
//    int d = dy * 2 - dx;
//    
//    if(yy){
//        while(cx != x2){
//            if(d < 0){
//                d+=n2dy;
//            }
//            else{
//                d+= n2dydx;
//                cy += iy;
//            }
//            DrawPoint(cy, cx, 0, color);
//            cx += ix;
//        }
//    }else{
//        while(cx != x2){
//            if(d < 0){
//                d+=n2dy;
//            }else{
//                d+=n2dydx;
//                cy += iy;
//            }
//            DrawPoint(cx, cy, 0, color);
//            cx+=ix;
//        }
//    }
//}





