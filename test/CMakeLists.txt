set(CMAKE_CXX_STANDARD 11)
add_executable(a.out main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(a.out pong ${SDL2_LIBRARIES})