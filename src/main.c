#include <stdio.h>

#define ROWS 6
#define COLS 10

int main(void)
{

    char dungeon[ROWS][COLS + 1] = {
        "##########",
        "#........#",
        "#..##....#",
        "#....T...#",
        "#.......E#",
        "##########"};
    int playerRow = 1;
    int playerCol = 1;
    int score = 0;
    int treasure_collected = 0;
    char move;

    while (1)
    {
        printf("=== DUNGEON EXPLORER ===\n\n");
        printf("Tressure: %d/1 | Score: %d\n\n",
               treasure_collected, score);

        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (row == playerRow && col == playerCol)
                {
                    printf("P");
                }
                else
                {
                    printf("%c", dungeon[row][col]);
                }
            }
            printf("\n");
        }

        printf("\nMove: W/A/S/D | Quit: Q\n");
        printf("Your move: ");

        if (scanf(" %c", &move) != 1)
        {
            break;
        }

        if (move == 'q' || move == 'Q')
        {
            printf("Game ended. Final score: %d\n", score);
            break;
        }

        int new_row = playerRow;
        int new_col = playerCol;

        switch (move)
        {
        case 'w':
        case 'W':
            new_row--;
            break;

        case 's':
        case 'S':
            new_row++;
            break;

        case 'a':
        case 'A':
            new_col--;
            break;

        case 'd':
        case 'D':
            new_col++;
            break;

        default:
            printf("Invalid move! Use W, A, S, or D.\n");
            continue;
        }

        if (new_row < 0 || new_row >= ROWS ||
            new_col < 0 || new_col >= COLS)
        {
            printf("You cannot move outside the dungeon!\n");
            continue;
        }

        if (dungeon[new_row][new_col] == '#')
        {
            printf("You cannot walk through walls!\n");
            continue;
        }

        playerRow = new_row;
        playerCol = new_col;

        if (dungeon[playerRow][playerCol] == 'T')
        {
            score += 10;
            treasure_collected = 1;
            dungeon[playerRow][playerCol] = '.';

            printf("You found treasure! +10 points!\n");
        }

        if (dungeon[playerRow][playerCol] == 'E')
        {
            if (treasure_collected)
            {
                printf("\nYOU ESCAPED THE DUNGEON!\n");
                printf("Final score: %d\n", score);
                break;
            }
            else
            {
                printf("The exit is locked! Find the treasure first.\n");
                playerRow = new_row;
                playerCol = new_col;
            }
        }
    }
    return 0;
}