cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(tloc_engine VERSION 0.1 LANGUAGES CXX)

add_subdirectory(src)

install(DIRECTORY "src/include/" DESTINATION "include/tloc")
