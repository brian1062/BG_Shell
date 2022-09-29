//
// Created by brian on 28/09/22.
//
#include "../include/execScript.h"
#include "../include/cmdHandler.h"

int readScript(char* scriptPath){
    FILE *file;
    file  = fopen(scriptPath,"r");
    if(file==NULL){
        printf("Error a abrir el script");
        return 0;
    }else{
        char *line;//aca se van a ir guardando las lineas de comando
        line= (char*) malloc(sizeof(char)*600);
        while (fgets(line,600,file)!=NULL){
            cmdHandler(line);
        }
        free(line);
        fclose(file);
        return 1;
    }
}