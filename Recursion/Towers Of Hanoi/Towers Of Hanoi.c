#include <stdio.h>

void move(int no, int x, int y);

int main()
{
    int n; // 원반 개수
    
    printf("원반 개수 : ");
    scanf("%d", &n);
    
    move(n, 1, 3);
    
    return 0;
}

// no : 원반 개수, x : 시작 기둥 번호, y : 목표 기둥 번호
void move(int no, int x, int y)
{
    // 그룹을 시작 기둥에서 중간 기둥으로
    if(no > 1) {
        move(no - 1, x, 6 - x - y);
    }
    
    printf("원반[%d]을 %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);
    
    // 그룹을 중간 기둥에서 목표 기둥으로
    if(no > 1) {
        move(no - 1, 6 - x - y, y);
    }
    
}
