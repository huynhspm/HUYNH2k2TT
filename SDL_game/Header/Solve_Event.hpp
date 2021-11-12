#ifndef _Solve_Event_
#define _Solve_Event_

#include "Solve_Pause.hpp"
void solve_Event(Object& plane, Game& game){
    bool check = false;
    for(int i = 0; i <= 20; ++ i){
        SDL_Event event;

        if(SDL_PollEvent(&event) == 0 || check) continue;
        else if(game.mode == PASS_LEVEL || game.mode == PREPARE_PASS_LEVEL) continue;

        switch(event.type){
            case SDL_QUIT:{
                game.mode = QUIT; check = true;
                break;
            }
            case SDL_KEYDOWN:{
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:{
                        game.mode = QUIT;
                        break;
                    }
                    case SDLK_LEFT:{
                        plane.direct = LEFT;
                        break;
                    }
                    case SDLK_a: {
                        plane.direct = LEFT;
                        break;
                    }
                    case SDLK_RIGHT:{
                        plane.direct = RIGHT;
                        break;
                    }
                    case SDLK_d:{
                        plane.direct = RIGHT;
                        break;
                    }
                    case SDLK_DOWN:{
                        plane.direct = DOWN;
                        break;
                    }
                    case SDLK_s:{
                        plane.direct = DOWN;
                        break;
                    }
                    case SDLK_UP:{
                        plane.direct = UP;
                        break;
                    }
                    case SDLK_w:{
                        plane.direct = UP;
                        break;
                    }
                    case SDLK_m:{
                        game.music = START;
                        break;
                    }
                    default:{
                        break;
                    }
                }
                check = true;
                break;
            }
            case SDL_MOUSEBUTTONDOWN:{
                if(event.button.button == SDL_BUTTON_LEFT){
                    int x = event.button.x;
                    int y = event.button.y;
                    if(target_Range(x, y, button_PAUSE)){
                        if(game.mode == BATTLE_BOSS || game.mode == BATTLE_NORMAL){
                            game.last_mode = game.mode;
                            game.mode = PAUSE;
                        }
                    }
                    else if(target_Range(x, y, button_REPLAY)) game.mode = REPLAY;
                    else if(target_Range(x, y, button_QUIT)) game.mode = QUIT;
                    else if(target_Range(x, y, button_SOUND)){
                        if(game.music == PAUSE) game.music = START;
                        else game.music = PAUSE;
                    }
                    check = true;
                }
                break;
            }
            default:{
                break;
            }
        }
    }
}

#endif
