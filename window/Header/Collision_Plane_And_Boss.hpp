#ifndef _Collision_Plane_And_Boss_
#define _Collision_Plane_And_Boss_

void collision_Plane_And_Boss(Object& plane, Object& boss, Game& game, vBullet& bullet_plane){
    if(!plane.visible || !boss.visible) return;
    int X_left = plane.x;
    int Y_up = plane.y;
    int X_right = plane.x + plane.width;
    int Y_down = plane.y + plane.height;
    Rectangle rect1 = Rectangle(X_left, Y_up, X_right, Y_down);

    int x_left = boss.x;
    int y_up = boss.y;
    int x_right = boss.x + boss.width;
    int y_down = boss.y + boss.height;
    Rectangle rect2 = Rectangle(x_left, y_up, x_right, y_down);

    if(intersect_Rect(rect1, rect2)) solve_Life(game, plane, bullet_plane);
}
#endif
