#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define START    'S'   // 시작점
#define GOAL     'G'   // 탈출구
#define WAY      ' '   // 길
#define WALL     '#'   // 벽
#define MARKED   '+'   // 탈출구로 향하는 길 표식

#define MAX_BUFFER 1024
#define INIT_VALUE -1

enum DIRECTION { NORTH, SOUTH, EAST, WEST };
enum RESULT { FAIL, SUCCEED };

typedef struct tagMazeInfo
{
    int columnSize;  // 너비
    int rowSize;     // 높이
    char** data;     // 동적으로 할당한 2차원 배열을 담기 위한 2차원 포인터
} MazeInfo;

typedef struct tagPosition
{
    int x;   // 수평 위치
    int y;   // 수직 위치
} Position;

int Solve(MazeInfo* maze);
int MoveTo(MazeInfo* maze, Position* current, int direction);
int GetNextStep(MazeInfo* maze, Position* current, int direction, Position* next);
int GetMaze(char* filePath, MazeInfo* maze);

int main(int argc, char* argv[])
{
    int i = 0;
    int j = 0;
    
    MazeInfo maze;
    
    if(argc < 2) {
        printf("Usage : MazeSolver <MazeFile>\n");
        return 0;
    }
    
    if(GetMaze(argv[1], &maze) == FAIL) {
        return 0;
    }
    
    if(Solve(&maze) == FAIL) {
        return 0;
    }
    
    for(i = 0; i < maze.rowSize; i++) {
        for(j = 0; j < maze.columnSize; j++) {
            printf("%c", maze.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int Solve(MazeInfo* maze)
{
    int i = 0;
    int j = 0;
    int startFound = FAIL;
    int result = FAIL;
    
    Position start;
    
    // 시작점 S를 찾음
    for(i = 0; i < maze->rowSize; i++) {
        for(j = 0; j < maze->columnSize; j++) {
            if(maze->data[i][j] == START) {
                start.x = j; // column
                start.y = i; // row
                startFound = SUCCEED;
                break;
            }
        }
    }
    
    if(startFound == FAIL) {
        return FAIL;
    }
    
    // 북, 남, 동, 서 순으로 시도
    if(MoveTo(maze, &start, NORTH)) {
        result = SUCCEED;
    }
    else if(MoveTo(maze, &start, SOUTH)) {
        result = SUCCEED;
    }
    else if(MoveTo(maze, &start, EAST)) {
        result = SUCCEED;
    }
    else if(MoveTo(maze, &start, WEST)) {
        result = SUCCEED;
    }
    
    maze->data[start.x][start.y] = START;
    
    return result;
}

int MoveTo(MazeInfo* maze, Position* current, int direction)
{
    int i = 0;
    
    // 코딩 편의를 위해 네 방향을 배열에 보관
    int dirs[] = { NORTH, SOUTH, EAST, WEST };
    
    Position next;
    
    if(maze->data[current->x][current->y] == GOAL) {
        return SUCCEED;
    }
    
    // 지나왔음을 표시
    maze->data[current->y][current->x] = MARKED;
    
    for(i = 0; i < 4; i++) {
        if(GetNextStep(maze, current, dirs[i], &next) == FAIL) {
            continue;
        }
        
        if(MoveTo(maze, &next, NORTH) == SUCCEED) {
            return SUCCEED;
        }
    }
    
    maze->data[current->y][current->x] = WAY;
    
    return FAIL;
}

int GetNextStep(MazeInfo* maze, Position* current, int direction, Position* next)
{
    switch(direction) {
        case NORTH:
            next->x = current->x;
            next->y = current->y - 1;
            
            if(next->y == -1) {
                return FAIL;
            }
            
            break;
            
        case SOUTH:
            next->x = current->x;
            next->y = current->y + 1;
        
            if(next->y == maze->rowSize) {
                return FAIL;
            }
            
            break;
        case EAST:
            next->x = current->x + 1;
            next->y = current->y;
        
            if(next->y == maze->columnSize) {
                return FAIL;
            }
            
            break;
        case WEST:
            next->x = current->x - 1;
            next->y = current->y;
        
            if(next->x == -1) {
                return FAIL;
            }
            
            break;
    }
    
    if(maze->data[next->y][next->x] == WALL) {
        return FAIL;
    }
    if(maze->data[next->y][next->x] == MARKED) {
        return FAIL;
    }
    
    return SUCCEED;
}

int GetMaze(char* filePath, MazeInfo* maze)
{
    int i = 0;
    int j = 0;
    int rowSize = 0;
    int columnSize = INIT_VALUE;
    
    FILE* fp;
    char buffer[MAX_BUFFER];
    
    if((fp == fopen(filePath, "r")) == NULL) {
        printf("Cannot open file%s\n", filePath);
        return FAIL;
    }
    
    while(fgets(buffer, MAX_BUFFER, fp) != NULL) {
        rowSize++;
        
        if(columnSize == INIT_VALUE) {
            columnSize = strlen(buffer) - 1;
        }
        else if(columnSize != strlen(buffer) - 1) {
            printf("Maze data in file : %s is not valid\n", filePath);
            fclose(fp);
            
            return FAIL;
        }
    }
    
    maze->rowSize = rowSize;
    maze->columnSize = columnSize;
    maze->data = (char**)malloc(sizeof(char*) * rowSize);
    
    for(i = 0; i < rowSize; i++) {
        maze->data[i] = (char*)malloc(sizeof(char) * columnSize);
    }
    
    rewind(fp);
    
    for(i = 0; i < rowSize; i++) {
        fgets(buffer, MAX_BUFFER, fp);
        
        for(j = 0; j < columnSize; j++) {
            maze->data[i][j] = buffer[j];
        }
    }
    
    fclose(fp);
    
    return SUCCEED;
}
