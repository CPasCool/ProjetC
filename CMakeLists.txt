cmake_minimum_required(VERSION 3.24)
project(ProjetC C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetC main.c src/Board/CreateBoard.c src/Character/Character.c include/src/Character.h Tests/Character/TestCharacter.c Tests/Character/TestCharacter.h src/Keyboard/Keyboard.c include/src/Keyboard.h Tests/Monsters/MonstersTests.c Tests/Monsters/MonstersTests.h src/menu/menu.c include/src/menu.h src/Monster/Monster.c src/Fight/FightSystem.c include/src/FightSystem.h src/Game/Game.c include/src/Game.h src/Windows/windows.c include/src/windows.h src/EventListener/event.c src/EventListener/event.h)


