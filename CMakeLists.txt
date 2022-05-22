cmake_minimum_required(VERSION 3.9)
project(mylib LANGUAGES CXX VERSION 1.0.1 DESCRIPTION "Devoncat libretro core")

file(GLOB SRC src/*.cpp src/*.hpp src/*.c src/*.h src/*.cxx)

add_library(devoncat SHARED ${SRC})
set_target_properties(devoncat PROPERTIES
    SOVERSION 1
    PUBLIC_HEADER src/libretro.h)
target_link_libraries(devoncat unicorn-common riscv32-softmmu)
target_include_directories(devoncat PRIVATE src)
