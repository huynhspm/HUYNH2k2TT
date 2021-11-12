#ifndef _Start_Game_
#define _Start_Game_

void start_Game(SDL_Renderer* renderer, Object& plane, vBullet& bullet_plane, Obstacle& obstacle,
                   Object& boss, Bullet& bullet_boss, Game& game, Background& background){

    Mix_Music* music_pass_level = Mix_LoadMUS("Music/PassLevel.mp3");
    Mix_Music* music_explosion = Mix_LoadMUS("Music/Explosion.mp3");
    Mix_Music* music_get_item = Mix_LoadMUS("Music/GetItem.mp3");
    Mix_Chunk* music_normal = Mix_LoadWAV("Music/Normal.wav");

    while (true) {
        SDL_Delay(80);
        game.time ++;

        solve_Event(plane, game);

        if(game.music == START && !Mix_Playing(-1)) Mix_PlayChannel(-1, music_normal, -1);
        if(game.mode == PAUSE) solve_Pause(renderer, game);
        if(game.mode == FINISH || game.mode == QUIT || game.mode == REPLAY){
            end_Game(renderer, game);
            break;
        }

        solve_Plane(plane, game);
        solve_BulletPlane(plane, bullet_plane);

        solve_Obstacle(renderer, obstacle, boss, game);

        solve_Boss(boss, game);
        solve_BulletBoss(boss, bullet_boss, game);

        solve_Collision(plane, bullet_plane, obstacle, boss, bullet_boss, game);

        solve_Level(game, boss, bullet_boss, obstacle, bullet_plane, plane, background);

        refreshScreen(renderer, plane, bullet_plane, obstacle, boss, bullet_boss, game, background);

        solve_Music(music_pass_level, music_explosion, music_get_item, music_normal, game, boss);
    }
}

#endif


