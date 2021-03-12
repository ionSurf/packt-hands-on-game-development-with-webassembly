#!/bin/bash

cd src/
emcc main.c -o build/gameloop.html  --preload-file sprites -s NO_EXIT_RUNTIME=1 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS=["png"] -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap', 'ccall']" -s USE_SDL=2 && emrun --browser firefox --serve_after_close --kill_start build/gameloop.html 