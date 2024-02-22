cmake_minimum_required(VERSION 3.25)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VERSION})
file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)
CPMAddPackage("gh:google/googletest#v1.14.0")

set(CMAKE_CXX_STANDARD 23)
configure_file (version.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/version.hpp @ONLY)

add_library(lib STATIC lib.cpp lib.hpp version.hpp)

add_executable(helloworld_cli main.cpp)

target_link_libraries(helloworld_cli lib)

target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
)
install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

