#include <stdio.h>
#include <stdlib.h>

void FindSolutionForQueen(int columns[], int row, int numberOfQueens, int* solutionCount);
int IsThreatened(int columns[], int newRow);
void PrintSolution(int columns[], int numberOfQueens);

int main(int argc, char* argv[])
{
    int i = 0;
    int numberOfQueens = 0;
    int solutionCount = 0;
    int* columns;
    
    if(argc < 2) {
        printf("Usage : %s <Number Of Queens>", argv[0]);
        return 1;
    }
    
    numberOfQueens = atoi(argv[1]);
    columns = (int*)calloc(numberOfQueens, sizeof(int));
    
    for(i = 0; i < numberOfQueens; i++) {
        columns[0] = i;
        FindSolutionForQueen(columns, 0, numberOfQueens, &solutionCount);
    }
    
    free(columns);

    return 0;
}

void FindSolutionForQueen(int columns[], int row, int numberOfQueens, int* solutionCount)
{
    if(IsThreatened(columns, row)) {
        return;
    }
    
    if(row == numberOfQueens - 1) {
        printf("Solution #%d : \n", ++(*solutionCount));
        PrintSolution(columns, numberOfQueens);
    }
    else {
        int i;
        
        for(i = 0; i < numberOfQueens; i++) {
            columns[row + 1] = i;
            FindSolutionForQueen(columns, row + 1, numberOfQueens, solutionCount);
        }
    }
}

int IsThreatened(int columns[], int newRow)
{
    int currentRow = 0;
    int threatened = 0;
    
    while(currentRow < newRow) {
        if(columns[newRow] == columns[currentRow] || abs(columns[newRow] - columns[currentRow]) == abs(newRow - currentRow)) {
            threatened = 1;
            break;
        }
        
        currentRow++;
    }
    
    return threatened;
}

void PrintSolution(int columns[], int numberOfQueens)
{
    int i = 0;
    int j = 0;
    
    for(i = 0; i < numberOfQueens; i++) {
        for(j = 0; j < numberOfQueens; j++) {
            if(columns[i] == j) {
                printf("Q");
            }
            else {
                printf(".");
            }
        }
        
        printf("\n");
    }
    
    printf("\n");
}
