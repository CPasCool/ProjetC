CC = gcc                  # Variable représentant le nom du compilateur.
CFLAGS = -Wall -I include # Variable représentant les options de compilation.
LDFLAGS = -L lib -lZDS    # Variable représentant les options d’édition de liens.


SRC_C = $(wildcard *.c */*/*.c)

main: $(SRC_C)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean :
	rm -rf *.o