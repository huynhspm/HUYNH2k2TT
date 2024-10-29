#ifndef _Show_
#define _Show_

#include "Show_Background.hpp"
#include "Design_Broad.hpp"
#include "Show_Plane.hpp"
#include "Show_BulletPlane.hpp"
#include "Show_Obstacle.hpp"
#include "Show_Boss.hpp"
#include "Show_BulletBoss.hpp"

void refreshScreen(SDL_Renderer* renderer, Object& plane, vBullet& bullet_plane, Obstacle& obstacle,
                   Object& boss, Bullet& bullet_boss, Game& game, Background& background){
    show_Background(renderer, background, game);

    design_Broad(renderer, game);

    show_Plane(renderer, plane, game, boss);

    show_BulletPlane(renderer, bullet_plane, game);

    show_Obstacle(renderer, obstacle);

    show_Boss(renderer, boss, game);

    show_BulletBoss(renderer, bullet_boss, game, boss);

    SDL_RenderPresent(renderer);
}

#endif
