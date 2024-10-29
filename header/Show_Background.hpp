#ifndef _Show_Background_
#define _Show_Background_

void solve_Image_Background(SDL_Renderer *renderer, Background &background, Game &game)
{
    string s = PICTURE_FOLDER + "/Background";
    s += char(min(3, game.level) + 48);
    s += ".png";

    const string file = s;
    background.image = loadTexture(file, renderer);
}
void show_Background(SDL_Renderer *renderer, Background &background,
                     Game &game)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    SDL_RenderClear(renderer);

    solve_Image_Background(renderer, background, game);
    if (game.mode == PREPARE_PASS_LEVEL || game.mode == PASS_LEVEL)
    {
        background.y = (background.y + STEP) % BROAD_HEIGHT;
    }
    else
        background.y = (background.y + STEP / 4) % BROAD_HEIGHT;

    SDL_Rect range_background;
    range_background.x = background.x;
    range_background.y = background.y;
    range_background.w = BROAD_WIDTH;
    range_background.h = BROAD_HEIGHT;

    SDL_RenderCopy(renderer, background.image, NULL, &range_background);

    range_background.y = background.y - BROAD_HEIGHT;
    if (game.mode == PASS_LEVEL)
    {
        game.level++;
        solve_Image_Background(renderer, background, game);
        game.level--;
        SDL_RenderCopy(renderer, background.image, NULL, &range_background);
    }
    else
    {
        SDL_RenderCopy(renderer, background.image, NULL, &range_background);
    }
}
#endif
