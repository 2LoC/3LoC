#!/bin/bash
if [ "$EUID" -ne 0 ]
then echo "Please run as root"
  exit
fi

apt-get install libx11-dev -y
apt-get install xorg-dev libglu1-mesa-dev -y

mkdir -p build
cd build
cmake ../
cmake --build .
