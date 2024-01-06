#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tx[] = {-1,0,1,1,1,0,-1,-1};
int ty[] = {-1,-1,-1,0,1,1,1,0};


int main()
{
    int n;
    scanf("%d",&n);
    
    char str[100];
    scanf("%s",str);
    int c = (int)strlen(str);
    int r = 1;
    char **matrix = malloc(sizeof(char*));
    matrix[0] = malloc(sizeof(char) * c+1);
    strncpy(matrix[0], str, c);
    
    while( scanf("%s",str) != EOF)
    {
        matrix = realloc(matrix, sizeof(char*) * r+1);
        matrix[r] = malloc(sizeof(char) * c+1);
        
        strncpy(matrix[r++], str, c+1);
    }
    
    
    char **next = malloc(sizeof(char*)*r);
    for(int i = 0; i < r; i++)
        next[i] = malloc(sizeof(char)*c+1);
    
    while(n--)
    {
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                int neighbor = 0;
                for(int k = 0; k < 8; k++)
                {
                    int row = i + ty[k];
                    int col = j + tx[k];
                   
                    if(row >= 0 && row < r
                       && col >= 0 && col < c
                       && matrix[row][col] == '1'
                       ){
                        neighbor++;
                    }
                    
                    
                    
                }
                
                if(neighbor <= 1 || neighbor >= 4){
                    next[i][j] = '0';

                }
                else if(neighbor == 2)
                {
                    next[i][j] = matrix[i][j];
                    
                }
                else if(neighbor == 3)
                {
                    next[i][j] = '1';
                }
                
             //   printf("i -> %d, j -> %d, nei -> %d\n",i,j,neighbor);
        }
        
        for(int i = 0; i < r; i++)
        {
            strncpy(matrix[i],next[i],c+1);
            
        }

    }
    
    
    
    
    for(int i = 0 ; i < r; i++){

        printf("%s\n",matrix[i]);
        free(matrix[i]);
        free(next[i]);
    }
    free(matrix);
    free(next);

    
    
    
    return 0;
}