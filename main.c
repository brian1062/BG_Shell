#include <stdio.h>
#include <unistd.h>
#include "./include/cmdHandler.h"
#include "./include/execScript.h"

void printPresentacion();

int main(int argc,char *argv[])
{
    if(readScript(argv[1])){
        //si se puedo ejecutar el scrip termino
    }else { //si no abro el BG_Shell
        printPresentacion();
        char *comand;
        while (1) {
            comand = getLine();
            cmdHandler(comand);
        }
    }
	return 0;
}
void printPresentacion(){
    clear();
    printf("\n\t\x1b[43m*******************************************");
    printf("\n\t**\x1b[0m                \x1b[42mBG_Shell\x1b[0m               \x1b[43m**");
    printf("\n\t**\x1b[0m Este shell fue creado para la materia \x1b[43m**");
    printf("\n\t**\x1b[0m          Sistemas operativos          \x1b[43m**");
    printf("\n\t**\x1b[0m       Trabajo practico numero 4       \x1b[43m**");
    printf("\n\t*******************************************\x1b[0m");
    printf("\n\n");
    sleep(1);
}