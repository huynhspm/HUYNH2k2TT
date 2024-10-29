#ifndef _Collision_Plane_And_BulletBoss_
#define _Collision_Plane_And_BulletBoss_

void collision_Plane_And_BulletBoss(Object& plane, Bullet& bullet_boss,
                                    Game &game, Object& boss, vBullet& bullet_plane){
    if(!plane.visible || !bullet_boss.visible) return;

    int X_left = plane.x;
    int Y_up = plane.y;
    int X_right = plane.x + plane.width;
    int Y_down = plane.y + plane.height;
    Rectangle rect1 = Rectangle(X_left, Y_up, X_right, Y_down);

    if(game.level == 3){
        if(game.time % 16 != 15) return;
        int x_left = boss.x;
        int y_up = boss.y + boss.height;
        int x_right = boss.x + boss.width;
        int y_down = BROAD_HEIGHT;
        Rectangle rect2 = Rectangle(x_left, y_up, x_right, y_down);
        if(intersect_Rect(rect1, rect2)) solve_Life(game, plane, bullet_plane);
        return;
    }

    for(int i = 0; i < bullet_boss.bullet_array.size(); ++ i){
        int x_left = bullet_boss.bullet_array[i].x;
        int y_up = bullet_boss.bullet_array[i].y;
        int x_right = bullet_boss.bullet_array[i].x + bullet_boss.width;
        int y_down = bullet_boss.bullet_array[i].y + bullet_boss.height;
        Rectangle rect2 = Rectangle(x_left, y_up, x_right, y_down);

        if(intersect_Rect(rect1, rect2)){
            bullet_boss.bullet_array.erase(bullet_boss.bullet_array.begin() + i);
            i--;
            solve_Life(game, plane, bullet_plane);
        }
    }
}

#endif
