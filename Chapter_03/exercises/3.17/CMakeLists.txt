cmake_minimum_required(VERSION 3.20.4)

project(HealthProfile)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/HealthProfile.cpp 
        ${PROJECT_SOURCE_DIR}/main.cpp
    )

set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/HealthProfile.hpp
    )

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})