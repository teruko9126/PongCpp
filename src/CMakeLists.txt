set(CMAKE_CXX_STANDARD 11)

add_library(pong
  SHARED
    bar.cpp
    pong.cpp
  )

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_include_directories(pong
  PUBLIC ${PROJECT_SOURCE_DIR}/inc
  )

target_link_libraries(pong ${SDL2_LIBRARIES})
