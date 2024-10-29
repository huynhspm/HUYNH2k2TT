#ifndef _Solve_BulletBoss_
#define _Solve_BulletBoss_


void solve_BulletBoss(Object& boss, Bullet& bullet_boss, Game& game){
    if(!bullet_boss.visible || game.level == 3) return;

    for(int i = 0; i < bullet_boss.bullet_array.size(); ++ i){
        int id = bullet_boss.bullet_array[i].direct;

        if(game.level == 1){
            bullet_boss.bullet_array[i].x += dx[id] * STEP;
            bullet_boss.bullet_array[i].y += dy[id] * STEP;

            if(bullet_boss.bullet_array[i].y > BROAD_HEIGHT - bullet_boss.height){
                bullet_boss.bullet_array.erase(bullet_boss.bullet_array.begin() + i);
                i--;
            }
        }
        else if(game.level == 2){
            if(game.time % 2) continue;
            int x = bullet_boss.bullet_array[i].x + dx[id] * STEP;
            int y = bullet_boss.bullet_array[i].y + dy[id] * STEP;

            while(x < 0 || x > BROAD_WIDTH - bullet_boss.width ||
                y <= boss.height || y > BROAD_HEIGHT - bullet_boss.height){
                id = rand() % 4 + 4;
                x = bullet_boss.bullet_array[i].x + dx[id] * STEP;
                y = bullet_boss.bullet_array[i].y + dy[id] * STEP;
            }
            update_Direct(bullet_boss.bullet_array[i].direct, id);
            bullet_boss.bullet_array[i].x = x;
            bullet_boss.bullet_array[i].y = y;
        }
    }

    if(game.time % 3 == 0){
        if(game.level == 1){
            int x = (boss.x + (boss.width - bullet_boss.width) / 2) % BROAD_WIDTH;
            int y = boss.y + boss.height;
            bullet_boss.bullet_array.push_back(Data_Bullet{x, y, DOWN});
        }
        else if(game.level == 2){
            if(bullet_boss.bullet_array.size() > 5) return;

            int x = (boss.x + (boss.width - bullet_boss.width) / 2) % BROAD_WIDTH;
            int y = boss.y + boss.height + 1;
            Direct direct;
            update_Direct(direct, rand() % 4 + 4);
            bullet_boss.bullet_array.push_back(Data_Bullet{x, y, direct});
        }
    }
}
#endif


