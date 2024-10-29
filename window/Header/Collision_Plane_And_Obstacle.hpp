#ifndef _Collision_Plane_And_Obstacle_
#define _Collision_Plane_And_Obstacle_

void collision_Plane_And_Obstacle(Object& plane, Obstacle& obstacle, Game& game, vBullet& bullet_plane){
    if(!plane.visible || !obstacle.visible) return;

    int X_left = plane.x;
    int Y_up = plane.y;
    int X_right = plane.x + plane.width;
    int Y_down = plane.y + plane.height;
    Rectangle rect1 = Rectangle(X_left, Y_up, X_right, Y_down);

    for(int i = 0; i < obstacle.obstacle_array.size(); ++ i){
        if(obstacle.obstacle_array[i].type != OBSTACLE) continue;

        int x_left = obstacle.obstacle_array[i].x;
        int y_up = obstacle.obstacle_array[i].y;
        int x_right = obstacle.obstacle_array[i].x + obstacle.width;
        int y_down = obstacle.obstacle_array[i].y + obstacle.height;
        Rectangle rect2 = Rectangle(x_left, y_up, x_right, y_down);

        if(intersect_Rect(rect1, rect2)){
            obstacle.obstacle_array.erase(obstacle.obstacle_array.begin() + i);
            i--;
            solve_Life(game, plane, bullet_plane);
        }
    }
}
#endif
