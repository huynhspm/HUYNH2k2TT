#ifndef _Public_
#define _Public_

const int BROAD_WIDTH = 640;
const int BROAD_HEIGHT = 660;

const int PLANE_WIDTH = 100;
const int PLANE_HEIGHT = 100;

const int BOSS_WIDTH = 100;
const int BOSS_HEIGHT = 100;

const int BULLET_PLANE_WIDTH = 20;
const int BULLET_PLANE_HEIGHT = 20;


const int BULLET_BOSS_WIDTH[] = {0, 20, 50, 0};
const int BULLET_BOSS_HEIGHT[] = {0, 20, 50, 0};


const int OBSTACLE_WIDTH = 20;
const int OBSTACLE_HEIGHT = 20;

const int N = 50;
const int STEP = 40;

const int SCORE_LEVEL[] = {0, 30, 60, 90};
const int LIFE_BOSS[] = {0, 50, 60, 70};
const int TIME_IMMORTAL = 10;

enum Mode{
    BATTLE_NORMAL,
    BATTLE_BOSS,
    EXPLOSION,
    PAUSE,
    FINISH,
    REPLAY,
    QUIT,
    PREPARE_PASS_LEVEL,
    PASS_LEVEL,
    START,
    GET_ITEM,
    NORMAL,
    DEFEAT_BOSS
};

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};

enum Direct{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    LEFT_DOWN,
    RIGHT_DOWN,
    LEFT_UP,
    RIGHT_UP,
    STATIC
};

void update_Direct(Direct &direct, int cnt){
    if(cnt == 0) direct = LEFT;
    else if(cnt == 1) direct = RIGHT;
    else if(cnt == 2) direct = UP;
    else if(cnt == 3) direct = DOWN;
    else if(cnt == 4) direct = LEFT_DOWN;
    else if(cnt == 5) direct = RIGHT_DOWN;
    else if(cnt == 6) direct = LEFT_UP;
    else if(cnt == 7) direct = RIGHT_UP;
}

enum Type{
    HEART,
    ARMOR,
    OBSTACLE,
    BULLET,
    SIMPLE
};

struct Data_Bullet{
    int x, y;
    Direct direct;
};


struct Bullet{
    bool visible;
    int width, height;
    SDL_Texture* image;
    vector<Data_Bullet> bullet_array;
    Bullet(bool visible, int width, int height){
        this -> visible = visible;
        this -> width = width;
        this -> height = height;
    }
};

#define vBullet vector<Bullet>

struct Data_Obstacle{
    int x, y;
    Direct direct;
    Type type;
};

struct Obstacle{
    bool visible;
    int width, height;
    SDL_Texture* image;
    vector<Data_Obstacle> obstacle_array;
    Obstacle(bool visible, int width, int height){
        this -> visible = visible;
        this -> width = width;
        this -> height = height;
    }
};

struct Object{
    bool visible;
    Type type;
    int x, y, width, height;
    Direct direct;
    SDL_Texture* image;
    SDL_Texture* armor;
    Object(bool visible, int x, int y, int width, int height, Type type, Direct direct){
        this -> visible = visible;
        this -> x = x;
        this -> y = y;
        this -> width = width;
        this -> height = height;
        this -> type = type;
        this -> direct = direct;
    }
};

struct Game{
    int level, life, score, life_boss, time, time_Immortal, level_start;
    Mode mode, last_mode, music;
    Game(int level, int life, int score, int life_boss, int time, Mode mode, int time_Immortal, Mode music){
        this -> level = level;
        this -> level_start = level;
        this -> life = life;
        this -> score = score;
        this -> life_boss = life_boss;
        this -> time = time;
        this -> mode = mode;
        this -> last_mode = mode;
        this -> time_Immortal = time_Immortal;
        this -> music = music;
    }
};

struct Rectangle{
    int x_left, y_up, x_right, y_down;
    Rectangle(int x_left, int y_up, int x_right, int y_down){
        this -> x_left = x_left;
        this -> y_up = y_up;
        this -> x_right = x_right;
        this -> y_down = y_down;
    }
    Rectangle(){

    }
};

struct Background{
    int x, y;
    SDL_Texture* image;
    Background(int x, int y){
        this -> x = x;
        this -> y = y;
    }
};

Rectangle button_SOUND = Rectangle(830, 250, 0, 0);
Rectangle button_PAUSE = Rectangle(700, 250, 0, 0);
Rectangle button_REPLAY = Rectangle(700, 330, 0, 0);
Rectangle button_QUIT = Rectangle(880, 330, 0, 0);
Rectangle range_LEVEL, range_SCORE, range_LIFE, range_GAME_OVER, range_WIN_GAME;

void show_Text(SDL_Renderer* renderer, string text, SDL_Color color, TTF_Font* font, Rectangle& range, bool button){
    if(font == NULL) logSDLError(cout, "TTF OpenFont", true);

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	int width, height;
    TTF_SizeText(font, text.c_str(), &width, &height);

    range.x_right = range.x_left + width;
    range.y_down = range.y_up + height;

    SDL_Rect filled_rect;
    filled_rect.x = range.x_left;
    filled_rect.y = range.y_up;
    filled_rect.h = height;
    filled_rect.w = width;
    if(!button){
        SDL_RenderCopy(renderer, texture, NULL, &filled_rect);
    }
    else{
        SDL_SetRenderDrawColor(renderer, 250, 0, 0, 250);
        SDL_RenderFillRect(renderer, &filled_rect);

        filled_rect.x += 3;
        filled_rect.y += 3;
        filled_rect.w -= 6;
        filled_rect.h -= 6;

        SDL_SetRenderDrawColor(renderer, 0, 100, 100, 20);
        SDL_RenderFillRect(renderer, &filled_rect);

        SDL_RenderCopy(renderer, texture, NULL, &filled_rect);
    }
}

bool intersect_Rect(Rectangle& rect1, Rectangle& rect2){
    if(rect1.x_right > BROAD_WIDTH){
        int x_left_Max = max(rect1.x_left, rect2.x_left);
        int x_right_Min = min(BROAD_WIDTH, rect2.x_right);

        int x_left_MAX = max(0, rect2.x_left);
        int x_right_MIN = min(rect1.x_right - BROAD_WIDTH, rect2.x_right);

        if(x_left_Max >= x_right_Min && x_left_MAX >= x_right_MIN) return false;
    }
    else{
        int x_left_Max = max(rect1.x_left, rect2.x_left);
        int x_right_Min = min(rect1.x_right, rect2.x_right);
        if(x_left_Max >= x_right_Min) return false;
    }

    int y_up_Max = max(rect1.y_up, rect2.y_up);
    int y_down_Min = min(rect1.y_down, rect2.y_down);
    if(y_up_Max >= y_down_Min) return false;

    return true;
}

bool target_Range(int x, int y, Rectangle range){
    if((range.x_left < x && x < range.x_right)
       && (range.y_up < y && y < range.y_down)) return true;
    return false;
}


string change_NumberToString(int number){
    number = max(number, 0);
    string res;
    while(number > 0){
        res = char(number % 10 + 48) + res;
        number /= 10;
    }
    if(res.empty()) res = "0";
    return res;
}
#endif
