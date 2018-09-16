#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdbool.h>

#define MAX_NAME_LEN 50
enum Bool { False, True };
enum status { P1_TURN, P2_TURN, P1_WON, P2_WON, DRAW };
typedef enum Bool boolean;
const char SPACE= '-';
const char X_SYMBOL = 'X';
const char O_SYMBOL = 'O';

struct game {
    char board[3][3];
    char playerNames[2][MAX_NAME_LEN];
    int status;
    bool finished;
};

void print_status(struct game* pGame);
void initialise_game(struct game* p_game_info, char* name1, char* name2);
void draw_Banner();
void display_board(char board[3][3]);
void print_status(struct game* pGame);
void display_board_positions();
void get_row_col(int position, int* row, int* col);
void process_move(struct game* game_info);
void check_winner(struct game* game_info);




#endif // GAME_H_INCLUDED
