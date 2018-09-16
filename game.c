#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "game.h"

void play_game()
{

    printf("Xs and Os!\n");
    struct game* p_game_info;

    char name1[10];
    char name2[10];

    printf("Enter name 1: ");
    scanf("%s", name1);

    printf("Enter name 2: ");
    scanf("%s", name2);


    int moves = 0;

    p_game_info = (struct game*) malloc(sizeof(struct game));
    p_game_info->finished = false;

    initialise_game (p_game_info, name1, name2);


   // p_game_info->board[0][0] = X_SYMBOL; // top left X
    //p_game_info->board[2][2] = O_SYMBOL; // bottom right o

    //print_status(p_game_info);

    // ADD CODE
    //printf("HEllo");
    while(p_game_info->finished == false)
    {
        //printf("ENTERED LOOoP\n");
        //print_status(p_game_info);
        draw_Banner();
        display_board(p_game_info->board);
        print_status(p_game_info);
        display_board_positions();
        print_status(p_game_info);
        process_move(p_game_info);
       // print_status(p_game_info);

        moves++;
        if(moves == 9)
        {
            p_game_info->finished = true;
            //print_status(p_game_info);
            //printf("Game ended - draw");
            p_game_info->status = DRAW;
        }

        check_winner(p_game_info);
        print_status(p_game_info);

    }

        //print_status(p_game_info);
        //display_board_positions();


    //printf("%s", p_game_info->playerNames[0]);
}
void initialise_game(struct game* p_game_info, char* name1, char* name2)
{
    //printf("TEST");

    //p_game_info->status = P1_TURN;
    //p_game_info->status = P2_TURN;


    for(int i = 0; i < 3; i++)
    {
        for(int x = 0; x < 3; x++)
        {
            p_game_info->board[i][x] = SPACE;
        }
    }
    p_game_info->finished = false;

    strncpy(p_game_info->playerNames[0], name1,10);
    strncpy(p_game_info->playerNames[1], name2,10);


   // get_row_col();
}

void draw_Banner()
{
    int noOfSpace = 15;
    for(int i = 0; i < noOfSpace; i++)
    {
        printf(" ");
    }

    printf("----------\nGAME STATUS\n----------");



    //printf("test");
}
void display_board(char board[3][3])
{
    printf("\n");
    for(int i = 0; i < 3; i++)
    {
        for(int x = 0; x < 3; x++)
        {
            printf("%c |", board[i][x]);
        }
        printf("\n----------\n");

    }
}
void print_status(struct game* pGame)
{
    if(pGame->finished == false && pGame->status == P1_TURN)
    {
        printf("%s's Turn\n", pGame->playerNames[0]);
    }
    if(pGame->finished == false && pGame->status == P2_TURN)
    {
        printf("%s's Turn\n", pGame->playerNames[1]);
    }

    if(pGame->finished == true && pGame->status == P1_WON)
    {
        printf("\nWell done %s you have won!", pGame->playerNames[0]);

    }
    if(pGame->finished == true && pGame->status == P2_WON)
    {
        printf("\nWell done %s you have won!", pGame->playerNames[1]);

    }
    if(pGame->finished == true && pGame->status == DRAW)
    {
        printf("\nDraw.. game over!");
    }

}
void display_board_positions()
    {
    printf("\n");
    int count =1; //change later to 0 ----------------------------------------------------------------------
        for(int a = 0; a < 3; a++)
        {
            for(int b = 0; b < 3; b++)
            {
                printf("%d |",count);
                count++;
            }
            printf("\n----------\n");

        }
    }
void get_row_col(int position, int* row, int* col)
{
 if(0 < position && position < 4)
        {
        *row = 0;
        if (position == 1)
        {
            *col = 0;
        }
    else if (position == 2)
        {
            *col = 1;
        }
    else if (position == 3)
        {
            *col = 2;
        }
    }
    else if (3 < position && position < 7)
        {
        *row = 1;
        if (position == 4)
        {
            *col = 0;
        }
    else if (position == 5)
        {
            *col = 1;
        }
    else if (position == 6)
        {
            *col = 2;
        }
    }
    else if (6 < position && position < 10)
        {
        *row = 2;
        if (position == 7)
        {
            *col = 0;
        }
    else if (position == 8)
        {
            *col = 1;
        }
    else if (position == 9)
        {
            *col = 2;
        }
    }


}
void process_move(struct game* game_info)
{
    int position = 0;
    boolean inputValidation = false;
//    boolean test = false;

    do
    {
        printf("Enter a position between 1 - 9");
        scanf("%d", &position);

    }while(position < 1 || position > 9);

        while(inputValidation == false)
            {
                int row = -1;
                int col = -1;
                get_row_col(position, &row, &col);
                //printf("%d %d", row , col);
                char checkTaken = game_info->board[row][col];

                if(checkTaken == SPACE)
                {
                    if (game_info->status ==P1_TURN)
                    {
                        game_info->board[row][col] = X_SYMBOL;
                        game_info->status = P2_TURN;
                        inputValidation = True;
                    }
                    else
                    {
                        game_info->board[row][col] = O_SYMBOL;
                        game_info->status = P1_TURN;
                        inputValidation = True;
                    }
                }
            }
}
void check_winner(struct game* game_info)
{

    int winningCombos[8][6] =
    {
        {0,0,0,1,0,2} , //[0]
        {1,0,1,1,1,2} , //[1]
        {2,0,2,1,2,2} , //[2]
        {0,0,1,0,2,0} , //[3]
        {0,1,1,1,2,1} , //[4]
        {0,2,1,2,2,2} , //[5]
        {0,0,1,1,2,2} , //[6]
        {0,2,1,1,2,0}   //[7]
    };
    //Iterates through each array checking

    for(int i = 0; i < 8; i++)
        {
    int oneX = game_info->board[winningCombos[i][0]][winningCombos[i][1]] == X_SYMBOL;
    int oneO = game_info->board[winningCombos[i][0]][winningCombos[i][1]] == O_SYMBOL;
    int second = game_info->board[winningCombos[i][0]][winningCombos[i][1]] == game_info->board[winningCombos[i][2]][winningCombos[i][3]];
    int third = game_info->board[winningCombos[i][0]][winningCombos[i][1]] == game_info->board[winningCombos[i][4]][winningCombos[i][5]];

        if (oneX && second && third)
            {
            game_info->finished = True;
            game_info->status = P1_WON;

           // printf("%s, you win!", game_info->playerNames[0]);
            }
        else if (oneO && second && third)
            {
            game_info->finished = True;
            game_info->status = P2_WON;

           // printf("%s, you win!", game_info->playerNames[1]);
            }

        }

}
