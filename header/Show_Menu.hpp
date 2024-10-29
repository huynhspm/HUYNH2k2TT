#ifndef _Show_Menu_
#define _Show_Menu_

Rectangle range_NEWGAME = Rectangle(350, 100, 0, 0);
Rectangle range_CHOOSELEVEL = Rectangle(280, 200, 0, 0);
Rectangle range_HIGHSCORE = Rectangle(320, 300, 0, 0);
Rectangle range_ABOUT = Rectangle(400, 400, 0, 0);
Rectangle range_1 = Rectangle(900, 100, 0, 0);
Rectangle range_2 = Rectangle(900, 200, 0, 0);
Rectangle range_3 = Rectangle(900, 300, 0, 0);

void show_Menu(SDL_Renderer *renderer, int &x, int &y, bool chooselevel, int level_start)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    SDL_RenderClear(renderer);

    SDL_Color color;
    const int size_text = 50;
    TTF_Font *font = TTF_OpenFont((FONT_FOLDER + "/ChockABlockNF.ttf").c_str(), size_text);

    if (target_Range(x, y, range_NEWGAME))
        color = {192, 192, 192};
    else
        color = {128, 155, 0};
    show_Text(renderer, "NEW GAME", color, font, range_NEWGAME, false);

    if (target_Range(x, y, range_CHOOSELEVEL))
        color = {192, 192, 192};
    else
        color = {128, 155, 0};
    show_Text(renderer, "CHOOSE LEVEL", color, font, range_CHOOSELEVEL, false);

    if (chooselevel)
    {
        TTF_Font *font1 = TTF_OpenFont((FONT_FOLDER + "/VeraMoBd.ttf").c_str(), 50);

        if (level_start == 1)
            color = {192, 192, 192};
        else
            color = {0, 128, 128};
        show_Text(renderer, "1", color, font1, range_1, false);

        if (level_start == 2)
            color = {192, 192, 192};
        else
            color = {0, 128, 128};
        show_Text(renderer, "2", color, font1, range_2, false);

        if (level_start == 3)
            color = {192, 192, 192};
        else
            color = {0, 128, 128};
        show_Text(renderer, "3", color, font1, range_3, false);
    }

    if (target_Range(x, y, range_HIGHSCORE))
    {
        color = {255, 106, 106};
        TTF_Font *font1 = TTF_OpenFont((FONT_FOLDER + "/spm.otf").c_str(), 25);
        Rectangle range = Rectangle(70, 550, 0, 0);
        ifstream infile;
        int data;
        infile.open(SCORE_PATH);
        for (int i = 1; i <= 5; ++i)
        {
            show_Text(renderer, "RANK ", color, font1, range, false);
            range.x_left = range.x_right;
            infile >> data;
            string s;
            s += change_NumberToString(i);
            s += " :  ";
            s += change_NumberToString(data);
            show_Text(renderer, s, color, font1, range, false);
            range.x_left = range.x_right + 30;
        }
        color = {192, 192, 192};
    }
    else
        color = {128, 155, 0};
    show_Text(renderer, "HIGH SCORE", color, font, range_HIGHSCORE, false);

    if (target_Range(x, y, range_ABOUT))
    {
        Rectangle rect = Rectangle(80, 100, 0, 0);
        color = {128, 0, 0};
        TTF_Font *font1 = TTF_OpenFont((FONT_FOLDER + "/bloofs.ttf").c_str(), 50);
        show_Text(renderer, "MOVE", color, font1, rect, false);

        rect = Rectangle(50, 530, 0, 0);
        show_Text(renderer, "OBSTACLE", color, font1, rect, false);

        SDL_Rect range;
        range.x = 50;
        range.y = 180;
        range.w = 200;
        range.h = 150;

        SDL_Texture *image = loadTexture(PICTURE_FOLDER + "/move_1.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        range.y = 330;
        image = loadTexture(PICTURE_FOLDER + "/move_2.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        range.x = 80;
        range.y = 600;
        range.w = 50;
        range.h = 50;
        image = loadTexture(PICTURE_FOLDER + "/Bullet_Boss21.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        range.x = 250;
        image = loadTexture(PICTURE_FOLDER + "/Bullet_Boss22.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        range.x = 160;
        range.y = 620;
        range.w = 20;
        range.h = 20;
        image = loadTexture(PICTURE_FOLDER + "/Bullet_Boss1.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        range.x = 200;
        range.y = 620;
        image = loadTexture(PICTURE_FOLDER + "/Obstacle2.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        rect = Rectangle(700, 530, 0, 0);
        show_Text(renderer, "ITEM", color, font1, rect, false);

        range.x = 710;
        range.y = 620;
        image = loadTexture(PICTURE_FOLDER + "/Obstacle0.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        range.x = 760;
        image = loadTexture(PICTURE_FOLDER + "/Obstacle1.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        range.x = 810;
        image = loadTexture(PICTURE_FOLDER + "/Obstacle3.png", renderer);
        SDL_RenderCopy(renderer, image, NULL, &range);

        color = {192, 192, 192};
    }
    else
        color = {128, 155, 0};
    show_Text(renderer, "ABOUT", color, font, range_ABOUT, false);

    SDL_RenderPresent(renderer);
}

#endif
