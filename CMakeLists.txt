cmake_minimum_required(VERSION 3.24)
project(ProjetC C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetC main.c src/Board/CreateBoard.c src/Character/Character.c include/src/Character.h Tests/Character/TestCharacter.c Tests/Character/TestCharacter.h src/Keyboard/Keyboard.c include/src/Keyboard.h Tests/Monsters/MonstersTests.c Tests/Monsters/MonstersTests.h src/menu/menu.c include/src/menu.h src/Monster/Monster.c src/Board/Levels.c src/Coodonnees/Coordonees.c include/src/Coordonees.h src/Fight/FightSystem.c include/src/FightSystem.h src/Game/Game.c include/src/Game.h Tests/Levels/LevelsTests.c Tests/Levels/LevelsTests.h src/MoveCharacter/Move.c include/src/Move.h src/Board/Board.c include/src/Board.h src/Cheat/Cheat.c include/src/Cheat.h src/menuPause/menuPause.c src/Save/save.c src/Dijkstra/Dijkstra.c)
