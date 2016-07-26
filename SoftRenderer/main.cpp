//
//  main.cpp
//  SoftRenderer
//
//  Created by  lyonlei on 16/5/30.
//  Copyright © 2016年  lyonlei. All rights reserved.
//

#include <SDL2/SDL.h>
#include "SFScreen.h"
#include <iostream>
#include <thread>

const uint32_t WIDTH = 320;
const uint32_t HEIGHT = 240;

int main(int argc, const char * argv[]) {
    SFScreen* _sfScreen;
    SDL_Window* window = NULL;
    SDL_Surface* screen = NULL;
//    SDL_Surface* image = NULL;
    SDL_Event event;
    SDL_bool running = SDL_TRUE;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return 0;
    }
    
    window = SDL_CreateWindow("Hello Sdl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    
    screen = SDL_GetWindowSurface(window);
    _sfScreen = new SFScreen((uint32_t*) screen->pixels, WIDTH, HEIGHT);
    Color* col = new Color(0.0f,1.0f,0.0f,1.0f);
    
//    uint centerx = WIDTH >> 1;
//    uint centery = HEIGHT >> 1;
    
    Vector3 center = Vector3(WIDTH >> 1,HEIGHT >> 1);
    std::cout<<"center x "<<center.x<<" center y : "<<center.y<<std::endl;
    int x = 0;
    int y = 0;
    int index = 0;
    while(running) {
        while (SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT){
                running = SDL_FALSE;
            }
        }
        
        _sfScreen->Clear();
        _sfScreen->DrawLineBresenham(Vector3(x, y), center, *col);
        if(index < 50) {
            index++;
            continue;
        }
//
        if(x == 0 && y == 0){
            x++;
        } else if(0 < x && y == 0){
            x ++;
            if(x ==WIDTH)
                y++;
            
        } else if(x == WIDTH && y > 0){
                y++;
                if(y == HEIGHT)
                    x--;
        } else if(x > 0 && y == HEIGHT){
            x--;
            if(x == 0)
                y--;
        } else if(x == 0 && y > 0){
            y--;
        }
        
        SDL_UpdateWindowSurface(window);
        
    }
        
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
