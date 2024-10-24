cmake_minimum_required(VERSION 3.16)
project(Xeraoo-etap2)  # Zmieniono nazwę projektu, aby pasowała do nowej konwencji

set(CMAKE_CXX_STANDARD 14)  # Standard C++

# Dodaj katalogi z nagłówkami
include_directories(${PROJECT_SOURCE_DIR})  # Użycie ${PROJECT_SOURCE_DIR} jako dynamicznej ścieżki

# Wymieniamy pliki źródłowe i nagłówkowe
set(SOURCE_FILES
        Automat.cpp
        Napoj.cpp
        Platnosc.cpp
        Blik.cpp
        Karta.cpp
        main.cpp)  # Zgrupowane pliki źródłowe

set(HEADER_FILES
        Automat.h
        Napoj.h
        Platnosc.h
        Blik.h
        Karta.h
        Odczyt.h)  # Zgrupowane pliki nagłówkowe

# Tworzenie głównej aplikacji
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
