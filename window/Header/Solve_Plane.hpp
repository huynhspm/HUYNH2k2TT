#ifndef _Solve_Plane_
#define _Solve_Plane_

void solve_Plane(Object& plane, Game& game){
    if(game.mode == PASS_LEVEL){
        plane.y += STEP;
        return;
    }

    if(game.mode == PREPARE_PASS_LEVEL){
        plane.y -= STEP;
        return;
    }

    plane.x = (plane.x + STEP * dx[plane.direct] + BROAD_WIDTH) % BROAD_WIDTH;
    int y = plane.y + STEP * dy[plane.direct];
    if(0 <= y && y + plane.height <= BROAD_HEIGHT) plane.y = y;

    plane.direct = STATIC;
}

#endif
