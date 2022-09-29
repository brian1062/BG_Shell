//
// Created by brian on 26/09/22.
//

#include "../include/execProcess.h"

void callConsole(char* comand){
    int ret, wstatus,w;
    ret = fork();
    switch (ret) {
        case -1:
            perror("fork error");
            exit(1);
        case 0:
            execComand(comand);
            printf("soy el hijo");
        default:
            do { //codigo extraido de man waitpid
                w = waitpid(ret, &wstatus, WUNTRACED | WCONTINUED);
                if (w == -1) {
                    perror("waitpid");
                    exit(EXIT_FAILURE);
                }
                if (WIFEXITED(wstatus)) {
                    printf("exited, status=%d\n", WEXITSTATUS(wstatus));
                } else if (WIFSIGNALED(wstatus)) {
                    printf("killed by signal %d\n", WTERMSIG(wstatus));
                } else if (WIFSTOPPED(wstatus)) {
                    printf("stopped by signal %d\n", WSTOPSIG(wstatus));
                } else if (WIFCONTINUED(wstatus)) {
                    printf("continued\n");
                }
                if(WEXITSTATUS(wstatus)==255){
                    printf("Comando invalido para conocer las utilidades de BG_Shell ingrese el comando:");
                    printf("\n-h o -help\n");
                }
            } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
            break;
            //exit(EXIT_SUCCESS);
    }
}
void execComand(char* comand){
    char *programName = comand;
    char **args;//= a *args[]= {programName, "-lh", "/home", NULL};
    args=(char**)malloc(sizeof(char));
    int i=0;
    while(comand!=NULL){
        if(i>0) {
            args = (char **) realloc(args, sizeof(char *) * (i + 1));
        }
        args[i]=comand;
        comand= strtok(NULL, " ");
        i++;
    }
    args[i]=NULL;
    if(execvp(programName, args)!=-1){
    }
    else{exit(-1);}

}