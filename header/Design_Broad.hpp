#ifndef _Design_Broad_
#define _Design_Broad_

void design_Broad(SDL_Renderer *renderer, Game &game)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, BROAD_WIDTH, 0, BROAD_WIDTH, BROAD_HEIGHT);

    TTF_Font *font = TTF_OpenFont((FONT_FOLDER + "/VeraMoBd.ttf").c_str(), 20);
    SDL_Color color = {243, 156, 18};

    range_LEVEL.x_left = 750, range_LEVEL.y_up = 50;
    show_Text(renderer, "LEVEL : ", color, font, range_LEVEL, false);

    range_LEVEL.x_left = range_LEVEL.x_right + 10;
    string level = change_NumberToString(game.level);
    show_Text(renderer, level, color, font, range_LEVEL, false);

    range_SCORE.x_left = 750, range_SCORE.y_up = 100;
    show_Text(renderer, "SCORE : ", color, font, range_SCORE, false);

    range_SCORE.x_left = range_SCORE.x_right + 10;
    string score = change_NumberToString(game.score - SCORE_LEVEL[game.level_start - 1]);
    show_Text(renderer, score, color, font, range_SCORE, false);

    range_LIFE.x_left = 750, range_LIFE.y_up = 150;
    show_Text(renderer, "LIFE : ", color, font, range_LIFE, false);
    range_LIFE.x_left = range_LIFE.x_right + 10;
    string life = change_NumberToString(game.life);
    show_Text(renderer, life, color, font, range_LIFE, false);

    font = TTF_OpenFont((FONT_FOLDER + "/VeraMoBd.ttf").c_str(), 30);
    show_Text(renderer, "PAUSE", color, font, button_PAUSE, true);

    if (game.music == PAUSE)
    {
        show_Text(renderer, "SOUND ON", color, font, button_SOUND, true);
    }
    else
    {
        show_Text(renderer, "SOUND OFF", color, font, button_SOUND, true);
    }

    show_Text(renderer, "REPLAY", color, font, button_REPLAY, true);
    show_Text(renderer, "QUIT", color, font, button_QUIT, true);

    if (game.mode == FINISH)
    {
        if (game.life > 0)
        {
            range_WIN_GAME.x_left = 750, range_WIN_GAME.y_up = 450;
            show_Text(renderer, "WIN_GAME", color, font, range_WIN_GAME, false);
        }
        else
        {
            range_GAME_OVER.x_left = 750, range_GAME_OVER.y_up = 450;
            show_Text(renderer, "GAME_OVER", color, font, range_GAME_OVER, false);
        }
    }
}

#endif
