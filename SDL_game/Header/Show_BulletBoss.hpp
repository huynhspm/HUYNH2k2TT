#ifndef _Show_BulletBoss_
#define _Show_BulletBoss_

void solve_Image_BulletBoss(SDL_Renderer* renderer, Game &game, Bullet &bullet_boss){
    string s = "Picture/Bullet_Boss";
    s += char(game.level + 48);
    if(game.level == 2) s += char(rand() % 2 + 49);
    s += ".png";
    const string file = s;
    bullet_boss.image = loadTexture(file, renderer);
}

void show_BulletBoss(SDL_Renderer* renderer, Bullet &bullet_boss, Game &game, Object & boss){
    if(bullet_boss.visible){
        solve_Image_BulletBoss(renderer, game, bullet_boss);

        for(int i = 0; i < bullet_boss.bullet_array.size(); ++ i){
            SDL_Rect range_bullet;
            range_bullet.w = bullet_boss.width;
            range_bullet.h = bullet_boss.height;
            range_bullet.x = bullet_boss.bullet_array[i].x;
            range_bullet.y = bullet_boss.bullet_array[i].y;
            SDL_RenderCopy(renderer, bullet_boss.image, NULL, &range_bullet);
        }
    }

    if(game.level == 2 && boss.visible){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 0, boss.y + boss.height, BROAD_WIDTH, boss.y + boss.height);
    }

    if(game.level == 3 && boss.visible && game.time % 16 == 15){
        solve_Image_BulletBoss(renderer, game, bullet_boss);

        SDL_Rect range_bullet;
        range_bullet.w = BOSS_WIDTH;
        range_bullet.h = BROAD_HEIGHT - BOSS_HEIGHT;
        range_bullet.x = boss.x;
        range_bullet.y = boss.y + BOSS_HEIGHT;
        SDL_RenderCopy(renderer, bullet_boss.image, NULL, &range_bullet);
    }

}
#endif

