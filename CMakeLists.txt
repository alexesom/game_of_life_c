cmake_minimum_required(VERSION 3.13)
project(cmake_testapp)
set(CMAKE_CXX_STANDARD 17)
add_executable(cmake_testapp src/main.c src/gifenc.h src/gifenc.c src/game.c src/game.h src/generator.c src/generator.h src/alloc.c src/alloc.h src/evolution.c src/evolution.h)