cmake_minimum_required(VERSION 3.20.4)

project(Program)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/DeckOfCards.cpp
        ${PROJECT_SOURCE_DIR}/Card.cpp
        ${PROJECT_SOURCE_DIR}/PokerHand.cpp
    )

set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/DeckOfCards.hpp
        ${PROJECT_INCLUDE_DIR}/Card.hpp
        ${PROJECT_INCLUDE_DIR}/PokerHand.hpp
    )

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})