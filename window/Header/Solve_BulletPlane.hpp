#ifndef _Solve_BulletPlane_
#define _Solve_BulletPlane_

void solve_BulletPlane(Object& plane, vBullet& bullet_plane){
    int cnt = 0;
    for(Bullet& bullet : bullet_plane){
        if(!bullet.visible) continue;

        for(int i = 0; i < bullet.bullet_array.size(); ++ i){
            bullet.bullet_array[i].y -= STEP;
            if(bullet.bullet_array[i].y < 0){
                bullet.bullet_array.erase(bullet.bullet_array.begin() + i);
                i--;
            }
        }
        int x, y;

        if(cnt == 0) x = (plane.x + STEP) % BROAD_WIDTH;
        else if(cnt == 1) x = plane.x;
        else if(cnt == 2) x = (plane.x + (STEP << 1)) % BROAD_WIDTH;
        cnt++;

        y = plane.y - bullet.height;
        bullet.bullet_array.push_back(Data_Bullet{x, y, UP});
    }
}
#endif
