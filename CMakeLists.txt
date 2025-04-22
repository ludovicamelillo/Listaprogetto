cmake_minimum_required(VERSION 3.23)
project(Listaprogetto)

set(CMAKE_CXX_STANDARD 14)

add_executable(Listaprogetto src/main.cpp src/utente.cpp include/utente.h src/oggetto.cpp include/oggetto.h src/listaspesa.cpp include/listaspesa.h)

set(SOURCE_FILES
        src/main.cpp
        src/utente.cpp
        src/oggetto.cpp
        src/listaspesa.cpp
        )

include_directories(include)