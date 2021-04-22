#include<bits/stdc++.h>
using namespace std;

#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define MAXSIDE 25
#define MAXMINES 99
#define MOVESIZE 526 // (25 * 25 - 99)

int SIDE ;
int MINES ;

bool isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < SIDE) &&
           (col >= 0) && (col < SIDE);
}

bool isMine (int row, int col, char board[][MAXSIDE])
{
    if (board[row][col] == '*')
        return (true);
    else
        return (false);
}

// A Function to get the user's move
void makeMove(int *x, int *y)

{
    int i, j;

    printf ("    ");

    for (i=0; i<SIDE; i++)
        printf ("%d ", i);

    printf ("\n\n");

    for (i=0; i<SIDE; i++)
    {
        printf ("%d   ", i);

        for (j=0; j<SIDE; j++)
            printf ("%c ", myBoard[i][j]);
        printf ("\n");
    }
    return;
}
