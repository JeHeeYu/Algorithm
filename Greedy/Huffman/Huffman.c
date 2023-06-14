#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_BIT 8

typedef unsigned int UINT;
typedef unsigned char UCHAR;

typedef struct _Node
{
    int priority;
    void* data; 
} Node;

typedef struct _PriorityQueue
{
    Node* node; 
    int capacity;
    int usedSize;
} PriorityQueue;

typedef struct TagSymbolInfo
{
    UCHAR symbol;
    int frequency;
} SymbolInfo;

typedef struct TagHuffmanNode
{
    SymbolInfo data;
    struct TagHuffmanNode* left;
    struct TagHuffmanNode* right;
} HuffmanNode;

typedef struct TagBitBuffer
{
    UCHAR* buffer;
    UINT size;
} BitBuffer;

typedef struct TagHuffmanCode
{
    UCHAR code[MAX_BIT];
    int size;
} HuffmanCode;

PriorityQueue* CreateQueue(int size);
void Enqueue(PriorityQueue* pq, Node newNode);
void Dequeue(PriorityQueue* pq, Node* root);
int GetParent(int index);
int GetLeftChild(int index);
void SwapNodes(PriorityQueue* pq, int aIndex, int bIndex);

HuffmanNode* HuffmanCreateNode(SymbolInfo newData);
void HuffmanDestroyNode(HuffmanNode* node);
void HuffmanDestroyTree(HuffmanNode* node);
void HuffmanAddBit(BitBuffer* buffer, char bit);
void HuffmanEncode(HuffmanNode** tree, UCHAR* source, BitBuffer* encoded, HuffmanCode codeTable[MAX_BIT]);
void HuffmanDecode(HuffmanNode* tree, BitBuffer* encoded, UCHAR* decoded);
void HuffmanBuildPrefixTree(HuffmanNode **tree, SymbolInfo symbolInfoTable[MAX_CHAR]);
void HuffmanBuildCodeTable(HuffmanNode* tree, HuffmanCode codeTable[MAX_CHAR], UCHAR code[MAX_BIT], int size);
void HuffmanPrintBinary(BitBuffer* buffer);

int main()
{
    char* source = "This Is Algorithms.";
    char* decoded = "";
    
    HuffmanNode* tree = NULL;
    BitBuffer encoded = { NULL, 0 };
    HuffmanCode codeTable[MAX_CHAR];
    
    memset(&codeTable, 0, sizeof(HuffmanCode) * MAX_CHAR);
    
    HuffmanEncode(&tree, (UCHAR*)source, &encoded, codeTable);
    
    printf("Original Size : %ld Encoded Size : %d\n", (strlen(source) + 1) * sizeof(char) * 8, encoded.size);
    
    decoded = (char*)malloc(sizeof(char) * (strlen(source) + 1));
    HuffmanDecode(tree, &encoded, (UCHAR*)decoded);
    
    printf("Original : %s\n", source);
    printf("Encoded : ");
    
    HuffmanPrintBinary(&encoded);
    
    printf("\n");
    
    printf("Decoded : %s\n", decoded);
    
    HuffmanDestroyTree(tree);
    free(decoded);

    return 0;
}

PriorityQueue* CreateQueue(int size)
{
    PriorityQueue* newQueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    
    newQueue->capacity = size;
    newQueue->usedSize = 0;
    newQueue->node = (Node*)malloc(sizeof(Node) * newQueue->capacity);
    
    return newQueue;
}

void Enqueue(PriorityQueue* pq, Node newNode)
{
    int currentPosition = pq->usedSize;
    int parentPosition = GetParent(currentPosition);
    
    if(pq->usedSize == pq->capacity) {
        if(pq->capacity == 0) {
            pq->capacity = 1;
        }
        
        pq->capacity *= 2;
        
        pq->node = (Node*)realloc(pq->node, sizeof(Node) * pq->capacity);
    }
    
    pq->node[currentPosition] = newNode;
    
    // 후속  처리
    while(currentPosition > 0 && pq->node[currentPosition].priority < pq->node[parentPosition].priority) {
        SwapNodes(pq, currentPosition, parentPosition);
        
        currentPosition = parentPosition;
        parentPosition = GetParent(currentPosition);
    }
    
    pq->usedSize++;
}

