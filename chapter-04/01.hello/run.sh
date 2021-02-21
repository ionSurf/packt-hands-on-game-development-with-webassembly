#!/bin/bash

cd src/
emcc hello_sdl.c --emrun --preload-file font -s USE_SDL=2 -s USE_SDL_TTF=2 -o build/hello_sdl.html && emrun --browser firefox --serve_after_close --kill_start build/hello_sdl.html