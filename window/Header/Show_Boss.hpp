#ifndef _Show_Boss_
#define _Show_Boss_

void solve_Image_Boss(SDL_Renderer *renderer, Game &game, Object &boss){
    if(game.mode == DEFEAT_BOSS){
        boss.image = loadTexture("Picture/Explosion.png", renderer);
        return;
    }

    if(game.level <= 2){
        string s = "Picture/Boss";
        s += char(game.level + 48);
        s += ".png";
        const string file = s;
        boss.image = loadTexture(file, renderer);
    }
    else if(game.level == 3){
        if(game.time % 16 == 9){
            boss.image = loadTexture("Picture/Boss_Angry.png", renderer);
        }
        else if(game.time % 16 == 0){
            boss.image = loadTexture("Picture/Boss_SIMPLE.png", renderer);
        }
    }
}

void show_Boss(SDL_Renderer* renderer, Object &boss, Game &game){
    if(!boss.visible) return;
    solve_Image_Boss(renderer, game, boss);

    // show boss
    SDL_Rect range_boss;
    range_boss.x = boss.x;
    range_boss.y = boss.y;
    range_boss.w = boss.width;
    range_boss.h = boss.height;
    SDL_RenderCopy(renderer, boss.image, NULL, &range_boss);

    // show life of boss
    SDL_Rect range, area;
    range.h = 5;
    range.w = boss.width;
    range.x = boss.x;
    range.y = 2;

    area.h = 5;
    area.w = range.w / LIFE_BOSS[game.level] * game.life_boss;
    area.x = boss.x;
    area.y = 2;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &area);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    if(game.mode == DEFEAT_BOSS) return;
    for(int i = 0; i <= 1; ++ i){
        range.x -= 1;
        range.y -= 1;
        range.w += 2;
        range.h += 2;
        SDL_RenderDrawRect(renderer, &range);
    }
}
#endif

