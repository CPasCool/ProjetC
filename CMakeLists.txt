cmake_minimum_required(VERSION 3.24)
project(ProjetC C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetC main.c Board/CreateBoard.c Character/Character.c Character/Character.h Tests/Character/TestCharacter.c Tests/Character/TestCharacter.h Keyboard/Keyboard.c Keyboard/Keyboard.h Tests/Monsters/MonstersTests.c Tests/Monsters/MonstersTests.h menu/menu.c menu/menu.h Monster/Monster.c Board/Levels.c Coodonnees/Coordonees.c Coodonnees/Coordonees.h Fight/FightSystem.c Fight/FightSystem.h Game/Game.c Game/Game.h)
