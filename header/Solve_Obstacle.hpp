#ifndef _Solve_Obstacle_
#define _Solve_Obstacle_

void solve_Obstacle(SDL_Renderer * renderer, Obstacle& obstacle, Object& boss, Game& game){
    if(!obstacle.visible) return;

    for(int i = 0; i < obstacle.obstacle_array.size(); ++ i){
        obstacle.obstacle_array[i].y += STEP;
        if(obstacle.obstacle_array[i].y + obstacle.height > BROAD_HEIGHT)
            obstacle.obstacle_array.erase(obstacle.obstacle_array.begin() + i);
    }

    if(game.time % 2) return;

    int x = (rand() % (BROAD_WIDTH / STEP - 1)) * STEP;
    int y = 0;
    Type type;

    int r = rand() % 25;
    if(r == 5 || r == 20) type = HEART;
    else if(r == 10) type = ARMOR;
    else if(r == 15) type = BULLET;
    else type = OBSTACLE;

    obstacle.obstacle_array.push_back(Data_Obstacle{x, y, DOWN, type});

}

#endif

