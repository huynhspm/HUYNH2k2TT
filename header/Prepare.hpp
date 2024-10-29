#ifndef _Prepare_
#define _Prepare_

#include "Show_Menu.hpp"
int prepare(SDL_Renderer * renderer, int& level_start){
    int x = 0, y = 0; bool chooselevel = false;
    SDL_Event e;
    show_Menu(renderer, x, y, chooselevel, level_start);
    while(true){
        if(SDL_PollEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) return false;
        else if(e.type == SDL_KEYDOWN){
            if(e.key.keysym.sym == SDLK_ESCAPE) return false;
        }
        else if(e.type == SDL_MOUSEMOTION){
            x = e.button.x;
            y = e.button.y;
        }
        else if(e.type == SDL_MOUSEBUTTONDOWN){
            x = e.button.x;
            y = e.button.y;
            if(target_Range(x, y, range_NEWGAME)) break;
            else if(target_Range(x, y, range_CHOOSELEVEL)) chooselevel = true;
            else if(target_Range(x, y, range_1)) level_start = 1;
            else if(target_Range(x, y, range_2)) level_start = 2;
            else if(target_Range(x, y, range_3)) level_start = 3;
        }
        else continue;
        show_Menu(renderer, x, y, chooselevel, level_start);
    }
    return true;
}

#endif

