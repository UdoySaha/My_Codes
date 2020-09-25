
//a function that clears the command screen (alternative to clrscr() function, as it is not supported in modern compilers)
void clear_screen()
{
    printf("\e[1;1H\e[2J");
}
/*
            Explanation:
The \e[1;1H sets your cursor to the top left.
The \e[2J prints a space over all existing screen characters.
*/

