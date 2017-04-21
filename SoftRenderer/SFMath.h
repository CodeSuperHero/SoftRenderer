//
//  SFMath.h
//  SoftRenderer
//
//  Created by  lyonlei on 16/6/1.
//  Copyright © 2016年  lyonlei. All rights reserved.
//

#ifndef SFMath_h
#define SFMath_h

#include <cmath>

class SFMath{
public:
    constexpr const static float FLOAT_EPSILON = 0.0001f;
    constexpr const static float PI = 3.1415926535f;
    constexpr const static float DEGREE_TO_RADIAN =  0.017453293f;
    constexpr const static float RADIAN_TO_DEGREE = 57.295779515f;
    
    inline static bool FloatEqual(const float a, const float b){
        return fabsf(a-b) <= FLOAT_EPSILON;
    }
    
    inline static float DegreeToRadian(const float degree){
        return PI * degree * DEGREE_TO_RADIAN;
    }
    
    inline static float RadianToDegree(const float radian){
        return radian * RADIAN_TO_DEGREE;
    }
    
    inline static float FloatMAX(const float a, const float b) {
        return a > b ? a : b;
    }
    
    inline static float FloatMin(const float a, const float b) {
        return a < b ? a : b;
    }
};

#endif /* SFMath_h */
