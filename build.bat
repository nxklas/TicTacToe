@echo off

if not exist build\obj mkdir build\obj

cl /nologo ^
    src\program.c ^
    src\board.c ^
    src\io\read.c ^
    /Fo:build\obj\ ^
    /Fe:build\tictactoe.exe
