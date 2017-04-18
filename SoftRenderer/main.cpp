//
//  main.cpp
//  SoftRenderer
//
//  Created by  lyonlei on 16/5/30.
//  Copyright © 2016年  lyonlei. All rights reserved.
//

#include "SDL2/SDL.h"
#include "SFScreen.h"
#include "Window.h"
#include <iostream>
#include <thread>

int main(int argc, const char * argv[]) {
    Window* w = new Window();
    if (w == NULL) {
        printf(" w is null");
        getchar();
    }
    w->Run();
    return 0;
}
