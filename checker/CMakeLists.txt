cmake_minimum_required(VERSION "3.2")
project(checker LANGUAGES C VERSION 0.0.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra -Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")

set(PROJECT_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(PROJECT_HEADERS_DIR "${PROJECT_SOURCE_DIR}/include/")

include_directories(${PROJECT_HEADERS_DIR})

file(GLOB SOURCES ${PROJECT_SRC_DIR}/*.c)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ft errors stack)
