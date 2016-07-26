//
//  Window.h
//  SoftRenderer
//
//  Created by  lyonlei on 16/6/2.
//  Copyright © 2016年  lyonlei. All rights reserved.
//

#ifndef Window_h
#define Window_h

#include<cstdio>
#include<SDL2/SDL.h>

#include "SFScreen.h"
#include "Color.h";
#include "Vector3.h";

using std::vector;

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;

class Window {
private:
    SDL_Surface* _sdlSreen;
    SFScreen* _screen;
    
    int _width;
    int _height;
    
    bool _running;
    
public:
    Window(int argc, char *argv[], int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT, const char *title = "SoftRender") {
        if(SDL_Init(SDL_INIT_VIDEO) != 0) {
            fprintf(stderr, "SDL_Init failed\n")
        }
        
        SDL_Surface* screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
        if(screen == NULL){
            SDL_Quit();
            fprintf(stderr, "SDL_SetVideoMode failed\n");
        }
        _sdlSreen = screen;
        SDL_WM_SetCaption(title, NULL);
        
        _width = width;
        _height = height;
        
        _screen = new SFScreen((uint32_t *)screen->pixels, width, height);
        
        _running = true;
        
    };
    
    void Run() {
        while (_running) {
            SDL_LockSurface(_screen);
            
//            UpdateInput();
            
            Clear();
            
            Draw();
            
            Show();
        }
    };
    
    void Show() {
        SDL_UnlockSurface(_sdlSreen);
        SDL_UpdateRect(_sdlSreen, 0, 0, 0, 0);
    };
    
    void Clear() {
        _screen->Clear();
    };
    
    void Draw() {
        Vector3 vec;
        vec.x = 10f;
        vec.y = 10f;
        vec.z = 1f;
        Color(1f,0f,0f,1f) color;
        _screen.DrawPoint(&vec, &color);
    };
    
    void Quit()
    {
        _running = false;
    }
}

#endif /* Window_h */