void Dequeue(PriorityQueue* pq, Node* root)
{
    int parentPosition = 0;
    int leftPosition = 0;
    int rightPosition = 0;
    
    memcpy(root, &pq->node[0], sizeof(Node));
    memset(&pq->node[0], 0, sizeof(Node));
    
    pq->usedSize--;
    SwapNodes(pq, 0, pq->usedSize);
    
    leftPosition = GetLeftChild(0);
    rightPosition = leftPosition + 1;
    
    while(1) {
        int selectChild = 0;
        
        if(leftPosition >= pq->usedSize) {
            break;
        }
        
        if(rightPosition >= pq->usedSize) {
            selectChild = leftPosition;
        }
        
        else {
            if(pq->node[leftPosition].priority > pq->node[rightPosition].priority) {
                selectChild = rightPosition;
            }
            else {
                selectChild = leftPosition;
            }
        }
        
        if(pq->node[selectChild].priority < pq->node[parentPosition].priority) {
            SwapNodes(pq, parentPosition, selectChild);
            parentPosition = selectChild;
        }
        
        else {
            break;
        }
        
        leftPosition = GetLeftChild(parentPosition);
        rightPosition = leftPosition + 1;
    }
    
    if(pq->usedSize < (pq->capacity / 2)) {
        pq->capacity /= 2;
        pq->node = (Node*)realloc(pq->node, sizeof(Node) * pq->capacity);
    }
}

int GetParent(int index)
{
    return (int) ((index - 1) / 2);
}

int GetLeftChild    (int index)
{
    return (2 * index) + 1;
}

void SwapNodes(PriorityQueue* pq, int aIndex, int bIndex)
{
    int copySize = sizeof(Node);
    
    Node* temp = (Node*)malloc(copySize);
    
    memcpy(temp, &pq->node[aIndex], copySize);
    memcpy(&pq->node[aIndex], &pq->node[bIndex], copySize);
    memcpy(&pq->node[bIndex], temp, copySize);
    
    free(temp);
}

HuffmanNode* HuffmanCreateNode(SymbolInfo newData)
{
    HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
    
    return newNode;
}

void HuffmanDestroyNode(HuffmanNode* node)
{
    free(node);
}

void HuffmanDestroyTree(HuffmanNode* node)
{
    if(node == NULL) {
        return;
    }
    
    HuffmanDestroyTree(node->left);
    HuffmanDestroyTree(node->right);
    HuffmanDestroyNode(node);
}

void HuffmanAddBit(BitBuffer* buffer, char bit)
{
    UCHAR mask = 0x80;
    
    if(buffer->size % 8 == 0) {
        buffer->buffer = realloc(buffer->buffer, sizeof(UCHAR) * ((buffer->size / 8) + 1));
        buffer->buffer[buffer->size / 8] = 0x00;
    }
    
    mask >>= buffer->size % 8;
    
    if(bit == 1) {
        buffer->buffer[buffer->size / 8] |= mask;
    }
    else {
        buffer->buffer[buffer->size / 8] &= ~mask;
    }
    
    buffer->size++;
}

