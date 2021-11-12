#ifndef _Solve_Level_
#define _Solve_Level_

void start_Boss(Game& game, Object& boss, Bullet& bullet_boss, Obstacle& obstacle){
    game.life_boss = LIFE_BOSS[game.level];
    game.time_Immortal = 0;
    game.mode = BATTLE_BOSS;
    game.time = 0;

    boss.visible = true;
    boss.x = 8*STEP;
    boss.y = 10;
    bullet_boss.visible = true;
    bullet_boss.height = BULLET_BOSS_HEIGHT[game.level];
    bullet_boss.width = BULLET_BOSS_WIDTH[game.level];

    obstacle.visible = false;
    while(!obstacle.obstacle_array.empty()) obstacle.obstacle_array.pop_back();
}

void end_Boss(Game& game, Object& boss, Bullet& bullet_boss, Obstacle& obstacle,
              vBullet& bullet_plane, Object& plane){
    game.time_Immortal = 0;
    game.mode = DEFEAT_BOSS;

    for(Bullet& bullet : bullet_plane){
        bullet.visible = false;
        while(!bullet.bullet_array.empty()) bullet.bullet_array.pop_back();
    }
    bullet_boss.visible = false;
    while(!bullet_boss.bullet_array.empty()) bullet_boss.bullet_array.pop_back();
}

void solve_Level(Game& game, Object& boss, Bullet& bullet_boss, Obstacle& obstacle,
                 vBullet& bullet_plane, Object& plane, Background& background){
    if(game.life <= 0) game.mode = FINISH;

    if(game.mode == BATTLE_NORMAL || (game.mode == EXPLOSION && game.last_mode == BATTLE_NORMAL)){
        if(game.score >= SCORE_LEVEL[game.level]) start_Boss(game, boss, bullet_boss, obstacle);
    }
    else if(game.mode == BATTLE_BOSS || (game.mode == EXPLOSION && game.last_mode == BATTLE_BOSS)){
        if(game.life_boss <= 0) end_Boss(game, boss, bullet_boss, obstacle, bullet_plane, plane);
    }

    if(game.mode == PREPARE_PASS_LEVEL){
        if(background.y + STEP >= BROAD_HEIGHT && plane.y < -PLANE_HEIGHT){
            plane.y = -PLANE_HEIGHT;
            game.mode = PASS_LEVEL;
        }
    }
    else if(game.mode == PASS_LEVEL){
        if(background.y + STEP >= BROAD_HEIGHT){
            plane.y = BROAD_HEIGHT - PLANE_HEIGHT;
            game.mode = BATTLE_NORMAL;
            game.level ++;
            obstacle.visible = true;
            for(Bullet& bullet : bullet_plane){
                bullet.visible = true;
            }
            game.music = NORMAL;
        }
    }
    else if(game.mode == EXPLOSION){
        if(--game.time_Immortal <= 0){
            game.mode = game.last_mode;
        }
    }
}
#endif

