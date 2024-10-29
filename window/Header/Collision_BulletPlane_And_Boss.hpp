#ifndef _Collision_BulletPlane_And_Boss_
#define _Collision_BulletPlane_And_Boss_

void solve_Life(Game &game, Object &plane, vBullet& bullet_plane){
    if(plane.type == ARMOR)  plane.type = SIMPLE;
    else{
        if(game.time_Immortal > 0) return;
        game.life --;
        game.last_mode = game.mode;
        game.mode = EXPLOSION;
        game.time_Immortal = TIME_IMMORTAL;
        if(bullet_plane.size() > 1) bullet_plane.pop_back();
    }
}

void collision_BulletPlane_And_Boss(vBullet& bullet_plane, Object& boss, Game& game){
    for(Bullet& bullet : bullet_plane){
        if(!bullet.visible || !boss.visible) return;

        int X_left = boss.x;
        int Y_up = boss.y;
        int X_right = boss.x + boss.width;
        int Y_down = boss.y + boss.height;
        Rectangle rect1 = Rectangle(X_left, Y_up, X_right, Y_down);

        for(int i = 0; i < bullet.bullet_array.size(); ++ i){
            int x_left = bullet.bullet_array[i].x;
            int y_up = bullet.bullet_array[i].y;
            int x_right = bullet.bullet_array[i].x + bullet.width;
            int y_down = bullet.bullet_array[i].y + bullet.height;
            Rectangle rect2 = Rectangle(x_left, y_up, x_right, y_down);

            if(intersect_Rect(rect1, rect2)){
                bullet.bullet_array.erase(bullet.bullet_array.begin() + i);
                i--;
                game.life_boss --;
            }
        }
    }
}
#endif

