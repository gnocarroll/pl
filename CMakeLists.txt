cmake_minimum_required(VERSION 4.0)

project(ProgrammingLanguage
    VERSION 0.1.0
    DESCRIPTION "programming language"
    LANGUAGES CXX)

add_executable(pl src/main.cpp)
target_include_directories(pl PUBLIC include)