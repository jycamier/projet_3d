#!/bin/bash

if [ -d bin/ ]
then
	rm -rf bin/
fi

mkdir bin
cd src/
g++ -lSDL -lGL -lGLU -lglut -lSDL_image **/*.cpp *.cpp **/**/*.cpp  -o ../bin/main
../bin/main


