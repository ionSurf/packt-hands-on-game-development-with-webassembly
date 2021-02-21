#!/bin/bash

cd src/
emcc wakeyboard.c --emrun -o build/wakeyboard.html -s USE_SDL=2 && emrun --browser firefox --serve_after_close --kill_start build/wakeyboard.html