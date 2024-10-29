#ifndef _Collision_BulletPlane_And_Obstacle_
#define _Collision_BulletPlane_And_Obstacle_

void collision_BulletPlane_And_Obstacle(vBullet& bullet_plane, Obstacle& obstacle, Game& game, Object& plane){
    bool add_bullet = false;
    for(Bullet& bullet : bullet_plane){
        if(!bullet.visible || !obstacle.visible) continue;

        for(int i = 0; i < bullet.bullet_array.size(); ++ i){
            for(int j = 0; j < obstacle.obstacle_array.size();  ++ j){
                if(bullet.bullet_array[i].x != obstacle.obstacle_array[j].x) continue;

                if(bullet.bullet_array[i].y - obstacle.obstacle_array[j].y <= STEP &&
                   obstacle.obstacle_array[j].y - bullet.bullet_array[i].y <= STEP){

                    if(obstacle.obstacle_array[j].type != OBSTACLE) game.music = GET_ITEM;

                    if(obstacle.obstacle_array[j].type == HEART) game.life ++;
                    else if(obstacle.obstacle_array[j].type == OBSTACLE) game.score ++;
                    else if(obstacle.obstacle_array[j].type == ARMOR) plane.type = ARMOR;
                    else if(obstacle.obstacle_array[j].type == BULLET) add_bullet = true;

                    bullet.bullet_array.erase(bullet.bullet_array.begin() + i);
                    obstacle.obstacle_array.erase(obstacle.obstacle_array.begin() + j);
                    i--;
                    break;
                }
            }
        }
    }

    if(!add_bullet || bullet_plane.size() > 2) return;
    bullet_plane.push_back(Bullet{true, BULLET_PLANE_WIDTH , BULLET_PLANE_HEIGHT});
}
#endif
