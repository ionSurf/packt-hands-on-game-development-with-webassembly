#include <emscripten.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  printf( "main has run\n" );
}

void press_up() {
  printf( "UP PRESSED\n" );
}
void press_down() {
  printf( "DOWN PRESSED\n" );
}
void press_left() {
  printf( "LEFT PRESSED\n" );
}
void press_right() {
  printf( "RIGHT PRESSED\n" );
}

void release_up() {
  printf( "UP RELEASED\n" );
}
void release_down() {
  printf( "DOWN RELEASED\n" );
}
void release_left() {
  printf( "LEFT RELEASED\n" );
}
void release_right() {
  printf( "RIGHT RELEASED\n" );
}