cmake_minimum_required(VERSION 3.20.0)
project(TADfecha)

# Aqui van la carpeta con las cabezeras
include_directories(include)

#set(SOURCES src/main.cpp src/strings.cpp)

file(GLOB SOURCES "src/*.cpp")


add_executable(modelo ${SOURCES})