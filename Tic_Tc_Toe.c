// this is a Tic-Tac-Toe game
#include <stdio.h>

// this is the main array to store whatever the data is as a board of 9 cells (initially marked with numbers 1-9)
char Board[3][3];


int  available_cells=9; //for counting the number of available cells
char Player1, Player2; // for taking the symbol of player1 and player2


// all the prototypes
void clear_screen();
void draw_the_board();
char capitalize_character(char input);
char lowerize_character(char input);
void turn_of_player(char symbol);
int validating_cell(int cell);
void get_row_col(int cell_number, int *row, int *col);
int win_or_not(char symbol);


int main()
{
    int row, col;
    char marking;
play_again:
    marking = '1';
    available_cells = 9;


    // marking the cells of the 3*3 matrix with numbers 1-9
    for(row=0; row<3; row++)
    {
        for(col=0; col<3; col++)
        {
            Board[row][col]=marking++;
        }
    }


    // taking the symbols of players1 and player2
again:
    printf("\n\n\n\n\t\tPlaese enter the symbol for Player 1 ('X' or 'O') : ");
    scanf(" %c", &Player1);
    Player1 = capitalize_character(Player1);

    if(Player1 == 'X')
    {
        Player2 = 'O';
    }
    else if(Player1 == 'O')
    {
        Player2 = 'X';
    }
    else
    {
        printf("\n\n\t\t\aInvalid input\n\n\t\tLet's try again...\n");
        sleep(2);
        clear_screen();
        goto again;
    }


    // drawing the initial board
    draw_the_board();


    //now starting to take input from users with a loop until the number of available cells is 0
    while(available_cells > 0)
    {
        turn_of_player(Player1); // player 1 will play now

        if( available_cells == 0 )
        {
            break;
        }

        turn_of_player(Player2); // player 2 will play now
    }


    // restarting the game
    char start_again;
    printf("\n\n\t\tDo you want to play again ? (Y/N) : ");
    scanf(" %c", &start_again);
    start_again = capitalize_character(start_again);
    if(start_again == 'Y')
    {
        clear_screen();
        goto play_again;
    }


    return 0;
}



//a function that clears the command screen (alternative to clrscr() function, as it is not supported in modern compilers)
void clear_screen()
{
    printf("\e[1;1H\e[2J");
}



// this fumction draws the board to the screen
void draw_the_board()
{
    clear_screen();
    printf("\n\n\t     Tic - Tac - Toe !!\n\n\n\n\n");

    printf("\t\t %c | %c | %c \n", Board[0][0], Board[0][1], Board[0][2]);

    printf("\t\t---|---|---\n");

    printf("\t\t %c | %c | %c \n", Board[1][0], Board[1][1], Board[1][2]);

    printf("\t\t---|---|---\n");

    printf("\t\t %c | %c | %c \n", Board[2][0], Board[2][1], Board[2][2]);
}



// function to capitalize a charater
char capitalize_character(char input)
{
    if(input >= 'a' && input <= 'z')
    {
        return (input - 'a' + 'A');
    }
    else
    {
        return input;
    }
}



// function to lowerize a charater
char lowerize_character(char input)
{
    if(input >= 'A' && input <= 'Z')
    {
        return (input - 'A' + 'a');
    }
    else
    {
        return input;
    }
}



// this function takes the input of a player and checks if the player has won or not
void turn_of_player(char player)
{
    int cell_choice;
choice_again:
    printf("\n\n\t\tTurn of Player : %c\n\n\t\tPlease enter a valid cell number : ", player);
    scanf("%d", &cell_choice);

    // validating the choice of cell
    if( validating_cell(cell_choice) == 0 ) // if invalid
    {
        printf("\n\t\tInvalid Choice\a\n\t\tTry again...\n");
        sleep(2);
        draw_the_board();
        goto choice_again;
    }

    int row, col;
    get_row_col(cell_choice, &row, &col); // getting the row and column of provided cell
    Board[row][col] = player; // inserting the symbol into the game board
    draw_the_board(); // drawing the updated board

    // checking if player won
    if( win_or_not(player) )
    {
        available_cells = 0;
        printf("\n\n\n\t\t\aPlayer %c has WON !!!", player);
        return;
    }

    available_cells--; // decreasing the available number of cells
    if( available_cells == 0)
    {
        printf("\n\n\n\t\t\aGame Drawn !!!");
        return;
    }
}



// validates the cell number a user has given as input.. returning 0 means invalid and 1 means valid
int validating_cell(int cell)
{
    int row, col;

    // if the cell number is greater than 9 or less than 1
    if(cell < 1  ||  cell > 9)
    {
        return 0;
    }

    // getting row and column number of that cell
    get_row_col(cell, &row, &col);

    // checking whether the cell is empty
    if(Board[row][col] == 'X' || Board[row][col] == 'O')
    {
        return 0;
    }

    //otherwise of the circumstances above
    return 1;
}



// this function calculates the row and column of the given cell
void get_row_col(int cell, int *row, int *col)
{
    *row = (cell - 1) / 3;
    *col = (cell - 1) % 3;
}



// check for winning... 1 means player has won, 0 means to continue playing
int win_or_not(char symbol)
{
    // checking the 1st row
    if( Board[0][0] == symbol  && Board[0][1] == symbol  && Board[0][2] == symbol )
    {
        return 1;
    }

    // checking the 2nd row
    if( Board[1][0] == symbol  && Board[1][1] == symbol  && Board[1][2] == symbol )
    {
        return 1;
    }

    // checking the 3rd row
    if( Board[2][0] == symbol  && Board[2][1] == symbol  && Board[2][2] == symbol )
    {
        return 1;
    }

    // checking the 1st column
    if( Board[0][0] == symbol  && Board[1][0] == symbol  && Board[2][0] == symbol )
    {
        return 1;
    }

    // checking the 2nd column
    if( Board[0][1] == symbol  && Board[1][1] == symbol  && Board[2][1] == symbol )
    {
        return 1;
    }

    // checking the 3rd column
    if( Board[0][2] == symbol  && Board[1][2] == symbol  && Board[2][2] == symbol )
    {
        return 1;
    }

    // checking the main diagonal
    if( Board[0][0] == symbol  && Board[1][1] == symbol  && Board[2][2] == symbol )
    {
        return 1;
    }

    // checking the 1st anti diagonal
    if( Board[0][2] == symbol  && Board[1][1] == symbol  && Board[2][0] == symbol )
    {
        return 1;
    }


    // otherwise
    return 0;
}
