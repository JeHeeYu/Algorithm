#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 해시 테이블이 비어 있을 때 0, 비어 있지 않으면 1
enum ElementStatus
{
    EMPTY       = 0,
    OCCUPIED    = 1
};

typedef struct _Node
{
    char* key;
    char* value;
    
    enum ElementStatus status;
} Node;

typedef struct _HashTable
{
    int occupiedCount;
    int tableSize;
    
    Node* table;
} HashTable;


// 해시 테이블 생성
HashTable* CreateHashTable(int tableSize);

// 해시 테이블 소멸
void DestroyHashTable(HashTable* table);

// 노드 클리어
void ClearNode(Node* node);

// 이중 해싱
int Hash(char* key, int keyLength, int tableSize);
int Hash2(char* key, int keyLength, int tableSize);

// 주소 내에 데이터 확인
char* GetValue(HashTable* table, char* key);

// 데이터 삽입
void Insert(HashTable** table, char* key, char* value);

// 재해싱
void Rehash(HashTable** table);

int main()
{
    HashTable* table = CreateHashTable(11);
    
    Insert(&table, "A", "AAAAAAAA");
    Insert(&table, "B", "BBBBBBBB");
    Insert(&table, "C", "CCCCCCCC");
    Insert(&table, "D", "DDDDDDDD");
    Insert(&table, "E", "EEEEEEEE");
    Insert(&table, "F", "FFFFFFFF");
    Insert(&table, "G", "GGGGGGGG");
    Insert(&table, "H", "HHHHHHHH");
    Insert(&table, "I", "IIIIIIII");
    Insert(&table, "J", "JJJJJJJJ");
    Insert(&table, "K", "KKKKKKKK");


    printf("\n");
    
    printf("Key : [%s], Value : [%s]\n", "A", GetValue(table, "A"));
    printf("Key : [%s], Value : [%s]\n", "B", GetValue(table, "B"));
    printf("Key : [%s], Value : [%s]\n", "C", GetValue(table, "C"));
    printf("Key : [%s], Value : [%s]\n", "D", GetValue(table, "D"));
    printf("Key : [%s], Value : [%s]\n", "E", GetValue(table, "E"));
    printf("Key : [%s], Value : [%s]\n", "F", GetValue(table, "F"));
    printf("Key : [%s], Value : [%s]\n", "G", GetValue(table, "G"));
    printf("Key : [%s], Value : [%s]\n", "H", GetValue(table, "H"));
    printf("Key : [%s], Value : [%s]\n", "I", GetValue(table, "I"));
    printf("Key : [%s], Value : [%s]\n", "J", GetValue(table, "J"));
    printf("Key : [%s], Value : [%s]\n", "K", GetValue(table, "K"));


    return 0;
}


HashTable* CreateHashTable(int tableSize)
{
    // 테이블 생성
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->table = (Node*)malloc(sizeof(Node) * tableSize);
    
    memset(table->table, 0, sizeof(Node) * tableSize);
    
    table->tableSize = tableSize;
    table->occupiedCount = 0;
    
    return table;
}

void DestroyHashTable(HashTable* table)
{
    int i = 0;
    
    // 링크드 리스트 제거
    for(i = 0; i < table->tableSize; i++) {
        ClearNode(&(table->table[i]));
    }
    
    // 해시 테이블 제거
    free(table->table);
    free(table);
}

void ClearNode(Node* node)
{
    if(node->status == EMPTY) {
        return;
    }
    
    free(node->key);
    free(node->value);
}

int Hash(char* key, int keyLength, int tableSize)
{
    int i = 0;
    int value = 0;
    
    for(i = 0; i < keyLength; i++) {
        value = (value << 3) + key[i];
    }
    
    value = value % tableSize;
    
    return value;
}

int Hash2(char* key, int keyLength, int tableSize)
{
    int i = 0;
    int value = 0;
    
    for(i = 0; i < keyLength; i++) {
        value = (value << 2) + key[i];
    }
    
    value = value % (tableSize - 3);
    
    return value + 1;
}

char* GetValue(HashTable* table, char* key)
{
    int keyLength = strlen(key);
    int address = Hash(key, keyLength, table->tableSize);
    int stepSize = Hash2(key, keyLength, table->tableSize);
    
    while(table->table[address].status != EMPTY && strcmp(table->table[address].key, key) != 0) {
        address = (address + stepSize) & table->tableSize;
    }
    
    return table->table[address].value;
}

void Insert(HashTable** table, char* key, char* value)
{
    // keyLength : key길이, adress : 해싱한 주소, stepSize : 이동폭
    int keyLength, address, stepSize;
    
    // 재해싱 여부
    double usage;
    
    usage = (double)(*table)->occupiedCount / (*table)->tableSize;
    
    if(usage > 0.5) {
        Rehash(table);
    }
    
    keyLength = strlen(key);
    address = Hash(key, keyLength, (*table)->tableSize);
    stepSize = Hash2(key, keyLength, (*table)->tableSize);
    
    while((*table)->table[address].status != EMPTY && strcmp((*table)->table[address].key, key) != 0) {
        printf("Collision Occured Key : [%s], Address : [%d], StepSize : [%d]\n", key, address, stepSize);
        
        // 데이터를 삽입할 주소 재탐색
        address = (address + stepSize) % (*table)->tableSize;
    }
    
    (*table)->table[address].key = (char*)malloc(sizeof(char) * (keyLength) + 1);
    strcpy((*table)->table[address].key, key);
    
    (*table)->table[address].value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy((*table)->table[address].value, value);
    
    (*table)->table[address].status = OCCUPIED;
    (*table)->occupiedCount++;
    
    printf("Key[%s] enter at address : [%d]\n", key, address);
}

void Rehash(HashTable** table)
{
    int i = 0;
    Node* oldTable = (*table)->table;
    
    // 새로운 테이블 생성
    HashTable* newTable = CreateHashTable((*table)->tableSize * 2);
    
    printf("\n Rehash. New Table Size is : %d\n\n", newTable->tableSize);
    
    // 이전의 해시 테이블 데이터를 새 해시 테이블 데이트로 이동
    for(i = 0; i < (*table)->tableSize; i++) {
        if(oldTable[i].status == OCCUPIED) {
            Insert(&newTable, oldTable[i].key, oldTable[i].value);
        }
    }
    
    // 이전의 해시 테이블 소멸
    DestroyHashTable((*table));
    
    // 기존 테이블에 새로운 해시 테이블 주소 대입
    (*table) = newTable;
}
