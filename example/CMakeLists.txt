# Specifica la versione minima di CMake
cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(TestProject)

# Aggiungi i file sorgente
set(SOURCES
    read_key.c
    ../src/terminal.c
    ../src/box.c
    ../src/point.c
    ../src/tui.c
    ../src/color.c
    ../src/key.c
)

# Crea l'eseguibile
add_executable(read_key ${SOURCES})
