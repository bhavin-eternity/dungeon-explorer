#include <stdio.h>

#define ROWS 6
#define COLS 10

void draw_dungeon(char dungeon[ROWS][COLS + 1],
                  int player_row, int player_col)
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (row == player_row && col == player_col)
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
}

int move_player(char dungeon[ROWS][COLS + 1],
                int *player_row, int *player_col, char move, int treasure_collected)
{
    int new_row = *player_row;
    int new_col = *player_col;

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
        return 0;
    }

    if (new_row < 0 || new_row >= ROWS ||
        new_col < 0 || new_col >= COLS)
    {
        printf("You cannot leave the dungeon!\n");
        return 0;
    }

    if (dungeon[new_row][new_col] == '#')
    {
        printf("You cannot walk through walls!\n");
        return 0;
    }

    if (dungeon[new_row][new_col] == 'E' && !treasure_collected)
    {
        printf("The exit is locked! Find the treasure first.\n");
        return 0;
    }

    *player_row = new_row;
    *player_col = new_col;

    return 1;
}

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

        draw_dungeon(dungeon, playerRow, playerCol);

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

        if (!move_player(dungeon, &playerRow, &playerCol, move, treasure_collected))
        {
            continue;
        }

        if (dungeon[playerRow][playerCol] == 'T')
        {
            score += 10;
            treasure_collected = 1;
            dungeon[playerRow][playerCol] = '.';

            printf("You found treasure! +10 points!\n");
        }

        if (dungeon[playerRow][playerCol] == 'E')
        {
            printf("\nYOU ESCAPED THE DUNGEON!\n");
            printf("Final score: %d\n", score);
            break;
        }
    }
    return 0;
}