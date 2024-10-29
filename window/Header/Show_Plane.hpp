#ifndef _Show_Plane_
#define _Show_Plane_

void solve_Image_Plane(SDL_Renderer* renderer, Game &game, Object &plane){
    if(game.mode == EXPLOSION && game.time_Immortal + 1 == TIME_IMMORTAL){
        plane.image = loadTexture("Picture/Explosion.png", renderer);
    }
    else{
        string s = "Picture/Plane";
        if(game.mode == PASS_LEVEL) s += char(min(3, game.level + 1) + 48);
        else s += char(min(3, game.level) + 48);
        s += ".png";
        const string file = s;
        plane.image = loadTexture(file, renderer);
    }
}

void show_Plane(SDL_Renderer* renderer, Object &plane, Game &game, Object &boss){
    if(!plane.visible) return;
    if(game.mode == EXPLOSION && game.time_Immortal % 2 == 0) return;
    solve_Image_Plane(renderer, game, plane);
    SDL_Rect range_plane, range_image;
    range_image.x = 0;
    range_image.y = 0;
    range_image.w = plane.width;
    range_image.h = plane.height;

    range_plane.x = plane.x;
    range_plane.y = plane.y;
    range_plane.w = plane.width;
    range_plane.h = plane.height;

    if(range_plane.x + range_plane.w > BROAD_WIDTH){
        SDL_Rect range_add = range_plane;
        range_add.x = range_plane.x - BROAD_WIDTH;
        SDL_RenderCopy(renderer, plane.image, NULL, &range_add);

        range_plane.w = BROAD_WIDTH - range_plane.x;
        range_image.w = range_plane.w;
    }
    SDL_RenderCopy(renderer, plane.image, &range_image, &range_plane);

    if(plane.type == ARMOR){
        plane.armor = loadTexture("Picture/ARMOR.png", renderer);
        SDL_RenderCopy(renderer, plane.armor, &range_image, &range_plane);

    }
}
#endif
