//
//  SFScreen.hpp
//  SoftRenderer
//
//  Created by  lyonlei on 16/5/31.
//  Copyright © 2016年  lyonlei. All rights reserved.
//

#ifndef SFScreen_hpp
#define SFScreen_hpp

#include <stdio.h>
#include "Color.h"
#include "Vector3.h"
#include "Rect.h"

class SFScreen{
private:
    uint32_t* _pixels;
    size_t _size;
    
    float* _depthBuffer;
    uint32_t _bufferSize;
    uint32_t _width;
    uint32_t _height;
    
    void DrawPoint(const int &x, const int &y, const float &z, const Color &color);
    void PutPixel(int x, int y, float z, const Color &color);
    
    Rect _rect;
public:
    SFScreen(uint32_t* pixels, float width, float height){
        _pixels = pixels;
        _width = width;
        _height = height;
        _size = sizeof(uint32_t) * width * height;
        _bufferSize = width * height;
        _depthBuffer = new float[_bufferSize];
    };
    
    virtual ~SFScreen() {
        delete [] _depthBuffer;
    };
        
    void Clear();
    
    void DrawPoint(const Vector3 &v, const Color &color);
//    void DrawLine(const Vector3 &start, const Vector3 &end, const Color &color);
    void DrawLineBresenham(const Vector3 &start,const Vector3 &end, const Color &color);
    
    void DrawRect(const Rect rect, const Color &color);
    
    void DrawLine(const Vector3 &start, const Vector3 &end, const Color &color, const Rect rect);
    //void DrawLineBresenham(const Vector3 &start,const Vector3 &end, const Color &color);
};
#endif /* SFScreen_hpp */
