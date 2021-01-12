#!/bin/bash

emcc src/canvas.c -o build/canvas.html --shell-file src/shell.html && emrun --browser firefox build/canvas.html