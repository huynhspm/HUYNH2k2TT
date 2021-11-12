#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

#include "Header/SDL_default.hpp"
#include "Header/Public.hpp"
#include "Header/Solve_Event.hpp"
#include "Header/Solve_Plane.hpp"
#include "Header/Solve_BulletPlane.hpp"
#include "Header/Solve_Obstacle.hpp"
#include "Header/Solve_Boss.hpp"
#include "Header/Solve_BulletBoss.hpp"
#include "Header/Solve_Collision.hpp"
#include "Header/End_Game.hpp"
#include "Header/Solve_Level.hpp"
#include "Header/Show.hpp"
#include "Header/Solve_Music.hpp"
#include "Header/Prepare.hpp"
#include "Header/Start_Game.hpp"

int main(int argc, char* argv[]){
    srand(time(NULL));
    SDL_Window* window;
    SDL_Renderer* renderer;

    initSDL(window, renderer);
    while(true){
        int level_start = 1;
        if(!prepare(renderer, level_start)) break;

        Object plane = Object(true, STEP*8, BROAD_HEIGHT - PLANE_HEIGHT, PLANE_WIDTH, PLANE_HEIGHT, SIMPLE, STATIC);
        Object boss = Object(false, 0, 0, BOSS_WIDTH, BOSS_HEIGHT, SIMPLE, LEFT);
        Background background = Background(0, 0);
        Game game = Game(level_start, 5, SCORE_LEVEL[level_start - 1], 0, 0, BATTLE_NORMAL, 0, START);
        vBullet bullet_plane;
        bullet_plane.push_back(Bullet{true, BULLET_PLANE_WIDTH , BULLET_PLANE_HEIGHT});
        Bullet bullet_boss = Bullet(false, BULLET_BOSS_WIDTH[game.level], BULLET_BOSS_HEIGHT[game.level]);
        Obstacle obstacle = Obstacle(true, OBSTACLE_WIDTH, OBSTACLE_HEIGHT);

        start_Game(renderer, plane, bullet_plane, obstacle, boss, bullet_boss, game, background);

        if(game.mode == QUIT) break;
    }
    SDL_Delay(100);
    quitSDL(window, renderer);
    return 0;
}

