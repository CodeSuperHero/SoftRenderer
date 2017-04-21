//
//  Vector3.h
//  SoftRenderer
//
//  Created by  lyonlei on 16/6/1.
//  Copyright © 2016年  lyonlei. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

#include "SFMath.h"
#include "Vector2.h"
#include <cmath>

class Vector3 {
public:
    float x;
    float y;
    float z;
    
    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    inline static Vector3 Zero()  {
        return Vector3();
    }
    
    Vector3 operator+(const Vector3 &v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }
    
    Vector3 operator-(const Vector3 &v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }
    
    Vector3 operator*(float factor) const {
        return Vector3(x * factor, y * factor, z * factor);
    }
    
    Vector3 operator/(float factor) const {
        return Vector3(x / factor, y / factor, z / factor);
    }
    
    bool operator==(const Vector3 &v) const{
        return SFMath::FloatEqual(x, v.x) && SFMath::FloatEqual(y, v.y) && SFMath::FloatEqual(z, v.z);
    }
    
    Vector3 operator!=(const Vector3 &v) const{
        return !SFMath::FloatEqual(x, v.x) || !SFMath::FloatEqual(y, v.y) || !SFMath::FloatEqual(z, v.z);
    }
    
    inline Vector3 Normalize() const {
        float mag = magnitude();
        if(mag > 0)
            return *this *(1.0f / mag);
        else
            return Vector3();
    }
    
    inline float sqrMagnitude() const {
        return x * x + y * y + z * z;
    }
    
    inline float magnitude() const {
        return sqrtf(sqrMagnitude());
    }
    
    
   inline static float Dot(const Vector3 &v1, const Vector3 &v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }
    
    
    inline static void SwapVector3(Vector3 &v1, Vector3 &v2){
        Vector3 temp = v1;
        v1 = v2;
        v2 = temp;
    }
};

#endif /* Vector_h */






