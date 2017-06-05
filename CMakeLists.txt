cmake_minimum_required(VERSION 2.8)

project(kyEngine)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++14 -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

if (APPLE)
  set(CMAKE_MACOSX_RPATH 1)
endif(APPLE)

find_package(Boost 1.40 COMPONENTS system REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(GLEW REQUIRED)

if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR} src)

add_subdirectory(src/engine)
add_subdirectory(src/graphics)
add_subdirectory(src/math)

# kyengine is the final lib
add_library(kyengine SHARED
  $<TARGET_OBJECTS:engine>
  $<TARGET_OBJECTS:graphics>
  $<TARGET_OBJECTS:math>
  )
INSTALL(TARGETS kyengine DESTINATION lib)
# we link Boost
target_link_libraries(kyengine 
  ${Boost_LIBRARIES}
  glfw
  ${OPENGL_gl_LIBRARY})
