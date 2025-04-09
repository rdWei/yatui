# Specifica la versione minima di CMake
cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(TestProject)

# Aggiungi i file sorgente
set(SOURCES
    boxShroom.c
    ../src/terminal.c
    ../src/box.c
    ../src/point.c
    ../src/line.c
    ../src/tui.c
    ../src/color.c
)

# Crea l'eseguibile
add_executable(example ${SOURCES})
