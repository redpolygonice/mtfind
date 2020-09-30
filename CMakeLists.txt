cmake_minimum_required(VERSION 2.8)

project(mtfind)

# Sources
include_directories("src")
file(GLOB SOURCES "src/*.h" "src/*.hpp" "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} pthread -lstdc++fs)
