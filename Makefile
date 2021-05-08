ejecutable: limpiar main.o Lista.o
	gcc Build/object/main.o Build/object/circular_lista.o -o Build/bin/main.out
	./Build/bin/main.out

main.o: src/main.c Include/main.h Include/circular_lista.h

	gcc -Wall -Wextra -std=c11 -I./Include/ -c src/main.c -o Build/object/main.o

Lista.o: src/circular_lista.c Include/circular_lista.h 

	gcc -Wall -Wextra -std=c11 -I./Include/ -c src/circular_lista.c -o Build/object/circular_lista.o
	
limpiar:
	rm -f Build/object/main.o
	rm -f Build/object/circular_lista.o
	rm -f Build/bin/main.out