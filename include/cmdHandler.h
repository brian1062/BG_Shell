//
// Created by brian on 26/09/22.
//
#ifndef SOI_2022_LABORATORIO_4_BRIAN1062_CMDHANDLER_H
#define SOI_2022_LABORATORIO_4_BRIAN1062_CMDHANDLER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clear();
void cmdCd(char*);
void cmdEcho(char*);
void cmdHandler(char* comand);
char* getLine();
void printHelp();

#endif //SOI_2022_LABORATORIO_4_BRIAN1062_CMDHANDLER_H
