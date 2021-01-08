#!/bin/bash
emcc src/hello.c -o hello.html
emrun --browser firefox hello.html