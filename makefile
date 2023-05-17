CC=gcc
CFLAGS=

main : board.exe menu.exe
	$(CC) -o main.exe board.exe menu.exe main.c $(CFLAGS)

board.exe: Board\CreateBoard.c Board\CreateBoard.h
	$(CC)  -o board.exe -c Board\CreateBoard.c $(CFLAGS)

menu.exe: menu\menu.c menu\menu.h
	$(CC)  -o menu.exe -c menu\menu.c $(CFLAGS)

clean :
	del main.exe board.exe menu.exe