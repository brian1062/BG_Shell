#include "../include/cmdHandler.h"
#include "../include/execProcess.h"

char* getLine()
{
    char hostname[12];
    gethostname(hostname,sizeof(hostname));
    char *comand;
    comand= (char*) malloc(sizeof(char)*1024);
    //"\x1b[32m" :color rojo
    //"\x1b[31m" :color verde
    //"\x1b[0m": estado normal
    printf( "\x1b[31m%s@%s"  "\x1b[0m"":" "\x1b[32m""%s" "\x1b[0m""$ "
            ,getlogin(),hostname,getenv("PWD"));
    if(fgets(comand,1024,stdin)==NULL)
    {
        exit(EXIT_SUCCESS);
    }
    return comand;
}

void cmdHandler(char* comand){
    //quito el caracter '\n'
    //parsea el comand
    comand[strcspn(comand, "\n")] = '\000';
    comand=strtok(comand," ");

    if(strcmp(comand,"clr")==0){
        clear();
    }
    else if(strcmp(comand,"quit")==0||strcmp(comand,"q")==0){
        exit(0);
    }/*
    else if(strcmp(comand,"pwd")==0){
        printf("%s \n",getenv("PWD"));
    }*/
    else if(strcmp(comand,"cd")==0){
        cmdCd(comand);
    }
    else if(strcmp(comand,"echo")==0){
        cmdEcho(comand);
    }
    else if(strcmp(comand,"-h")==0||strcmp(comand,"-help")==0) {
        printHelp();
    }
    else{
        callConsole(comand);
    }

}

void cmdCd(char* comand){
    comand=strtok(NULL," "); //con este comando tomamos la palabra que le sigue al cd

    char actualdir[600];
    if(comand==NULL){
        //Si <directorio> no está presente, reporta el directorio actual
        printf("%s \n",getenv("PWD"));
    }
    else{//Si el directorio no existe se debe imprimir un error apropiado. Además, este comando debe cambiar la variable de entorno PWD. Este comando debe soportar
        if(strcmp(comand,"-")==0){
            //la opción cd -, que retorna al último directorio de trabajo (OLDPWD).
            chdir(getenv("OLDPWD"));//cambiamos de directorio

            getcwd(actualdir,600); //se guarda el directorio actual
            setenv("OLDPWD",getenv("PWD"),1);//seteamos el anterio como oldpwd
            setenv("PWD",actualdir,1);
        }else{
            if(chdir(comand)==0){//On  success,  zero is returned
                getcwd(actualdir,600);
                setenv("OLDPWD",getenv("PWD"),1);
                setenv("PWD",actualdir,1);

            }else{perror("directorio invalido");}
        }

    }
}

void cmdEcho(char* comand){
    comand=strtok(NULL," ");//saco la palabra siguiente de "echo"
    while(comand!=NULL){//si es null no hago nada
        printf("%s ",comand);
        comand=strtok(NULL," ");
    }printf("\n");
}

void clear(){
    printf("\033[H\033[J");
}
void printHelp(){
    printf("Bienvenido a la seccion de ayuda de BG_Shell\n");
    printf("los comandos de esta shell son:\n");
    printf("quit or q: cierra BG_Shell\n");
    printf("clr: limpia la pantalla\n");
    printf("cd <directorio> : cambia el directorio actual a <directorio>\n");
    printf("echo <comentario> : muestra <comentario> en la pantalla seguido por una línea nueva.\n");
    printf("Ademas puede ejecutar programas externos y/o comandos externos a BG_Shell.\n");
    printf("Tambien esta shell puede ejecutar una script si pasamos la PATH de la script como argumento\n");
    printf("Para hacer esto ejecute el ./BG_Shell script_PATH\n");
}