#!/bin/bash

cd src/
emcc jskey.c --emrun -o build/jskey.html -s NO_EXIT_RUNTIME=1 --shell-file shell/jskey_shell.html -s EXPORTED_FUNCTIONS="['_main', '_press_up', '_press_down', '_press_left', '_press_right', '_release_up', '_release_down', '_release_left', '_release_right']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap', 'ccall']" && emrun --browser firefox --serve_after_close --kill_start build/jskey.html