#ifndef _Solve_Pause_
#define _Solve_Pause_

void drawTriangle(SDL_Renderer *renderer, int x, int y)
{
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j <= i; ++j)
            SDL_RenderDrawPoint(renderer, x + j, y + i);

    y += 39;
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j <= i; ++j)
            SDL_RenderDrawPoint(renderer, x + j, y - i);
}
void solve_Pause(SDL_Renderer *renderer, Game &game)
{
    SDL_Rect range;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    range.x = 135;
    range.y = 200;
    range.w = 400;
    range.h = 300;
    SDL_RenderFillRect(renderer, &range);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    range.x = 140;
    range.y = 205;
    range.w = 390;
    range.h = 290;
    SDL_RenderFillRect(renderer, &range);

    SDL_Color color;
    color = {255, 255, 255};
    TTF_Font *font = TTF_OpenFont((FONT_FOLDER + "/bloofs.ttf").c_str(), 50);

    Rectangle rect = Rectangle(230, 270, 0, 0);
    show_Text(renderer, "RESUME", color, font, rect, false);

    rect.y_up = 370;
    show_Text(renderer, "REPLAY", color, font, rect, false);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    drawTriangle(renderer, 180, 280);

    SDL_RenderPresent(renderer);
    SDL_Event e;
    bool Option = 0;

    while (true)
    {
        if (SDL_WaitEvent(&e) == 0)
            continue;
        if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.scancode == SDL_SCANCODE_RETURN)
            {
                if (Option)
                    game.mode = REPLAY;
                else
                    game.mode = game.last_mode;
                break;
            };

            bool change = false;
            if (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
                change = true;
            if (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s)
                change = true;

            if (change)
            {
                Option ^= 1;
                if (Option)
                {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    drawTriangle(renderer, 180, 380);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    drawTriangle(renderer, 180, 280);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    drawTriangle(renderer, 180, 280);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    drawTriangle(renderer, 180, 380);
                }
                SDL_RenderPresent(renderer);
            }
        }
    }
}
#endif
