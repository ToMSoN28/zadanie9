cmake_minimum_required(VERSION 3.1)
project(asd)

add_executable(asd src/main.c src/gauss.c src/mat_io.c src/backsubst.c)
