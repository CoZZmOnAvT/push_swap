cmake_minimum_required(VERSION "3.2")
project(errors LANGUAGES C VERSION 0.0.1)
# enable_testing()

set(PROJECT_SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(PROJECT_HEADERS_DIR "${PROJECT_SOURCE_DIR}/include")

file(GLOB SOURCES ${PROJECT_SRC_DIR}/*.c)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_HEADERS_DIR})
target_link_libraries(${PROJECT_NAME} ft)

# add_subdirectory(test)
