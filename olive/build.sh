#! /usr/bin/sh

gcc -I src/include/ src/*.c src/include/*.c -o olive
./olive
