#!/bin/bash

# get password from user to get uninterrupted setup
sudo true || exit 1

sudo apt-get install libx11-dev -y
sudo apt-get install xorg-dev libglu1-mesa-dev -y

mkdir -p build
cd build
cmake ../
cmake --build .

cd ..
cd engine

mkdir -p build
cd build
cmake ../
cmake --build .
