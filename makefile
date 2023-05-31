CC=gcc
CFLAGS=

main : board.exe menu.exe character.exe keyboard.exe Fight.exe TestsCharacter.exe TestsMonster.exe Cheat.exe
	$(CC) -o main.exe board.exe menu.exe character.exe keyboard.exe Fight.exe TestsCharacter.exe TestsMonster.exe main.c $(CFLAGS)

board.exe: Board\CreateBoard.c Board\CreateBoard.h
	$(CC)  -o board.exe -c Board\CreateBoard.c $(CFLAGS)

menu.exe: menu\menu.c menu\menu.h
	$(CC)  -o menu.exe -c menu\menu.c $(CFLAGS)

character.exe: Character\Character.c Character\Character.h
	$(CC)  -o character.exe -c Character\Character.c $(CFLAGS)

keyboard.exe: Keyboard\Keyboard.c Keyboard\Keyboard.h
	$(CC)  -o keyboard.exe -c Keyboard\Keyboard.c  $(CFLAGS)
 
Fight.exe: Fight\FightSystem.c Fight\FightSystem.h
	$(CC)  -o Fight.exe -c Fight\FightSystem.c  $(CFLAGS)

TestsCharacter.exe: Tests\Character\TestCharacter.c Tests\Character\TestCharacter.h
	$(CC)  -o TestsCharacter.exe -c Tests\Character\TestCharacter.c  $(CFLAGS)

TestsMonster.exe: Tests\Monsters\MonstersTests.c Tests\Monsters\MonstersTests.c
	$(CC)  -o TestsMonster.exe -c Tests\Monsters\MonstersTests.c  $(CFLAGS)

Cheat.exe: Cheat\Cheat.c Cheat\Cheat.h
	$(CC)  -o Cheat.exe -c Cheat\Cheat.c  $(CFLAGS)

clean :
	del main.exe board.exe menu.exe character.exe keyboard.exe Fight.exe TestsCharacter.exe TestsMonster.exe Cheat.exe