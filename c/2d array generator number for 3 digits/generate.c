#include <stdio.h>
#include <math.h>
/*
    ->input the max number (max is 9)
    ->generate [][][] combination of numbers from 0 to 9
    ->display the 2d array

    ->expected output   000 001 002 010 011 012 020 021 022 100...

*/

int main()
{
    int max;

    printf("enter max number (shouldnt exceed number 9)\n");
    scanf("%d", &max);

    max += 1; //just to make 9 to
    int column = 3;
    int max2 = pow(max, column); //max squared

    int array[max2][column];

    int row1 = 0;
    int row2 = 0;

    //generate numbers
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            for (int k = 0; k < max; k++)
            {
                array[row1][0] = i; //[][]
                array[row1][1] = j; //[][]
                array[row1][2] = k; //[][]

                row1++;
            }
        }
    }

    //show the combination
    for (int i = 0; i < max2; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", array[i][j]);
            if (j == column - 1)
            {
                printf("\n");
            }
        }
    }
}

/*--TODO--
    *Make it reccursive (issue is with pointing to 2d arrays )

    *each column is an 1d array:kinda making the 2d array into n of arrays
    [][][][]    
    [][][][]   -->>  this is 4 arrays 
    [][][][]
    each level of arrays has it own pattern of changing the digits

*/
