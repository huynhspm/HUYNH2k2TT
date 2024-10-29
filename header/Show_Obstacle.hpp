#ifndef _Show_Obstacle_
#define _Show_Obstacle_

void solve_Image_Obstacle(SDL_Renderer *renderer, Obstacle &obstacle, int type)
{
    string s = PICTURE_FOLDER + "/Obstacle";
    s += char((int)type + 48);
    s += ".png";
    const string file = s;
    obstacle.image = loadTexture(file, renderer);
}

void show_Obstacle(SDL_Renderer *renderer, Obstacle &obstacle)
{
    if (!obstacle.visible)
        return;
    for (int i = 0; i < obstacle.obstacle_array.size(); ++i)
    {
        solve_Image_Obstacle(renderer, obstacle, obstacle.obstacle_array[i].type);
        SDL_Rect range_obstacle;

        range_obstacle.w = obstacle.width;
        range_obstacle.h = obstacle.height;
        range_obstacle.x = obstacle.obstacle_array[i].x;
        range_obstacle.y = obstacle.obstacle_array[i].y;
        SDL_RenderCopy(renderer, obstacle.image, NULL, &range_obstacle);
    }
}
#endif
