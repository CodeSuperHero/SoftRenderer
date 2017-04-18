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
#include "Color.h"
#include "Vector3.h"

using namespace std;

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;

class Window {
private:
    SFScreen* _sfScreen;
    SDL_Surface* _sdlScreen;
    SDL_Window* _sdlWindow;
    SDL_Event _event;
    
    int _width;
    int _height;
    
    bool _running;
    
public:
    Window(int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT, const char *title = "SoftRender") {
        _width = width;
        _height = height;
        _sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        _sdlScreen = SDL_GetWindowSurface(_sdlWindow);
        _sfScreen = new SFScreen((uint32_t*) _sdlScreen->pixels, width, height);
        _running = true;
    };
    
    void Run() {
        int x = 0;
        int y = 0;
        int index = 0;
        Vector3 center = Vector3(_width >> 1, _height >> 1);
        Color* c = new Color(0.0f, 1.0f, 0.0f, 1.0f);
        
          while (_running) {
            UpdateInput();
            
            Clear();
              
            // -- test draw start
            _sfScreen->DrawLineBresenham(Vector3(x,y), center, *c);
            if (index < 50) {
                index ++;
                continue;
            }
              
            if(x == 0 && y == 0){
                x++;
            } else if(0 < x && y == 0){
                x ++;
                if(x == _width)
                    y++;
            } else if(x == _width && y > 0){
                y++;
                if(y == _height)
                    x--;
            } else if(x > 0 && y == _height){
                x--;
                if(x == 0)
                    y--;
            } else if(x == 0 && y > 0){
                y--;
            }
            // -- test draw end
              
            //Draw();
            
            Show();
        }
    };
    
    void UpdateInput() {
        while (SDL_PollEvent(&_event) != 0) {
            if (_event.type == SDL_QUIT) {
                Quit();
            }
        }
    }
    
    void Show() {
        SDL_UnlockSurface(_sdlScreen);
        SDL_UpdateWindowSurface(_sdlWindow);
    };
    
    void Clear() {
        _sfScreen->Clear();
    };
    
    void Draw() {
        
    };
    
    void Quit()
    {
        _running = false;
        SDL_DestroyWindow(_sdlWindow);
        SDL_Quit();
    };
};

#endif /* Window_h */
