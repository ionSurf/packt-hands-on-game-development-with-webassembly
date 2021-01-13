#!/bin/bash

emcc src/hello_sdl.c --emrun --preload-file src/font -s USE_SDL=2 -s USE_SDL_TTF=2 -o hello_sdl.html && emrun --browser firefox --port 8080 hello_sdl.html