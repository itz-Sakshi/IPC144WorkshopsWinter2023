/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Sakshi Sakshi
Student ID#: 112602222
Email      : ssakshi7@myseneca.ca
Section    : NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#define MAX_PATHLEN 70

#include <stdio.h>

int main(void)
{
    int minPathLen = 10;
    int minLives = 1;
    int maxLives = 10;
    int pathMultiple = 5;
    float maxMoves = 0;
    int i, j, x, b, y, k, a, l; // Variables used in various for loops
    int currentPosition; // Variable used in for loop to print player's current position in the game's path.
    int nextPosition; // Variable used to prompt user for player's next move.

    // Defining structure data type to store player's information.
    struct playerInfo
    {
        int lives;
        char symbol;
        int numOfTreasures;
        int positionHistory[MAX_PATHLEN];
    };

    // Defining structure data type to store game's information.
    struct gameInfo
    {
        int moves;
        int pathLen;
        int bombPosition[MAX_PATHLEN];
        int treasurePosition[MAX_PATHLEN];
    };

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    struct playerInfo player;
    player.numOfTreasures = 0;
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < minLives || player.lives > maxLives)
        {
            printf("     Must be between %d and %d!\n", minLives, maxLives);
        }
    } while (player.lives < minLives || player.lives > maxLives);
    printf("Player configuration set-up is complete\n\n");
    //Setting history of moves to a safe empty state
    for (i = 0; i < MAX_PATHLEN; i++)
    {
        player.positionHistory[i] = -1;
    }
    struct gameInfo game;
    printf("GAME Configuration\n"
        "------------------\n");
    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", pathMultiple, minPathLen, MAX_PATHLEN);
        scanf("%d", &game.pathLen);
        if (game.pathLen < minPathLen || game.pathLen > MAX_PATHLEN || game.pathLen % pathMultiple != 0)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", pathMultiple, minPathLen, MAX_PATHLEN);
        }
    } while (game.pathLen < minPathLen || game.pathLen > MAX_PATHLEN || game.pathLen % pathMultiple != 0);
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        maxMoves = 0.75 * game.pathLen;
        if (game.moves < player.lives || game.moves >(int) maxMoves)
        {
            printf("    Value must be between %d and %d\n", player.lives, (int)maxMoves);
        }
    } while (game.moves < player.lives || game.moves >(int) maxMoves);
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    //Taking bomb placement inputs from player
    printf("Enter the bomb positions in sets of %d where a value\n", pathMultiple);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLen);
    for (j = 0; j < (game.pathLen / pathMultiple); j++)
    {
        printf("   Positions [%2d-%2d]: ", (pathMultiple * j) + 1, pathMultiple * (j + 1));
        for (x = 0; x < pathMultiple; x++)
        {
            scanf("%d", &game.bombPosition[(j * pathMultiple) + x]);
        }
    }
    printf("BOMB placement set\n\n");
    //Taking bomb placement inputs from player
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", pathMultiple);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLen);
    for (b = 0; b < (game.pathLen / pathMultiple); b++)
    {
        printf("   Positions [%2d-%2d]: ", (pathMultiple * b) + 1, pathMultiple * (b + 1));
        for (y = 0; y < pathMultiple; y++)
        {
            scanf("%d", &game.treasurePosition[(b * pathMultiple) + y]);
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c", player.symbol);
    printf("\n   Lives      : %d", player.lives);
    printf("\n   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d", game.pathLen);
    printf("\n   Bombs      : ");
    for (i = 0; i < game.pathLen; i++)
    {
        printf("%d", game.bombPosition[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLen; i++)
    {
        printf("%d", game.treasurePosition[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    while (player.lives != 0 && game.moves != 0)
    {
        printf("  ");
        for (k = 0; k < game.pathLen; k++)
        {
            if (player.positionHistory[k] == 1 && game.bombPosition[k] == 1 && game.treasurePosition[k] == 1)
            {
                printf("&");
            }
            else if (player.positionHistory[k] == 1 && game.bombPosition[k] == 1)
            {
                printf("!");
            }
            else if (player.positionHistory[k] == 1 && game.treasurePosition[k] == 1)
            {
                printf("$");
            }
            else if (player.positionHistory[k] == 1)
            {
                printf(".");
            }
            else if (player.positionHistory[k] == -1)
            {
                printf("-");
            }
        }
        printf("\n  ");
        for (a = 0; a < game.pathLen; a++)
        {
            if ((a + 1) % 10 != 0)
            {
                printf("|");
            }
            else
            {
                printf("%d", (a + 1) / 10);
            }
        }
        printf("\n  ");
        for (l = 0; l < game.pathLen; l++)
        {
            if ((l + 1) % 10 != 0 && (l + 1) < 10)
            {
                printf("%d", l + 1);
            }
            else if ((l + 1) % 10 != 0 && (l + 1) > 10)
            {
                printf("%d", (l + 1) - (10 * ((l + 1) / 10)));
            }
            else
            {
                printf("0");
            }
        }
        // Displaying Player's Statistics on the screen
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.numOfTreasures, game.moves);
        printf("+---------------------------------------------------+\n");
        do
        {
            printf("Next Move [1-%d]: ", game.pathLen);
            scanf("%d", &nextPosition);
            if (nextPosition < 1 || nextPosition > game.pathLen)
            {
                printf("  Out of Range!!!\n");
            }
        } while (nextPosition < 1 || nextPosition > game.pathLen);
        if (player.positionHistory[nextPosition - 1] == 1)
        {
            printf("\n===============> Dope! You've been here before!\n\n");
        }
        else if (game.bombPosition[nextPosition - 1] == 1 && game.treasurePosition[nextPosition - 1] == 1)
        {
            player.positionHistory[nextPosition - 1] = 1;
            game.moves--;
            player.lives--;
            player.numOfTreasures++;
            printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            if (player.lives == 0)
            {
                printf("No more LIVES remaining!\n\n");
            }
            if (game.moves == 0)
            {
                printf("No more MOVES remaining!\n\n");
            }
        }
        else if (game.treasurePosition[nextPosition - 1] == 1)
        {
            game.moves--;
            player.positionHistory[nextPosition - 1] = 1;
            player.numOfTreasures++;
            printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            if (game.moves == 0)
            {
                printf("No more MOVES remaining!\n\n");
            }
        }
        else if (game.bombPosition[nextPosition - 1] == 1)
        {
            game.moves--;
            player.positionHistory[nextPosition - 1] = 1;
            player.lives--;
            printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
            if (player.lives == 0)
            {
                printf("No more LIVES remaining!\n\n");
            }
            if (game.moves == 0)
            {
                printf("No more MOVES remaining!\n\n");
            }
        }
        else
        {
            game.moves--;
            player.positionHistory[nextPosition - 1] = 1;
            printf("\n===============> [.] ...Nothing found here... [.]\n\n");
            if (game.moves == 0)
            {
                printf("No more MOVES remaining!\n\n");
            }
        }
        printf("  ");
        for (currentPosition = 0; currentPosition < nextPosition; currentPosition++)
        {
            if (currentPosition == nextPosition - 1)
            {
                printf("%c\n", player.symbol);
            }
            else
            {
                printf(" ");
            }
        }
    }
    printf("  ");
    for (k = 0; k < game.pathLen; k++)
    {
        if (player.positionHistory[k] == 1 && game.bombPosition[k] == 1 && game.treasurePosition[k] == 1)
        {
            printf("&");
        }
        else if (player.positionHistory[k] == 1 && game.bombPosition[k] == 1)
        {
            printf("!");
        }
        else if (player.positionHistory[k] == 1 && game.treasurePosition[k] == 1)
        {
            printf("$");
        }
        else if (player.positionHistory[k] == 1)
        {
            printf(".");
        }
        else if (player.positionHistory[k] == -1)
        {
            printf("-");
        }
    }
    printf("\n  ");
    for (a = 0; a < game.pathLen; a++)
    {
        if ((a + 1) % 10 != 0)
        {
            printf("|");
        }
        else
        {
            printf("%d", (a + 1) / 10);
        }
    }
    printf("\n  ");
    for (l = 0; l < game.pathLen; l++)
    {
        if ((l + 1) % 10 != 0 && (l + 1) < 10)
        {
            printf("%d", l + 1);
        }
        else if ((l + 1) % 10 != 0 && (l + 1) > 10)
        {
            printf("%d", (l + 1) - 10 * ((l + 1) / 10));
        }
        else
        {
            printf("0");
        }
    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.numOfTreasures, game.moves);
    printf("+---------------------------------------------------+\n\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");
    return 0;
}