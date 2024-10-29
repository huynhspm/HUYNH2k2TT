#ifndef _End_Game_
#define _End_Game_

void end_Game(SDL_Renderer *renderer, Game &game)
{
    int socre[6];
    ifstream infile;
    infile.open("score.text");

    int high_score[6], check = 0, your_score = game.score;
    for (int i = 1; i <= 5; ++i)
    {
        infile >> high_score[i];
        if (game.score > high_score[i])
        {
            if (!check)
                check = (i == 1) ? 2 : 1;
            swap(game.score, high_score[i]);
        }
    }
    infile.close();

    ofstream outfile;
    outfile.open("score.text");
    for (int i = 1; i <= 5; ++i)
        outfile << high_score[i] << endl;
    outfile.close();

    SDL_Rect range;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    range.x = 135;
    range.y = 200;
    range.w = 500;
    range.h = 300;
    SDL_RenderFillRect(renderer, &range);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    range.x = 140;
    range.y = 205;
    range.w = 490;
    range.h = 290;
    SDL_RenderFillRect(renderer, &range);

    SDL_Color color;
    color = {255, 255, 255};
    TTF_Font *font = TTF_OpenFont((FONT_FOLDER + "/spm.otf").c_str(), 50);

    Rectangle rect = Rectangle(230, 270, 0, 0);

    if (!check)
        show_Text(renderer, "YOUR SCORE", color, font, rect, false);
    else if (check == 1)
        show_Text(renderer, "HIGH SCORE", color, font, rect, false);
    else if (check == 2)
        show_Text(renderer, "NEW RECORD", color, font, rect, false);

    rect.x_left = 330;
    rect.y_up = 370;
    string score = change_NumberToString(your_score);
    while (score.size() < 3)
        score = "0" + score;
    show_Text(renderer, score, color, font, rect, false);

    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    game.mode = FINISH;
}

#endif
