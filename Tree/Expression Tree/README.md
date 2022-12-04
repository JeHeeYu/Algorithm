## 요약
<ul>
  <li>수식 계산을 위한 트리 구조로 후위 변환 표기식으로 트리를 구축하고, 중위 표기식으로 변환하여 사용</li>
  <li>1개의 연산자와 2개의 피연산자를 요구함</li>
  <li>피 연산자는 잎 노드임</li>
  <li>연산자는 뿌리 또는 가지 노드임</li>
  <li>뒤에서부터 역순으로 계산이 되어야 함</li>
  <li>뒤에서부터 1개씩 토큰을 확인해 연산자인지 피연산자인지 확인</li>
</ul>

## 수식 트리(Experssion Tree)
수식 트리란 이름 그대로 수식을 표현하는 트리이며, 수식 이진 트리라고도 한다.
<br>
<br>
하나의 연산자가 2개의 피연산자를 취한다는 가정 아래, 수식 트리는 일반적으로 2가지의 규칙을 가진다.

<ul>
  <li>피연산자는 잎 노드이다.</li>
  <li>연산자는 뿌리 노드 또는 가지 노드이다.</li>
</ul>

예를 들어 아래와 같은 수식이 있다.
```
(1 * 2) + (7 - 8)
```

피연산자 1, 2, 7, 8은 모두 잎 노드이고, 연산자는 뿌리노드 여야 한다.
<br>
이 수식을 표현한 트리가 아래 그림의 트리이다.

<br>

