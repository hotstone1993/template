cmake_minimum_required(VERSION 3.28)

project(Template LANGUAGES CXX)

set(CMAKE_CXX_SCAN_FOR_MODULES YES)

add_executable(${PROJECT_NAME})

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 20
             CXX_STANDARD_REQUIRED ON)

target_sources(${PROJECT_NAME} 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC
    FILE_SET all_my_modules TYPE CXX_MODULES FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math.ixx
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)