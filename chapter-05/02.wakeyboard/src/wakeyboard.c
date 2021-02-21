#include <SDL2/SDL.h>
#include <emscripten.h>
#include <stdio.h>
#include <stdbool.h>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

bool left_key_press   = false;
bool right_key_press  = false;
bool up_key_press     = false;
bool down_key_press   = false;

void key_press();
void key_release();

void input_loop() {
  if( SDL_PollEvent( &event ) ) {
    if( event.type == SDL_KEYDOWN ) {
      key_press();
    } else if( event.type == SDL_KEYUP ) {
      key_release();
    }
  }
}

void key_press() {
  switch ( event.key.keysym.sym ){
  case SDLK_LEFT:
    if ( !left_key_press )
      printf( "left arrow key press\n" );
    
    left_key_press = true;
    break;
  case SDLK_RIGHT:
    if ( !right_key_press )
      printf( "right arrow key press\n" );
    
    right_key_press = true;
    break;
  case SDLK_UP:
    if ( !up_key_press )
      printf( "up arrow key press\n" );
    
    up_key_press = true;
    break;
  case SDLK_DOWN:
    if ( !down_key_press )
      printf( "down arrow key press\n" );
    
    down_key_press = true;
    break;
  
  default:
    printf( "Unknown key pressed\n" );
    break;
  }
}

void key_release() {
  switch ( event.key.keysym.sym ){
  case SDLK_LEFT:
    if ( left_key_press )
      printf( "left arrow key release\n" );
    
    left_key_press = false;
    break;
  case SDLK_RIGHT:
    if ( right_key_press )
      printf( "right arrow key release\n" );
    
    right_key_press = false;
    break;
  case SDLK_UP:
    if ( up_key_press )
      printf( "up arrow key release\n" );
    
    up_key_press = false;
    break;
  case SDLK_DOWN:
    if ( down_key_press )
      printf( "down arrow key release\n" );
    
    down_key_press = false;
    break;
  
  default:
    printf( "Unknown key released\n" );
    break;
  }
}

int main() {
  SDL_Init( SDL_INIT_VIDEO );

  SDL_CreateWindowAndRenderer( 320, 200, 0, &window, &renderer );
  SDL_SetRenderDrawColor( renderer, 0,0,0,255 );

  SDL_RenderClear( renderer );
  SDL_RenderPresent( renderer );

  emscripten_set_main_loop( input_loop, 0,0 );
  return 1;
}