void HuffmanEncode(HuffmanNode** tree, UCHAR* source, BitBuffer* encoded, HuffmanCode codeTable[MAX_BIT])
{
    int i = 0;
    int j = 0;
    
    SymbolInfo symbolInfoTable[MAX_CHAR];
    UCHAR temporary[MAX_BIT];
    
    for(i = 0; i < MAX_CHAR; i++) {
        symbolInfoTable[i].symbol = i;
        symbolInfoTable[i].frequency = 0;
    }
    
    i = 0;
    
    while(source[i] != '\0') {
        symbolInfoTable[source[i++]].frequency++;
    }
    
    HuffmanBuildPrefixTree(tree, symbolInfoTable);
    
    HuffmanBuildCodeTable(*tree, codeTable, temporary, 0);
    
    i = 0;
    while(source[i] != '\0') {
        int bitCount = codeTable[source[i]].size;
        
        for(j = 0; j < bitCount; j++) {
            HuffmanAddBit(encoded, codeTable[source[i]].code[j]);
        }
        
        i++;
    }
}

void HuffmanDecode(HuffmanNode* tree, BitBuffer* encoded, UCHAR* decoded)
{
    int i;
    int index = 0;
    HuffmanNode* current = tree;
    
    for(i = 0; i <= encoded->size; i++) {
        UCHAR mask = 0x80; // 1000 0000
        
        if(current->left == NULL && current->right == NULL) {
            decoded[index++] = current->data.symbol;
            current = tree;
        }
        
        mask >>= i % 8;
        
        if((encoded->buffer[i / 8] & mask) != mask) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    
    decoded[index] = '\0';
}

void HuffmanBuildPrefixTree(HuffmanNode **tree, SymbolInfo symbolInfoTable[MAX_CHAR])
{
    int i = 0;
    Node result;
    PriorityQueue* queue = CreateQueue(0);
    
    for(i = 0; i < MAX_CHAR; i++) {
        if(symbolInfoTable[i].frequency > 0) {
            HuffmanNode* bitNode = HuffmanCreateNode(symbolInfoTable[i]);
            Node newNode;
            
            newNode.priority = symbolInfoTable[i].frequency;
            newNode.data = bitNode;
            Enqueue(queue, newNode);
        }
    }
    
    while(queue->usedSize > 1) {
        SymbolInfo newData = { 0, 0 };
        HuffmanNode* bitNode = HuffmanCreateNode(newData);
        HuffmanNode* left;
        HuffmanNode* right;
        
        Node leftNode;
        Node rightNode;
        Node newNode;
        
        Dequeue(queue, &leftNode);
        Dequeue(queue, &rightNode);
        
        left = (HuffmanNode*)leftNode.data;
        right = (HuffmanNode*)rightNode.data;
        
        bitNode->data.symbol = 0;
        bitNode->data.frequency = left->data.frequency + right->data.frequency;
        
        bitNode->left = left;
        bitNode->right = right;
        
        newNode.priority = bitNode->data.frequency;
        newNode.data = bitNode;
        
        Enqueue(queue, newNode);
    }
    
    Dequeue(queue, &result);
    
    *tree = (HuffmanNode*)result.data;
}

void HuffmanBuildCodeTable(HuffmanNode* tree, HuffmanCode codeTable[MAX_CHAR], UCHAR code[MAX_BIT], int size)
{
    if(tree == NULL) {
        return;
    }
    
    if(tree->left != NULL) {
        code[size] = 0;
        HuffmanBuildCodeTable(tree->left, codeTable, code, size + 1);
    }
    
    if(tree->right != NULL) {
        code[size] = 1;
        HuffmanBuildCodeTable(tree->right, codeTable, code, size + 1);
    }
    
    if(tree->left == NULL && tree->right == NULL) {
        int i;
        
        for(i = 0; i < size; i++) {
            codeTable[tree->data.symbol].code[i] = code[i];
        }
        
        codeTable[tree->data.symbol].size = size;
    }
}

void HuffmanPrintBinary(BitBuffer* buffer)
{
    int i;
    
    for(i = 0; i < buffer->size; i++) {
        UCHAR mask = 0x80; // 1000 0000
        mask >>= i % 8;
        
        printf("%d", (buffer->buffer[i / 8] & mask) == mask);
    }
}
