all: arbre

arbre: objets/arbre.o objets/imagesettings.o objets/main_arbre.o
	gcc -o arbre objets/arbre.o objets/imagesettings.o objets/main_arbre.o -Wall -Wextra -Werror

objets/arbre.o: sources/structarbre.c
	gcc -o objets/arbre.o -c sources/structarbre.c -Wall -Wextra -Werror

objets/imagesettings.o: sources/imagesettings.c
	gcc -o objets/imagesettings.o -c sources/imagesettings.c -Wall -Wextra -Werror
	
objets/main_arbre.o: sources/main_arbre.c headers/structarbre.h headers/imagesettings.h
	gcc -o objets/main_arbre.o -c sources/main_arbre.c -Wall -Wextra -Werror


clean:
	rm -f objets/*.o core