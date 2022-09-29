CFLAGS=gcc -Wall -Werror -pedantic

BG_Shell : cmdHandler.o execProcess.o execScript.o main.o
	$(CFLAGS) main.o cmdHandler.o execProcess.o execScript.o -o BG_Shell
	./BG_Shell

main.o: main.c
	$(CFLAGS) main.c -c

cmdHandler.o: ./cmdutils/cmdHandler.c
	$(CFLAGS) -c ./cmdutils/cmdHandler.c

execProcess.o: ./cmdutils/execProcess.c
	$(CFLAGS) -c ./cmdutils/execProcess.c

execScript.o: ./cmdutils/execScript.c
	$(CFLAGS) -c ./cmdutils/execScript.c

clean:
	rm -f BG_Shell
	rm *.o