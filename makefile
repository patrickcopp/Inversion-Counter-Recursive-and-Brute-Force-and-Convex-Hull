all: main

main: P11.o P12.o P21.o P22.o main.c
	gcc -Wall -std=c11 -g -pedantic main.c P11.c P12.c P21.c P22.c -o main

P11.o: P11.c
	gcc -Wall -std=c11 -g -pedantic -c P11.c -o P11.o

P12.o: P12.c
	gcc -Wall -std=c11 -g -pedantic -c P12.c -o P12.o

P21.o: P21.c
	gcc -Wall -std=c11 -g -pedantic -c P21.c -o P21.o

P22.o: P22.c
	gcc -Wall -std=c11 -g -pedantic -c P22.c -o P22.o

clean:
	rm *.o
