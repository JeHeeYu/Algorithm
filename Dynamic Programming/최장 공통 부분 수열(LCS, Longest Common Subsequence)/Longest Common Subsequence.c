#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct structLCSTable
{
    int** data;
} LCSTable;

void LCS_TraceBack(char* x, char* y, int m, int n, LCSTable* table, char* lcs);
int LCS(char* x, char* y, int i, int j, LCSTable* table);
void LCS_PrintTable(LCSTable* table, char* x, char* y, int lengthX, int lengthY);

int main()
{
    char* x = "GOOD MORNING.";
    char* y = "GUTEN MORGEN.";
    char* result;
    
    int lengthX = strlen(x);
    int lengthY = strlen(y);
    
    int i = 0;
    int length = 0;
    
    LCSTable table;
    
    table.data = (int**)malloc(sizeof(int*) * (lengthX + 1));
    
    for(i = 0; i < lengthX + 1; i++) {
        table.data[i] = (int*)malloc(sizeof(int) * (lengthY + 1));
        
        memset(table.data[i], 0, sizeof(int) * (lengthY + 1));
    }
    
    length = LCS(x, y, lengthX, lengthY, &table);
    
    LCS_PrintTable(&table, x, y, lengthX, lengthY);
    
    size_t tableSize = sizeof(table.data[lengthX][lengthY] + 1);
    result = (char*)malloc(tableSize);
    memset(result, 0, tableSize);
    
    LCS_TraceBack(x, y, lengthX, lengthY, &table, result);
    
    printf("\n");
    printf("LCS:\%s\" (Length:%d)", result, length);

    return 0;
}

int LCS(char* x, char* y, int i, int j, LCSTable* table)
{
    int m = 0;
    int n = 0;

    for(m = 0; m <= i; m++) {
        table->data[m][0] = 0;
    }
    
    for(n = 0; n <= j; n++) {
        table->data[0][n] = 0;
    }
    
    for(m = 1; m <= i; m++) {
        for(n = 1; n <= j; n++) {
            if(x[m - 1] == y[n - 1]) {
                table->data[m][n] = table->data[m - 1][n - 1] + 1;
            }
            else {
                if(table->data[m][n - 1] >= table->data[m - 1][n]) {
                    table->data[m][n] = table->data[m][n - 1];
                }
                else {
                    table->data[m][n] = table->data[m - 1][n];
                }
            }
        }
    }
    
    return table->data[i][j];
}

void LCS_TraceBack(char* x, char* y, int m, int n, LCSTable* table, char* lcs)
{
    if(m == 0 || n == 0) {
        return;
    }
    
    if(table->data[m][n] > table->data[m][n - 1]
        && table->data[m][n] > table->data[m - 1][n]
        && table->data[m][n] > table->data[m - 1][n - 1])  {
            char tempLCS[100];
            strcpy(tempLCS, lcs);
            sprintf(lcs, "%c%s", x[m - 1], tempLCS);
            
            LCS_TraceBack(x, y, m - 1, n - 1, table, lcs);
        }
        else if(table->data[m][n] > table->data[m - 1][n]
                && table->data[m][n] == table->data[m][n - 1]){
            LCS_TraceBack(x, y, m, n - 1, table, lcs);
        }
        else {
            LCS_TraceBack(x, y, m - 1, n, table, lcs);
        }
}

void LCS_PrintTable(LCSTable* table, char* x, char* y, int lengthX, int lengthY)
{
    int i = 0;
    int j = 0;
    
    printf("%4s", "");
    
    for(i = 0; i < lengthY + 1; i++) {
        printf("%c ", y[i]);
    }
    
    printf("\n");
    
    for(i = 0; i < lengthX + 1; i++) {
        if(i == 0) {
            printf("%2s", "");
        }
        else {
            printf("%-2c", x[i -1]);
        }
        
        for(j = 0; j < lengthY + 1; j++) {
            printf("%d ", table->data[i][j]);
        }
        
        printf("\n");
    }
}
