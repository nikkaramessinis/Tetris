cmake_minimum_required(VERSION 3.5)



add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(intro main.cpp draw.hpp)
target_link_libraries(intro sfml-graphics sfml-window sfml-system)
