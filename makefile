CC=gcc
CFLAGS=

SRC_C = $(wildcard *.c */*/*.c)

main: $(SRC_C)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean :
	rm -rf *.o