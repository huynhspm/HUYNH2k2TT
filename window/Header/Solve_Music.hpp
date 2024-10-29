#ifndef _Start_Music_
#define _Start_Music_

void solve_Music(Mix_Music* music_pass_level, Mix_Music* music_explosion,
                 Mix_Music* music_get_item, Mix_Chunk* music_normal, Game& game, Object& boss){
    if(game.mode == EXPLOSION && game.time_Immortal + 1 == TIME_IMMORTAL){
        if(Mix_PlayingMusic()) Mix_HaltMusic();
        Mix_PlayMusic(music_explosion, 0);
        SDL_Delay(500);
        Mix_HaltMusic();
    }

    if(game.mode == DEFEAT_BOSS){
        if(Mix_PlayingMusic()) Mix_HaltMusic();
        Mix_PlayMusic(music_explosion, 0);
        SDL_Delay(1000);
        Mix_HaltMusic();
        game.mode = PREPARE_PASS_LEVEL;
        game.music = PASS_LEVEL;
        boss.visible = false;
        if(game.level == 3 && game.mode == PREPARE_PASS_LEVEL) game.mode = FINISH;
    }

    if(game.music == PAUSE) Mix_HaltChannel(-1);
    //else if(game.music == START && !Mix_Playing(-1)) Mix_PlayChannel(-1, music_normal, -1);

    if(game.music == PASS_LEVEL){
        if(game.level == 3) return;
        if(Mix_PlayingMusic()) Mix_HaltMusic();
        Mix_PlayMusic(music_pass_level, 0);
        game.music = NORMAL;
    }

    if(game.music == GET_ITEM){
        if(Mix_PlayingMusic()) Mix_HaltMusic();
        Mix_PlayMusic(music_get_item, 0);
        game.music = NORMAL;
    }
}

#endif
