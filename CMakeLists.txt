cmake_minimum_required(VERSION 4.1)
project(contact C)

set(CMAKE_C_STANDARD 11)

add_executable(contact main.c
        src/Contact.c
        src/Tri.c
        src/Search.c
)
