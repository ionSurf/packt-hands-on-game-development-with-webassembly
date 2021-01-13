#!/bin/bash

emcc src/shell.c -o shell-test.html --shell-file src/new_shell.html -s NO_EXIT_RUNTIME=1 -s EXPORTED_FUNCTIONS="['_test', '_string_test', '_int_test', '_float_test', '_main']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap', 'ccall']"
emrun --browser firefox shell-test.html
