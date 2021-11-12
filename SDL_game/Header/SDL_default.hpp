#ifndef _SDL_default_
#define _SDL_default_

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 660;
const string WINDOW_TITLE = "SPM GAME BY HUYNHSPM";

void logSDLError(ostream& os,
                 const string &msg, bool fatal){
    os << msg << " Error: " << SDL_GetError() << endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

SDL_Texture* loadTexture(const string &file, SDL_Renderer* renderer){
	SDL_Texture *texture = nullptr;
	SDL_Surface *loadedImage = IMG_Load(file.c_str());
	if (loadedImage != nullptr){
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		if (texture == nullptr)
			logSDLError(cout, "CreateTextureFromSurface", true);
	}
	else  logSDLError(cout, "LoadBMP", true);
	return texture;
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) logSDLError(cout, "SDL_Init", true);

    if (TTF_Init() < 0) logSDLError(cout, "TTF Init", true);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        logSDLError(cout, "Mix GetError", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) logSDLError(cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}

void waitUntilKeyPressed(){
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

#endif

