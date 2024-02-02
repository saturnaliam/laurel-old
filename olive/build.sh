#! /usr/bin/sh

gcc -I src/include/ src/*.c src/include/*.c src/include/networking/*.c -o olive
./olive
