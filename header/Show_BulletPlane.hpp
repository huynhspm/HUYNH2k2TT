#ifndef _Show_BulletPlane_
#define _Show_BulletPlane_

void solve_Image_BulletPlane(SDL_Renderer *renderer, Game &game, Bullet &bullet_plane)
{
    string s = PICTURE_FOLDER + "/Bullet_Plane";
    s += char(min(3, game.level) + 48);
    s += ".png";
    const string file = s;
    bullet_plane.image = loadTexture(file, renderer);
}

void show_BulletPlane(SDL_Renderer *renderer, vBullet &bullet_plane, Game &game)
{
    for (Bullet &bullet : bullet_plane)
    {
        if (!bullet.visible)
            continue;
        solve_Image_BulletPlane(renderer, game, bullet);
        for (int i = 0; i < bullet.bullet_array.size(); ++i)
        {
            SDL_Rect range_image;
            range_image.x = 0;
            range_image.y = 0;
            range_image.h = bullet.height;
            range_image.w = bullet.width;

            SDL_Rect range_bullet;
            range_bullet.w = bullet.width;
            range_bullet.h = bullet.height;
            range_bullet.x = bullet.bullet_array[i].x;
            range_bullet.y = bullet.bullet_array[i].y;

            if (range_bullet.x + range_bullet.w > BROAD_WIDTH)
            {
                SDL_Rect range_add = range_bullet;
                range_add.x = range_bullet.x - BROAD_WIDTH;
                SDL_RenderCopy(renderer, bullet.image, NULL, &range_add);

                range_bullet.w = BROAD_WIDTH - range_bullet.x;
                range_image.w = range_bullet.w;
            }
            SDL_RenderCopy(renderer, bullet.image, &range_image, &range_bullet);
        }
    }
}
#endif
