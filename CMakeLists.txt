cmake_minimum_required(VERSION 3.27)
set(PATCH_VERSION "2" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VERSION})


set(CMAKE_CXX_STANDARD 23)
configure_file (version.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/version.hpp @ONLY)

add_library(lib STATIC lib.cpp lib.hpp version.hpp)

add_executable(helloworld_cli main.cpp)

target_link_libraries(helloworld_cli lib)

target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
)

