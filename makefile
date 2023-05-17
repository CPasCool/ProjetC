CC=gcc
CFLAGS=

main : board.exe
	$(CC) -o main.exe board.exe menu.exe main.c $(CFLAGS)

board: Board\CreateBoard.c Board\CreateBoard.h
	$(CC)  -o board.exe -c Board\CreateBoard.c $(CFLAGS)

menu.exe: menu\menu.c
	$(CC)  -o menu.exe -c menu\menu.c $(CFLAGS)

clean :
	del menu.exe main.exe board.exe