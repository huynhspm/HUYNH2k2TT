#ifndef _Solve_Boss_
#define _Solve_Boss_

void solve_Boss(Object& boss, Game& game){
    if(!boss.visible) return;

    if(game.level == 1 || game.level == 2){
        if(boss.x >= BROAD_WIDTH - STEP - boss.width) boss.direct = LEFT;
        if(boss.x <= 0) boss.direct = RIGHT;
    }
    else if(game.level == 3){
        if(boss.x >= BROAD_WIDTH - STEP - boss.width) boss.direct = LEFT;
        else if(boss.x <= 0) boss.direct = RIGHT;
        else update_Direct(boss.direct, rand() % 2);
    }

    boss.x += STEP * dx[boss.direct];
    boss.y += STEP * dy[boss.direct];
}

#endif
