#!/bin/bash

cd src/
emcc sprite_control.c --preload-file sprites -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS=["png"] -o build/sprite_control.html && emrun --browser firefox --serve_after_close --kill_start build/sprite_control.html 