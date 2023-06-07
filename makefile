CC = gcc                  # Variable représentant le nom du compilateur.
CFLAGS = -Wall -I include # Variable représentant les options de compilation.
LDFLAGS = -L lib -lmingw32 -lSDL2main -lSDL2# Variable représentant les options d’édition de liens.


SRC_C = $(wildcard *.c */*/*.c)

main: $(SRC_C)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean :
	rm -rf *.o