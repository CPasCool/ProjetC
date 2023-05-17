cmake_minimum_required(VERSION 3.24)
project(ProjetC C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetC main.c Board/CreateBoard.c Character/Character.c Character/Character.h Tests/Character/TestCharacter.c Tests/Character/TestCharacter.h Monster/Monster.c Monster/Monster.h Tests/Monsters/MonstersTests.c Tests/Monsters/MonstersTests.h menu/menu.c)
