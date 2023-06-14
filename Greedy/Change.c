#include <stdio.h>
#include <stdlib.h>

void GetChange(int price, int pay, int coinUnits[], int change[], int size);
int CountCoins(int amount, int coinUnit);
void PrintChange(int coinUnits[], int change[], int size);
int Compare(const void* a, const void* b);

int main()
{
    int i = 0;
    int pay = 0;
    int price = 0;
    int unitCount = 0;
    int* coinUnits = NULL;
    int* change = NULL;
    
    printf("동전의 가짓수를 입력하세요 :");
    scanf("%d", &unitCount);
    
    coinUnits = (int*)malloc(sizeof(int) * unitCount);
    change = (int*)malloc(sizeof(int) * unitCount);
    
    for(i = 0 ; i < unitCount; i++) {
        printf("[%d] 번째 동전의 단위를 입력하세요 : ", i);
        scanf("%d", &coinUnits[i]);
    }
    
    qsort(coinUnits, unitCount, sizeof(int), Compare);
    
    printf("물건 가격을 입력하세요 : ");
    scanf("%d", &price);
    
    printf("손님이 지불한 돈은 얼마입니까? : ");
    scanf("%d", &pay);
    
    GetChange(price, pay, coinUnits, change, unitCount);
    
    PrintChange(coinUnits, change, unitCount);

    return 0;
}

void GetChange(int price, int pay, int coinUnits[], int change[], int size)
{
    int i = 0;
    int changeAmount = pay - price;
    
    // 해 검사 
    for(i = 0; i < size; i++) {
        // 해 선택
        change[i] = CountCoins(changeAmount, coinUnits[i]);
        changeAmount = changeAmount - (coinUnits[i] * change[i]);
    }
}

int CountCoins(int amount, int coinUnit)
{
    int coinCount = 0;
    int currentAmount = amount;
    
    while(currentAmount >= coinUnit) {
        coinCount++;
        currentAmount = currentAmount - coinUnit;
    }
    
    return coinCount;
}

void PrintChange(int coinUnits[], int change[], int size)
{
    int i = 0;
    
    for(i = 0; i < size; i++) {
        printf("%8d원 : %d개\n", coinUnits[i], change[i]);
    }
}

int Compare(const void* a, const void* b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    
    if(_a < _b) {
        return 1;
    }
    else {
        return -1;
    }
}
