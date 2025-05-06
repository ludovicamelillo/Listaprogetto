cmake_minimum_required(VERSION 3.23)
project(Listaprogetto)

set(CMAKE_CXX_STANDARD 14)

include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

add_subdirectory(googletest)

add_executable(Listaprogetto
        src/main.cpp
        src/utente.cpp
        include/utente.h
        src/oggetto.cpp
        include/oggetto.h
        src/listaspesa.cpp
        include/listaspesa.h
        include/observer.h)

set(SOURCE_FILES
        src/main.cpp
        src/utente.cpp
        src/oggetto.cpp
        src/listaspesa.cpp
        )

set(TEST_FILES
        tests/test_lista_spesa.cpp
        tests/test_oggetto.cpp)

add_executable(runTests
        tests/test_lista_spesa.cpp
        tests/test_oggetto.cpp
        tests/test_utente.cpp
        src/utente.cpp
        src/oggetto.cpp
        src/listaspesa.cpp
        tests/test_oggetto.cpp tests/test_utente.cpp)
target_link_libraries(runTests gtest gmock pthread)

include_directories(include)