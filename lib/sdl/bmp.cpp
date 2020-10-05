#include <SDL2/SDL.h>

// TODO:Texture Loading and Rendering

typedef struct {
    int width;
    int height;
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Surface* player1;
    SDL_Surface* player2;
} GAME_UI;

int destroy_screen(GAME_UI* gui)
{
    SDL_DestroyWindow( gui->window );
    SDL_Quit();
    return 0;
}

int init_screen(GAME_UI* gui)
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

bool loadMedia(GAME_UI* gui)
{
    bool success = true;

    //Load splash image
    gui->player1 = SDL_LoadBMP( "resource/01.bmp" );
    if( gui->player1 == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "resource/1.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

int main_loop(GAME_UI* gui)
{
    SDL_FillRect( gui->screenSurface, NULL, SDL_MapRGB( gui->screenSurface->format, 0x1E, 0x1E, 0x1E ) );
    
    if (loadMedia(gui)) {
        printf("load success\n");
    } else {
        printf("load png error\n");
        return -1;
    }
    
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                quit = true;
                break;
            default:
                break;
            }
        }
        SDL_BlitSurface( gui->player1, NULL, gui->screenSurface, NULL );
        SDL_UpdateWindowSurface( gui->window );
        SDL_Delay( 1 );
    }

    return 0;
}

int main(int argc, char* argv[])
{
    int ret = 0;
    GAME_UI gui;

    memset(&gui, 0, sizeof(gui));
    gui.width = 640;
    gui.height = 480;

    ret = init_screen(&gui);
    if (0 == ret) {
        main_loop(&gui);
    }

    destroy_screen(&gui);

    return 0;
}