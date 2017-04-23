//
//  Vector2.h
//  SoftRenderer
//
//  Created by  lyonlei on 17/4/18.
//  Copyright © 2017年  lyonlei. All rights reserved.
//

#ifndef Vector2_h
#define Vector2_h

#include "SFMath.h"
#include "Vector3.h"
#include <cmath>

class Vector2{
    public :
    float x, y;
    
    Vector2(float x = 0.0f, float y = 0.0f){
        this->x = x;
        this->y = y;
    }
    
    inline static Vector2 Zero(){
        return Vector2();
    }
    
    Vector2 operator+(const Vector2 &v) const {
        return Vector2(x + v.x, y + v.y);
    }
    
    Vector2 operator-(const Vector2 &v) const {
        return Vector2(x - v.x, y - v.y);
    }
    
    Vector2 operator*(float factor) const {
        return Vector2(x * factor, y * factor);
    }
    
    Vector2 operator/(float factor) const {
        return Vector2(x / factor, y / factor);
    }
    
    bool operator==(const Vector2 &v) const{
        return SFMath::FloatEqual(x, v.x) && SFMath::FloatEqual(y, v.y);
    }
    
    Vector2 operator!=(const Vector2 &v) const{
        return !SFMath::FloatEqual(x, v.x) || !SFMath::FloatEqual(y, v.y);
    }
    
    inline Vector2 Normalize() const {
        float mag = magnitude();
        if(mag > 0)
            return *this *(1.0f / mag);
        else
            return Vector2();
    }
    
    inline Vector2 interpolate(const Vector2 &v, float factor) const {
        return *this + (v - *this) * factor;
    };
    
    inline float sqrMagnitude() const {
        return x * x + y * y;
    }
    
    inline float magnitude() const {
        return sqrtf(sqrMagnitude());
    }
    
    
    inline static float Dot(const Vector2 &v1, const Vector2 &v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }
    
    
    inline static void SwapVector2(Vector2 &v1, Vector2 &v2){
        Vector2 temp = v1;
        v1 = v2;
        v2 = temp;
    }
    
    
};

#endif /* Vector2_h */
