CC=gcc
CFLAGS=

main.exe : board.exe
	$(CC) -o main.exe board.exe main.c $(CFLAGS)

board.exe : Board\CreateBoard.c Board\CreateBoard.h
	$(CC)  -o board.exe -c Board\CreateBoard.c $(CFLAGS)

clean :
	del main.exe board.exe