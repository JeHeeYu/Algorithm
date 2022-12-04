#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    // 왼쪽 자식을 가리키는 필드
    struct _Node* left;
    
    // 오른쪽 자식을 가리키는 필드
    struct _Node* right;
    
    // 데이터를 담는 필드
    char data;
} Node;

Node* CreateNode(char newData);
void DestroyNode(Node* node);
void PreorderPrintTree(Node* node);
void InorderPrintTree(Node* node);
void PostorderPrintTree(Node* node);
void DestroyTree(Node* node);
void ExpressionTree(char* expression, Node** node);
double Evaluate(Node* tree);

int main() 
{
    // 노드 생성
    Node* rootNode = NULL;
    
    // 계산식
    char expression[20] = "71+52-/";
    
    ExpressionTree(expression, &rootNode);
    
    // 전위 순회 방식 트리 출력
    printf("Preorder Tree\n");
    PreorderPrintTree(rootNode);
    
    printf("\n\n");
    
    // 중위 순회 방식 트리 출력
    printf("Inorder Tree\n");
    InorderPrintTree(rootNode);
    
    printf("\n\n");
    
    // 후위 순회 방식 트리 출력
    printf("Postorder Tree\n");
    PostorderPrintTree(rootNode);
    
    printf("\n");
    
    printf("Result : %f \n", Evaluate(rootNode));
    
    DestroyTree(rootNode);

    return 0;
}

Node* CreateNode(char newData)
{
    // 메모리 공간 할당
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // 각 필드 초기화
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
    
    // 노드의 메모리 주소 반환
    return newNode;
}

void DestroyNode(Node* node)
{
    free(node);
}

void PreorderPrintTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    // 뿌리 노드 출력
    printf(" %c", node->data);
    
    // 왼쪽 하위 트리 출력
    PreorderPrintTree(node->left);
    
    // 오른쪽 하위 트리 출력
    PreorderPrintTree(node->right);
}

void InorderPrintTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    printf("(");
    // 왼쪽 하위 트리 출력
    InorderPrintTree(node->left);
    
    // 뿌리 노드 출력
    printf("%c", node->data);
    
    // 오른쪽 하위 트리 출력
    InorderPrintTree(node->right);
    
    printf(")");
}

void PostorderPrintTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    // 왼쪽 하위 트리 출력
    PostorderPrintTree(node->left);
    
    // 오른쪽 하위 트리 출력
    PostorderPrintTree(node->right);
    
    // 뿌리 노드 출력
    printf(" %c", node->data);
}

void DestroyTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    DestroyTree(node->left);
    DestroyTree(node->right);
    DestroyNode(node);
}

void ExpressionTree(char* expression, Node** node)
{
    // 전체 문자열 길이
    int len = strlen(expression);
    
    // 읽은 토큰
    char token = expression[len - 1];
    expression[len - 1] = '\0';
    
    switch(token) {
        // 연산자일 경우
        case '+':
        case '-':
        case '*':
        case '/':
            (*node) = CreateNode(token);
            ExpressionTree(expression, &(*node)->right);
            ExpressionTree(expression, &(*node)->left);
            break;
        
        // 피연산자일 경우
        default:
            (*node) = CreateNode(token);    
            break;
    }
}

double Evaluate(Node* tree)
{
    char temp[2];
    
    // 왼쪽 수식 트리의 결과를 저장할 변수
    double left = 0;
    
    // 오른쪽 수식 트리이ㅡ 결과를 저장할 변수
    double right = 0;
    
    // 계산 결과를 저장할 변수
    double result = 0;
    
    // 트리가 빈 트리일 경우
    if(tree == NULL) {
        return 0;
    }
    
    switch(tree->data) {
        // 연산자인 경우
        case '+':
        case '-':
        case '*':
        case '/':
            left = Evaluate(tree->left);
            right = Evaluate(tree->right);
            
            if(tree->data == '+') {
                result = left + right;
            }
            
            else if(tree->data == '-') {
                result = left - right;
            }
            
            else if(tree->data == '*') {
                result = left * right;
            }
            
            else if(tree->data == '/') {
                result = left / right;
            }
        
            break;
        // 피연산자인 경우
        default:
            memset(temp, 0, sizeof(temp));
            temp[0] = tree->data;
            
            // 숫자로 변환
            result = atof(temp);
            break;
    }
    
    return result;
}
