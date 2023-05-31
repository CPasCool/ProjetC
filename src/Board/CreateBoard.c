#include "../../include/src/CreateBoard.h"
#include <stdio.h>


void generateBoard(){
    for(int i = 0; i<30; i++){
        for(int j = 0; j<30; j++){
            if(i == 0 || i == 29 || j==0 || j == 29){
                printf("#");
            }else{
                printf("%c", ' ');
            }
        }
        printf("%c", '\n');
    }
}
