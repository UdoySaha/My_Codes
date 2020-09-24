// a program that calculates the miltiplication of two matrixes
#include <stdio.h>

int choice_check(char choice);

int main()
{
    printf("Welcome! Here you can calculate The Multiplication of Two Matrixes\n\n\n\n");  // welcoming



    int Row1, Row2, Col1, Col2;

try_again:
    printf("Please enter the number of Rows and Columns for the First Matrix (Separated with Space) : "); // taking the number of rows and columns for the first matrix
    scanf("%d %d", &Row1, &Col1);

    printf("\nThank You\a\n\n");

    printf("Please enter the number of Rows and Columns for the Second Matrix (Separated with Space) : "); // taking the number of rows and columns for the second matrix
    scanf("%d %d", &Row2, &Col2);

    printf("\nThank You\a\n\n\n\n");




    if(Col1 != Row2)  // if the number of Columns of the First Matrix is not equal to the number of Rows of the Second Matrix, it is an invalid situation to calculate multiplication of two matrixes
    {
        char choice;
        printf("\aYou entered an INVALID number of Rows and Columns\n");
        printf("Do you want to try again? (Y/N) : ");

        scanf(" %c", &choice);  // taking and checking the choice of user to try the program again, because the user entered invalid numbers

        if( choice_check(choice) )
        {
            printf("\a\nLet's try again..\n\n\n\n\n");
            goto try_again;
        }
        else
        {
            printf("\n\nThank you for using the program :3\n\n");
            return 1;
        }
    }




    long long int Matrix_1 [Row1][Col1], Matrix_2 [Row2][Col2], Result_matrix [Row1][Col2], sum;
    int row, col, helper;




    // working with the first matrix
    printf("Please enter the entities of the First Matrix :\n");

    for(row=0; row < Row1; row++)  // taking the entities of matrix 1
    {
        for(col=0; col < Col1; col++)
        {
            scanf(" %lld", &Matrix_1 [row][col] );
        }
    }
    printf("(Successfully entered\a!)");

    printf("\n\nYour first matrics is : \n");
    for(row=0; row < Row1; row++)  // Showing the entities of matrix 1
    {
        for(col=0; col < Col1; col++)
        {
            printf("%5lld", Matrix_1 [row][col] );
        }
        printf("\n");
    }
    printf("\n\n\n");





    // working with the second matrix
    printf("Please enter the entities of the Second Matrix :\n");

    for(row=0; row < Row2; row++)  // taking the entities of matrix 2
    {
        for(col=0; col < Col2; col++)
        {
            scanf(" %lld", &Matrix_2 [row][col] );
        }
    }
    printf("(Successfully entered\a!)");

    printf("\n\nYour second matrics is : \n");
    for(row=0; row < Row2; row++)  // Showing the entities of matrix 2
    {
        for(col=0; col < Col2; col++)
        {
            printf("%5lld", Matrix_2 [row][col] );
        }
        printf("\n");
    }
    printf("\n\n\n");





    // Now multiplying the matrixes and storing the result in Result_matrix
    for(row=0; row < Row1; row++)
    {
        for(col=0; col < Col2; col++)
        {
            sum=0;

            for(helper=0; helper < Row2; helper++)
            {
                sum += ( Matrix_1 [row][helper] ) * ( Matrix_2 [helper][col] );
            }

            Result_matrix [row][col] = sum;
        }
    }

    printf("The result of multiplying the above metrixes is :\n");


    // showing the Result_matrix
    for(row=0; row < Row1; row++)
    {
        for(col=0; col < Col2; col++)
        {
            printf("%5lld", Result_matrix [row][col]);
        }
        printf("\n");
    }





    printf("\n\n\n\nThank You for using the program!\n\n\n\n");
    return 0;
}




int choice_check(char Y_N)
{
    if( !( (Y_N >= 'a') && (Y_N <= 'z') ) )  // if it is not lower case letter
    {

        if( (Y_N >= 'A') && (Y_N <= 'Z') )  // if it is an upper case letter
        {
            Y_N = Y_N - 'A' + 'a' ;
        }
        else      // it is not a letter
        {
            return 0;
        }
    }




    if( Y_N == 'y' )  // checks if the letter is lower case 'y' or not
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




