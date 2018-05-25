cmake_minimum_required(VERSION 3.10)
project(turing C)

set(CMAKE_C_STANDARD 11)

add_executable(turing tur.h tur.c tape.c run.c command.c)