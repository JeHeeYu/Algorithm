#include <stdio.h>
#include <stdlib.h>

// key와 value 값을 갖고 있는 노드
typedef struct _Node
{
    int key;
    int value;
} Node;

// 해시 테이블
typedef struct _HashTable
{
    int tableSize;
    Node* table;
} HashTable;

HashTable* CreateHashTable(int tableSize);
void DestroyHashTable(HashTable* table);

int Hash(int key, int tableSize);
int GetValue(HashTable* table, int key);
void Insert(HashTable* table, int key, int value);

int main()
{
    HashTable* table = CreateHashTable(193);
    
    // 데이터 삽입
    Insert(table, 111, 111111111);
    Insert(table, 222, 222222222);
    Insert(table, 333, 333333333);
    Insert(table, 444, 444444444);
    
    // 데이터 출력
    printf("Key : %d, Value : %d\n", 111, GetValue(table, 111));
    printf("Key : %d, Value : %d\n", 222, GetValue(table, 222));
    printf("Key : %d, Value : %d\n", 333, GetValue(table, 333));
    printf("Key : %d, Value : %d\n", 444, GetValue(table, 444));
    
    DestroyHashTable(table);
    
    return 0;
}

HashTable* CreateHashTable(int tableSize)
{
    // 새로운 해시 테이블 생성
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->table = (Node*)malloc(sizeof(Node) * tableSize);
    table->tableSize = tableSize;
    
    return table;
}

void DestroyHashTable(HashTable* table)
{
    // 메모리 소멸
    free(table->table);
    free(table);
}

int Hash(int key, int tableSize)
{
    // 키를 사이즈로 나눈 나머지 값으로 해싱
    return key % tableSize;
}

int GetValue(HashTable* table, int key)
{
    // 테이블 주소 해싱
    int address = Hash(key, table->tableSize);
    
    return table->table[address].value;
}

void Insert(HashTable* table, int key, int value)
{
    // 테이블 주소 해싱
    int address = Hash(key, table->tableSize);
    
    // 해싱한 주소에 데이터 삽입
    table->table[address].key = key;
    table->table[address].value = value;
}
