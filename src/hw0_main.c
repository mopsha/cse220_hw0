#include <stdio.h>
#define ROWS 5
#define COLS 5

char board[ROWS][COLS] = {
    {'x', 'x', 'x', '-', 'o'}, 
    {'o', 'x', 'x', 'o', 'o'}, 
    {'o', 'x', '-', 'x', 'x'}, 
    {'o', '-', 'x', 'x', '-'}, 
    {'x', 'o', 'x', 'o', 'o'}};



/* Hint:

scanf(" %c", &choice); //this command will erase whitespace in the token selection

*/
int dash_count(){
    int amount = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(board[i][j] == '-'){
                amount++;
            }
        }
    }
    return amount;
}

void print_board(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(j == COLS - 1){
                printf("%c\n", board[i][j]);
            }else{
                printf("%c ", board[i][j]);
            }
        }
    }
}

int main() {
    char piece, xs, os;
    xs = 'x';
    os = 'o';
    int row, col, dashes;
    dashes = dash_count();
    while(dashes != 0 && dashes > 0){
        print_board();
        printf("Choose a piece (x or o) or q to quit: ");
        scanf(" %c", &piece);
        while(!(piece != xs || piece != os)){
            printf("Invalid choice. Choose a piece (x or o) or q to quit: ");
            scanf(" %c", &piece);
        }
        printf("Choose a row (0-4): ");
        scanf(" %d", &row);
        while(row >= ROWS || row < 0){
            printf("Invalid choice. Choose a row (0-4): ");
            scanf(" %d", &row);
        }
        printf("Choose a column (0-4): ");
        scanf(" %d", &col);
        while(col >= COLS || col < 0){
            printf("Invalid choice. Choose a column (0-4): ");
            scanf(" %d", &col);
        }
        if(board[row][col] == '-'){
            board[row][col] = piece;
            dashes--;
        }else{
            printf("Invalid choice. That space is already occupied.");
        }
    }
    printf("Congratulations, you have filled the board!\n");
    print_board();
    return 0;
}

