cmake_minimum_required(VERSION 3.15)
project(kolizja_trojkatow_zad_1)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(Google_test)

add_executable(kolizja_trojkatow_zad_1 main.cpp isColliding.h)

include_directories(C:/SFML-2.5.1/include)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

if(SFML_FOUND)
    include_directories(C:/SFML-2.5.1/include)
    target_link_libraries(kolizja_trojkatow_zad_1 sfml-system sfml-window sfml-graphics sfml-audio)
endif()





