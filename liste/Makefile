all: liste

liste: objets/liste.o objets/imagesettings.o objets/main_liste.o
	gcc -o liste objets/liste.o objets/imagesettings.o objets/main_liste.o -Wall -Wextra -Werror

objets/liste.o: sources/liste.c
	gcc -o objets/liste.o -c sources/liste.c -Wall -Wextra -Werror

objets/imagesettings.o: sources/imagesettings.c
	gcc -o objets/imagesettings.o -c sources/imagesettings.c -Wall -Wextra -Werror
	
objets/main_liste.o: sources/main_liste.c headers/liste.h headers/imagesettings.h
	gcc -o objets/main_liste.o -c sources/main_liste.c -Wall -Wextra -Werror


clean:
	rm -f objets/*.o core

