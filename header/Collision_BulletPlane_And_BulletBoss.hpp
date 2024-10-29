#ifndef _Collision_BulletPlane_And_BulletBoss_
#define _Collision_BulletPlane_And_BulletBoss_

void collision_BulletPlane_And_BulletBoss(vBullet& bullet_plane, Bullet& bullet_boss, Game& game, Object& boss){
    if(!bullet_boss.visible) return;

    for(Bullet& bullet : bullet_plane){
        if(!bullet.visible) continue;

        if(game.level == 3){
            if(game.time % 16 != 15) continue;

            int x_left = boss.x;
            int y_up = boss.y + boss.height;
            int x_right = boss.x + boss.width;
            int y_down = BROAD_HEIGHT;
            Rectangle rect1 = Rectangle(x_left, y_up, x_right, y_down);

            for(int i = 0; i < bullet.bullet_array.size(); ++ i){
                int X_left = bullet.bullet_array[i].x;
                int Y_up = bullet.bullet_array[i].y;
                int X_right = X_left + bullet.width;
                int Y_down = Y_up + bullet.height;
                Rectangle rect2 = Rectangle(X_left, Y_up, X_right, Y_down);

                if(intersect_Rect(rect1, rect2)){
                    bullet.bullet_array.erase(bullet.bullet_array.begin() + i);
                    i--;
                }
            }
            continue;
        }

        for(int i = 0; i < bullet_boss.bullet_array.size(); ++ i){
            if(game.level == 1){
                for(int j = 0; j < bullet.bullet_array.size(); ++ j){
                    if(bullet.bullet_array[j].x != bullet_boss.bullet_array[i].x) continue;
                    if(bullet.bullet_array[j].y - bullet_boss.bullet_array[i].y <= STEP &&
                    bullet_boss.bullet_array[i].y - bullet.bullet_array[j].y <= STEP){
                        bullet.bullet_array.erase(bullet.bullet_array.begin() + j);
                        j--;
                    }
                }
            }
            else if(game.level == 2){
                int x_left = bullet_boss.bullet_array[i].x;
                int y_up = bullet_boss.bullet_array[i].y;
                int x_right = x_left + bullet_boss.width;
                int y_down = y_up + bullet_boss.height;
                Rectangle rect1 = Rectangle(x_left, y_up, x_right, y_down);

                for(int j = 0; j < bullet.bullet_array.size(); ++ j){
                    int X_left = bullet.bullet_array[j].x;
                    int Y_up = bullet.bullet_array[j].y;
                    int X_right = X_left + bullet.width;
                    int Y_down = Y_up + bullet.height;
                    Rectangle rect2 = Rectangle(X_left, Y_up, X_right, Y_down);

                    if(intersect_Rect(rect1, rect2)){
                        bullet.bullet_array.erase(bullet.bullet_array.begin() + j);
                        j--;
                    }
                }
            }
        }
    }
}
#endif
