#include <SDL2/SDL.h>
#include <stdbool.h>
#include "jeu.h"

/* Window resolution */
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

/* Window title */
#define WINDOW_TITLE "Plante vs Zombie Like"

/* The window */
SDL_Window* window = NULL;

/* The window surface */
SDL_Surface* screen = NULL;

/* The event structure */
SDL_Event event;

/* The game loop flag */
int running = 1;

/* to put the loaded fond */
SDL_Surface* fond = NULL;

SDL_Surface* plante1;

int main( int argc, char* args[] )
{
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL2 could not initialize! SDL2_Error: %s\n", SDL_GetError() );
  } else {
    window = SDL_CreateWindow(
      WINDOW_TITLE,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      WINDOW_WIDTH,
      WINDOW_HEIGHT,
      SDL_WINDOW_SHOWN);

    screen = SDL_GetWindowSurface( window );
    fond = SDL_LoadBMP( "images/fond.bmp" );
    plante1 = SDL_LoadBMP("images/Plante 1.bmp");
    SDL_Rect dest = { 144/2 - plante1->w/2-8,128/2 - plante1->h/2, 0, 0};

    while( running ) {
      while( SDL_PollEvent( &event ) != 0 ) {
        if( event.type == SDL_QUIT ) {
          running = 0;
        }
      }

      //jouer(); //appel la fonction jouer dans jeu.c
      SDL_BlitSurface( fond, NULL, screen, NULL );
      SDL_BlitSurface( plante1, NULL, screen, &dest );
      SDL_UpdateWindowSurface( window );
    }
  }
  SDL_FreeSurface( plante1 );
  SDL_FreeSurface( fond );
  SDL_DestroyWindow( window );
  SDL_Quit();
  return 0;
}
