#ifndef _Solve_Collision_
#define _Solve_Collision_

#include "Collision_BulletPlane_And_Boss.hpp"
#include "Collision_BulletPlane_And_Obstacle.hpp"
#include "Collision_BulletPlane_And_BulletBoss.hpp"
#include "Collision_Plane_And_Obstacle.hpp"
#include "Collision_Plane_And_Boss.hpp"
#include "Collision_Plane_And_BulletBoss.hpp"

void solve_Collision(Object& plane, vBullet& bullet_plane, Obstacle& obstacle,
                     Object& boss, Bullet& bullet_boss, Game& game){

    collision_BulletPlane_And_Boss(bullet_plane, boss, game);

    collision_BulletPlane_And_Obstacle(bullet_plane, obstacle, game, plane);

    collision_BulletPlane_And_BulletBoss(bullet_plane, bullet_boss, game, boss);

    collision_Plane_And_Obstacle(plane, obstacle, game, bullet_plane);

    collision_Plane_And_Boss(plane, boss, game, bullet_plane);

    collision_Plane_And_BulletBoss(plane, bullet_boss, game, boss, bullet_plane);
}

#endif
