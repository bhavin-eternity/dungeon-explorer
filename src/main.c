#include <stdio.h>


#define ROWS 6
#define COLS 10


int main(void){

     char dungeon[ROWS][COLS + 1] = {
        "##########",
        "#P.......#",
        "#..##....#",
        "#....T...#",
        "#.......E#",
        "##########"
    };
    printf("=== DUNGEON EXPLORER ===\n\n");

 for (int row=0;row<ROWS;row++){
    printf("%s\n",dungeon[row]);
 }
    return 0;
}