![image](https://user-images.githubusercontent.com/87363461/205478840-0b6482f1-0f82-4cc4-94f3-655ac482b49a.png)

<br>

뿌리 노드와 가지 노드 모두 피연산자를 양쪽 자식으로 가진다.
<br>
여기에서 피연산자는 숫자(Number)일 수도 있고, 또 다른 식(Expression)일 수도 있다.
<br>
<br>
뿌리 노드인 + 연산자는 왼쪽 하위 트리가 표현하는 수식 (1 * 2)와 오른쪽 하위 트리가 표현하는 수식 (7 - 8)을 피연산자로 갖고 있다.
<br>
<br>
따라서 뿌리 노드를 연산자로, 왼쪽 하위 수식 트리의 결괏값과 오른쪽 하위 수식 트리의 결괏값을 피연산자로 하여 계산을 수행하면 전체 수식의 계산 결과를 얻을 수 있다.
<br>

![image](https://user-images.githubusercontent.com/87363461/205478889-d5f4da16-04a7-48c0-896e-e7f638756bf9.png)

<br>

하위 수식 트리 역시 그 안에서 뿌리 노드를 연산자, 왼쪽/오른쪽 하위 수식 트리의 계산 결괏값을 피연산자로 삼아 계산하여 결과를 얻는다.
<br>
<br>
하위 수식 트리가 잎 노드인 경우 노드에 담긴 수를 피연산자로 삼는다.

## 수식 트리 구축 방법
수식 트리를 구축하기 위해 후위 순회 방식을 적용해야 한다. 후위 순회 방식으로 트리를 구축 후 중위 표기식으로 변환해서 사용한다.
<br>
후위 순회는 왼쪽 하위 트리 -> 오른쪽 하위 트리 -> 뿌리 노드 순으로 순회하는 방식이다.
<br>
<br>
수식 트리를 구축하기 위해 다음과 같은 순서로 프로그램이 동작한다.

<ol>
  <li>수식을 뒤에서부터 앞쪽으로 읽어나가며 토큰을 취한다.</li>
  <li>수식에서 제일 마지막에 있는 토큰으로 뿌리 노드를 생성한다. 후위 표기식에서 가장 마지막에 있는 토큰은 항상 연산자다.</li>
  <li>읽어낸 토큰이 연산자인 경우 가지 노드를 생성하며 이 토큰 다음에 따라오는 2개의 토큰으로 각각 좌 우 자식 노드와 왼쪽 자식 노드를 생성한다.</li>
  <li>이후 다음 토큰이 연산자일 경우 이 토큰에서 만들어지는 하위 트리가 완성된 이후에 읽어낸 토큰으로 왼쪽 자식 노드를 생성한다.</li>
  <li>읽어낸 토큰이 숫자인 경우 잎 노드를 생성한다.</li>
</ol>

<br>

위에서 예로 든 수식을 트리로 만들어내는 과정이다.
```
(1 * 2) + (7 - 8)
```
먼저 수식을 후위 표기식으로 변환하면 차례로 1 2 * 7 8 9 +가 된다.
<br>
여기서 마지막 토큰인 +을 취한다.
<br>
<br>
마지막 토큰인 +은 연산자이므로 + 연산자로 뿌리 노드를 생성한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/205479112-69b9eab8-30af-4690-8479-e1ab885e96cf.png)


<br>
이렇게 하면 뿌리 노드가 만들어지고, 이후 뒤에서 앞쪽으로 계속 토큰을 읽어 나가며 수식 트리를 완성한다.
<br>
<br>
하나의 연산자에 2개의 피연산자를 취하는 규칙이 있었으니, 2개의 피연산자를 요구한다.
<br>
그래서 다음 토큰 1개씩 2개를 읽어 수인지 확인하고 자식 노드로 만들어 붙인다.
<br>
<br>
만약 2개의 토큰 중 첫 번째 토큰이 연산자라면 두 번째 토큰을 첫 번째 토큰의 피연산자로 사용해야 한다.
<br>
<br>
마지막 토큰인 + 연산자 다음 토큰은 - 연산자이다. 이 경우 또다른 2개의 토큰이 필요하다.
<br>
이 토큰 역시 또 다른 2개의 토큰이 필요한 연산자이다. 일단 - 토큰으로 뿌리 노드의 오른쪽 자식 노드를 만든다.
<br>

![image](https://user-images.githubusercontent.com/87363461/205479118-456a72cc-dc5e-4293-8f68-2df7c8778cc5.png)

<br>

읽은 - 노드는 연산자 노드이니 피연산자 2개를 자식으로 필요로 한다.
<br>
그래서 다음 토큰을 1개씩 확인하니 8과 7이고, 이 값들을 자식으로 만들어 넣는다.
<br>
<br>
노드들은 모두 숫자이므로 잎 노드가 되고, + 노드의 오른쪽 하위 수식 트리가 만들어진다.

<br>

![image](https://user-images.githubusercontent.com/87363461/205479160-af70ef7c-7e55-4856-b042-99e088f915f3.png)

<br>

다음 토큰을 확인하니 * 연산자이다. 이 연산자를 + 노드의 왼쪽 자식 노드로 만들어 넣는다.

<br>

![image](https://user-images.githubusercontent.com/87363461/205479176-6326b89d-e74d-47c5-89b0-89c1a8924770.png)

<br>

확인한 * 노드는 연산자이므로, 2개의 피연산자 자식 노드를 필요로 한다.
<br>
다음 토큰들을 확인해보니 각각 2와 1인 숫자들이다.
<br>
이 숫자들을 각각 오른쪽 자식 노드와 왼쪽 자식 노드로 만들어 * 노드에 붙인다.
<br>
<br>
이제 왼쪽 하위 수식 트리도 완성되었으므로 전체 수식 트리가 완성된다.
<br>

![image](https://user-images.githubusercontent.com/87363461/205479206-c13da65f-a0eb-44ff-b446-127b173f1448.png)

<br>

## 수식 트리의 기본 연산

### 노드 선언
노드를 이루는 구조체로, left, right, data 필드가 존재한다.

```
typedef struct _Node
{
    // 왼쪽 자식을 가리키는 필드
    struct _Node* left;
    
    // 오른쪽 자식을 가리키는 필드
    struct _Node* right;
    
    // 데이터를 담는 필드
    char data;
} Node;
```

### 노드 생성
노드 생성을 위한 함수로, 먼저 malloc() 함수를 사용해 구조체의 크기만큼 메모리 공간을 할당한다.
<br>
할당한 메모리 공간을 newNode 포인터에 저장하고, left, right 필드를 NULL로 초기화한다.
<br>
data 필드에는 매개 변수로 받은 값을 할당하고 마지막으로 노드의 포인터를 반환한다.

```
Node* CreateNode(char newData)
{
    // 메모리 공간 할당
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // 각 필드 초기화
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
    
    // 노드의 포인터 반환
    return newNode;
}
```

### 노드 소멸
노드 소멸은 free() 함수를 이용해 공간 할당을 해제한다.
```
void DestroyNode(Node* node)
{
    free(node);
}
```

### 트리 출력
트리 출력은 전위, 중위, 후위 순회 방법을 이용해 출력할 수 있다.

### 전위 순회를 이용한 수식 트리 출력
전위 순회는 뿌리 노드 -> 잎 노드까지, 위에서 아래로 타고 내려온다.
```
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
```

### 중위 순회를 이용한 수식 트리 출력
중위 순회는 왼쪽 하위 트리 -> 뿌리 -> 오른쪽 하위 트리 순으로 방문한다.

```
void InorderPrintTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    // 왼쪽 하위 트리 출력
    InorderPrintTree(node->left);
    
    // 뿌리 노드 출력
    printf(" %c", node->data);
    
    // 오른쪽 하위 트리 출력
    InorderPrintTree(node->right);
}
```

### 후위 순회를 이용한 수식 트리 출력
후위 순회는 왼쪽 하위 트리 -> 오른쪽 하위 트리 -> 뿌리 순으로 방문한다.

```
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
```

### 후위 순회를 이용한 트리 소멸
트리를 생성할 때는 노드들이 어떤 순서로 생성되는지 상관 없지만, 소멸은 얘기가 다르다.
<br>
트리를 소멸할 때 반드시 <b>잎 노드부터 제거해야 한다.</b>
<br>
<br>
따라서 잎 노드부터 뿌리 노드로 방문하는 후위 순회를 이용하면 문제 없이 소멸시킬 수 있다.


<br>

![image](https://user-images.githubusercontent.com/87363461/205478357-95dac247-046a-4d34-9a78-e22e2f67170e.png)


<br>

```
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
```
### 수식 트리 구축
수식 트리 구축을 하기 위해 토큰을 읽어 연산자인지, 숫자인지 판단해야 한다.
<br>
읽어낸 토큰이 연산자라면 이는 2개의 피연산자를 필요로 한다.
<br>
<br>
따라서 이 경우에는 방금 읽어낸 연산자 토큰을 노드에 연결하고, 2번 재귀 호출하여 뒤따라오는 피연산자 둘을 연산자 노드의 양쪽 자식으로 연결한다.
<br>
<br>
만약 처음 읽은 토큰이 피연산자일 경우 해당 토큰을 노드에 입력하고 함수를 반환한다.
```
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
```

### 수식 트리 계산
이 함수는 노드에 담긴 토큰을 연산자인 경우와 피연산자인 경우로 나누어 처리한다.
<br>
토큰이 연산자일 때는 트리의 바닥(잎)부터 계산 결과를 병합하여 올라가도록 재귀 호출 작업을 진행한다.
<br>
<br>
재귀 호출한 함수가 값을 반환하면 왼쪽 수식 트리의 계산 결과는 left 변수에, 오른쪽 수식 트리의 계산 결과는 right 변수에 저장한다.
<br>
<br>
그 이후 연산자의 종류에 따라 계산 작업을 수행한다.
<br>
<br>
토큰이 피연산자인 경우 간단하게 토큰에 담겨 있던 값을 수로 변환해서 사용한다.
```
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
```

### [예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Tree/Expression%20Tree/ExpressionTree.c)

### 실행 결과
```
Preorder Tree
 / + 7 1 - 5 2

Inorder Tree
(((7)+(1))/((5)-(2)))

Postorder Tree
 7 1 + 5 2 - /
Result : 2.666667 
```
