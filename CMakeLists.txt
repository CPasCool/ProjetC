cmake_minimum_required(VERSION 3.24)
project(ProjetC C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetC main.c src/Board/CreateBoard.c src/Character/Character.c src/Character/Character.h Tests/Character/TestCharacter.c Tests/Character/TestCharacter.h src/Keyboard/Keyboard.c src/Keyboard/Keyboard.h Tests/Monsters/MonstersTests.c Tests/Monsters/MonstersTests.h src/menu/menu.c src/menu/menu.h src/Monster/Monster.c src/Fight/FightSystem.c src/Fight/FightSystem.h src/Game/Game.c src/Game/Game.h)


