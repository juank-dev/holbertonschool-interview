#include "sandpiles.h"

static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Write a function that computes the sum of two sandpiles
 *
 * 
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

    int x = 0;
    int y = 0;
    
    int status;

    for (x = 0; x < 3; x++)
    {  
        for(y = 0; y < 3; y++)
        {
            grid1[x][y] = grid1[x][y] + grid2[x][y];
        }
    }

    while(1)
    {
        status = validation(grid1);
        if(status)
        {
            printf("=\n");
            print_grid(grid1);
            for (x = 0; x < 3; x++)
            {  
                for(y = 0; y < 3; y++)
                {
                    if(grid1[x][y] >= 4)
                    {
                        grid1[x][y] = grid1[x][y] - 4;
                        if((x + 1 >= 0) && (x + 1 < 3))
                            grid1[x + 1][y]++;
                        if(((x - 1 >= 0) && (x - 1 < 3)))
                            grid1[x - 1][y]++;
                        if(((y + 1 >= 0) && (y + 1 < 3)))
                            grid1[x][y+1]++;
                        if(((y - 1 >= 0) && (y - 1 < 3)))    
                            grid1[x][y-1]++;
                    }
                }
            }
            
            
        
        }
        else
            break;
    }
}

int validation(int grid[3][3]) 
{
    int x, y;

    for (x = 0; x < 3; x++)
    {  
        for(y = 0; y < 3; y++)
        {
            if(grid[x][y] >= 4)
                return(1);
        }
    }
    return(0);
}