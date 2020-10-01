#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

typedef struct {
    SDL_Window* window;
    SDL_Surface* screenSurface;
} GAME_UI;

int destroy_screen(GAME_UI *gui)
{
    // //Destroy window
    // SDL_DestroyWindow( gui->window );
    // //Quit SDL subsystems
    // SDL_Quit();
    return 0;
}

int init_screen(GAME_UI *gui)
{
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    // SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return -1;}
    // } else {
    //     //Create window
    //     window = SDL_CreateWindow( "SDL Tutorial", 
    //         SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
    //         SCREEN_WIDTH, SCREEN_HEIGHT, 
    //         SDL_WINDOW_SHOWN );
    //     if( window == NULL ) {
    //         printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    //         return -1;
    //     } else {
    //         //Get window surface
    //         screenSurface = SDL_GetWindowSurface( window );
    //     }
    // }
    gui->window = window;
    // gui->screenSurface = screenSurface;

    return 0;
}

int main_loop(GAME_UI *gui)
{
    // //Fill the surface white
    // SDL_FillRect( gui->screenSurface, NULL, SDL_MapRGB( gui->screenSurface->format, 0xFF, 0xFF, 0xFF ) );
    // //Update the surface
    // SDL_UpdateWindowSurface( gui->window );
    // //Wait two seconds
    // SDL_Delay( 2000 );

    return 0;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    GAME_UI gui;

    ret = init_screen(&gui);
    if (0 == ret) {
        main_loop(&gui);
    }

    destroy_screen(&gui);

    return 0;
}