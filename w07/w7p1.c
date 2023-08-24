/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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
    int i, j, x, b, y; // Variables used in various 'for' loops
    
    // Defining structure data type for storing player information!
    struct playerInfo
    {
        int lives;
        char symbol;
        int NumOfTreasures;
        int positionHistory[MAX_PATHLEN];
    };
    
    // Defining structure data type for storing game information!
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
    //Setting history of moves to a 'safe empty state'
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
    //Taking bomb placement inputs from player
    printf("BOMB Placement\n");
    printf("--------------\n");
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
    //Taking treasure placement inputs from player
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
    printf("====================================\n");
    return 0;
}