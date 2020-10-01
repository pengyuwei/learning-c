#include <SDL2/SDL.h>

typedef struct {
    int width;
    int height;
    SDL_Window* window;
    SDL_Surface* screenSurface;
} GAME_UI;

int destroy_screen(GAME_UI *gui)
{
    SDL_DestroyWindow( gui->window );
    SDL_Quit();
    return 0;
}

int init_screen(GAME_UI *gui)
{
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return -1;
    } else {
        window = SDL_CreateWindow( "SDL Tutorial", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            gui->width, gui->height, 
            SDL_WINDOW_SHOWN );
        if( window == NULL ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            return -1;
        } else {
            screenSurface = SDL_GetWindowSurface( window );
        }
    }
    gui->window = window;
    gui->screenSurface = screenSurface;

    return 0;
}

int main_loop(GAME_UI *gui)
{
    SDL_FillRect( gui->screenSurface, NULL, SDL_MapRGB( gui->screenSurface->format, 0xFF, 0xFF, 0xFF ) );
    SDL_UpdateWindowSurface( gui->window );
    SDL_Delay( 2000 );

    return 0;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    GAME_UI gui;
    gui.width = 640;
    gui.height = 480;

    ret = init_screen(&gui);
    if (0 == ret) {
        main_loop(&gui);
    }

    destroy_screen(&gui);

    return 0;
}