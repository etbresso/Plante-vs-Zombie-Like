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

/* to put the loaded menu */
SDL_Surface* menu = NULL;

//boutons
SDL_Surface* bjouer = NULL;
SDL_Surface* bcredit = NULL;
SDL_Surface* bquitter = NULL;

//dim bjouer
int wBjouer = NULL;//dimention de l'image en x
int hBjouer = NULL;//dimention de l'image en y
//dim bcredit
int wBcredit = NULL;//dimention de l'image en x
int hBcredit = NULL;//dimention de l'image en y
//dim bquitter
int wBquitter = NULL;//dimention de l'image en x
int hBquitter = NULL;//dimention de l'image en y



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
    //Chargement image
    menu = SDL_LoadBMP( "images/menu.bmp" );

    bjouer = SDL_LoadBMP( "images/Jouer.bmp" );
    wBjouer = 1280/2 - bjouer->w/2;
    hBjouer = 720/2 - bjouer->h/2;

    bcredit = SDL_LoadBMP( "images/Crédit.bmp" );
    wBcredit = 1280/2 - bcredit->w/2;
    hBcredit = 720/2 - bcredit->h/2 + 120;

    bquitter = SDL_LoadBMP( "images/Quitter.bmp" );
    wBquitter = 1280/2 - bquitter->w/2;
    hBquitter = 720/2 - bquitter->h/2 + 240;


    while( running ) {
      while( SDL_PollEvent( &event ) != 0 ) {
        if ( event.type == SDL_QUIT) { 
          running = 0;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN){ // Souris
          if (event.button.button == SDL_BUTTON_LEFT){ //Quand on appuis sur clic gauche
            int x = event.motion.x; //recuperation coordonée souris
            int y = event.motion.y;

            if (appelJeu()==0){ //si on est dans le menu
              if (x>wBjouer && x<wBjouer+250 && y>hBjouer && y<hBjouer+100){
                    SDL_FreeSurface( menu ); // on supprime l'image du menu
                    SDL_FreeSurface( bjouer ); 
                    SDL_FreeSurface( bcredit ); 
                    SDL_FreeSurface( bquitter ); 
                    SDL_FreeSurface( screen ); 

                interfaceJeu();//appel de l'interface du jeu
                principalJeu(); //appel la fonction principalJeu dans jeu.c
              }
              if (x>wBcredit && x<wBcredit+250 && y>hBcredit && y<hBcredit+100){
                SDL_Log("Lancement des crédits");
              }
              if (x>wBquitter && x<wBquitter+250 && y>hBquitter && y<hBquitter+100){
                running = 0;
              }
            }

            else if (appelJeu() == 1){ //si on a lancé la partie jeu
              sourisJeu(x,y);
            }
          }
        }
        else if (event.type == SDL_KEYDOWN){ //clavier
          if (event.key.keysym.sym == SDLK_ESCAPE ){  //on peut toujours quitter avec echap
            running = 0;
          }
        }
      }
      if (appelJeu() == 0){ // si on est dans le menu 
        SDL_BlitSurface( menu, NULL, screen, NULL ); //fond
        
        //Postion Bouton
        SDL_Rect dimBjouer = { wBjouer,hBjouer, 0, 0}; //Position du bouton jouer
        SDL_BlitSurface( bjouer, NULL, screen, &dimBjouer );//actualisation de la postion du Bouton jouer

        SDL_Rect dimBcredit = { wBcredit,hBcredit, 0, 0}; //Position du bouton jouer
        SDL_BlitSurface( bcredit, NULL, screen, &dimBcredit );//actualisation de la postion du Bouton jouer

        SDL_Rect dimBquitter = { wBquitter,hBquitter, 0, 0}; //Position du bouton jouer
        SDL_BlitSurface( bquitter, NULL, screen, &dimBquitter );//actualisation de la postion du Bouton jouer

        SDL_UpdateWindowSurface( window );
      }
      else{
        actualisationJeu(screen);//appel de l'actualisation des position de l'interface du jeu
        SDL_UpdateWindowSurface( window );
      }
    }
  }

  SDL_Log("Merci d'avoir joué !!!");

  //a simplifier + voir surface jeu a supprimer tout le temps ou pas!
  if (appelJeu() == 0){
    SDL_FreeSurface( menu ); // on supprime l'image du menu
    SDL_FreeSurface( bjouer ); 
    SDL_FreeSurface( bcredit ); 
    SDL_FreeSurface( bquitter ); 
    SDL_FreeSurface( screen ); 
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
  }
  else{
    quitterJeu();
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
  }
}


