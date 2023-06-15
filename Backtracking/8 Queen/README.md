# 8개의 퀸 문제

## 8퀸(Queen) 문제
퀸은 다음 그림과 같이 여덟 방향으로 움직이면서 공격할 수 있고 이동 범위도 체스판 전체에 이른다.
<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/5649d292-0cf6-4656-94cd-a94efc43e594)

<br>

체스 선수 막스 베젤(Max Bezzel)은 이러한 퀸의 속성을 이용하여 1848년에 퍼즐을 하나 만들었다.
<br>
문제는 퀸 8개를 8 * 8 크기의 체스판 안에서 서로 공격할 수 없도록 배치하는 모든 경우를 구하는 문제이다.
<br>
<br>
예를 들어 첫 번째 퀸을 [3, 4] 위치에 놓으면 [5, 6]에는 두 번째 퀸을 놓을 수 없다.
<br>
두 번째 퀸의 위치가 첫 번째 퀸의 공격 범위 안에 들어가기 때문이다.
<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/3383b9e6-1fc7-4e91-a346-8e4447a724c7)

<br>

하지만 다음 그림처럼 두 퀸이 [3, 4]와 [5, 5]에 놓여 있으면 서로를 공격할 수 없다.
<br>
수평, 수직, 대각선 어느 방향에서도 서로를 만날 수 없기 때문이다.
<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/7852ca92-9ecf-44b5-9f9b-248416188cff)

<br>

이런 식으로 8개의 퀸이 서로를 공격할 수 없도록 배치하는 모든 방안을 찾아야 하는데, 후보해와 해의 수가 약간 많은 것이 문제이다.
<br>
체스판의 칸이 모두 64개이고 그 중에서 8개를 골라 퀸을 배치할 수 있으므로 후보해의 수는 총 44억개가 조금 넘는다.
<br>
<br>
이 중에서 실제 해는 92개 뿐이다.
<br>
<br>
말하자면 8개의 퀸 문제는 44억 개 이상의 후보해 속에서 실제 해 92개를 모두 찾아내라고 요구하는 문제이다.
<br>
<br>
8개의 퀸 문제는 8 * 8 크기의 체스판을 염두에 두고 제안됐지만 다른 크기의 체스판으로 문제를 축소 및 확장할 수 있다.
<br>
4 * 4 이상의 크기라면 이 문제를 적용할 수 있기 때문에 8개의 퀸 문제를 N개의 퀸 문제라 부르기도 한다.

<br>

## 8개의 퀸이 만드는 해공간과 백트래킹
8개의 퀸 문제의 해공간을 어떻게 구하는지 이해를 돕기 위해 8 * 8 크기 대신 4 * 4 크기의 체스판이 있다고 가정한다.
<br>
<br>
우선 첫 번째 퀸을 놓을 수 있는 위치는 다음과 같이 [1, 1], [1, 2], [1, 3], [1, 4] 네 가지이다.
<br>
이 네 가지 중 첫 번째 말의 위치는 최종해의 부분 후보해이며, 하나씩 시도해서 해가 될 조건을 만족하는지 확인해야 한다.
<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/0db1fc54-f912-4dab-bec0-4b0663cda0ab)

<br>

먼저 [1, 1] 부분부터 보면 [1, 1]과 [2, 1]은 서로를 수직 방향으로 위협하고 [1, 1]과 [2, 2]는 대각선 방향으로 공격이 가능하다.
<br>
[1, 1]에 대해 [2, 3]과 [2, 4]는 공격이 불가능하므로 일단 부분해로 수용한다.
<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/a4fb88f7-5693-45d1-8652-a521e8b8ba01)

<br>

하지만 [2, 3]은 수용할 수 있는 세 번째 부분해가 없고 [2, 4]는 유일하게 수용 가능한 [3, 2]마저도 수용 가능한 네 번째 부분해가 없으므로 폐기해야 한다.
<br>
<br>
결국 [1, 1] 부분해도 폐기하고 첫 번째 부분해 선택으로 백트래킹 해야한다.
<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/75732dda-d8cd-41ee-80e8-34fdf7aceab0)

<br>
다시 처음으로 돌아와서 [1, 2]를 첫 번째 부분해로 선택한다.
<br>
[1, 2]에 이은 두 번째 부분해 중 [2, 1], [2, 2], [2, 3]은 모두 [1, 2]를 위협하는 위치이기 때문에 버려야 한다.
<br>
<br>
[2, 4]만이 [1, 2]를 위협하지 않으므로 이를 두 번째 부분해로 채택한다.
<br>
[2, 4]에 이은 부분해를 보면 [3, 1]을 제외한 나머지가 모두 [1, 2]나 [2, 4]를 위협하는 위치이므로 [3, 1]을 세 번째 부분해로 채택한다.
<br>
[3, 1]의 후보해 네 개 중 [4, 3]을 빼고 모두 수용할 수 없는 위치들이다.
<br>
<br>
따라서 [4, 3]을 네 번째 부분해로 채택한다.
<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/6f060218-22f1-4c1b-b69e-a43850e8e624)

<br>

이렇게 해서 [1, 2] - [2, 4] - [3, 1] - [4, 3] 으로 이어지는 첫 번째 해를 얻었다.
<br>
4개의 퀸 문제에서 후보해의 수는 총 1820개이다.
<br>
해공간의 절반을 탐색했으니 원래는 910개의 후보해를 시도했어야 하지만 백트래킹을 이용하여 불필요한 후보해 검사량을 크게 줄일 수 있었다.

<br>

## N개의 퀸 문제 풀이 알고리즘 구현
8개의 퀸 문제는 N개의 퀸 문제로 일반화할 수 있으므로 N개의 퀸 문제를 만든다.

<br>

### 자료구조 정의
언뜻 보면 먼저 해를 담을 자료구조로 체스판과 같은 N^2 크기의 배열이 필요하다.
<br>
하지만 N개의 퀸 문제에서 N^2 크기의 자료구조를 사용하기에는 너무 비효율적이다.
<br>
N개의 퀸 문제의 해를 담는 데에는 그냥 N개의 배열 하나면 충분하다.
<br>
<br>
다음과 같은 N개의 배열에서 각 요소의 인덱스 행 번호, 각 요소에 담긴 값은 열 번호로 사용하면 된다.

```
int columns[8];

columns[0] = 0; // 0행 열
columns[1] = 4; // 1행 4열
columns[2] = 7; // 2행 7열
columns[3] = 5; // 3행 5열
columns[4] = 2; // 4행 2열
columns[5] = 6; // 5행 6열
columns[6] = 1; // 6행 1열
columns[7] = 3; // 7행 3열
```

### 알고리즘 구현
N개의 퀸의 해를 찾는 함수는 FindSolutionForQueen() 이라고 이름 짓는다.
<br>
이 함수도 재귀 호출을 이용하여 백트래킹을 처리한다.
<br>
<br>
이 함수의 매개변수는 다음과 같다.
- columns : 부분해
- row : 새 퀸이 놓인 행 번호
- numberOfQueens : 체스판의 크기
- solutionCount : 해의 개수

이 함수가 가장 먼저 할 일은 새로 놓은 퀸이 기존의 퀸들에게 위협받는지 알아내는 것이다.
<br>
이 함수가 호출할 IsThreatened() 함수는 부분해를 담고 있는 columns 배열과 새로 놓은 퀸이 행 번호를 매개 변수로 받아 위험 여부를 판단한다.
<br>
만약 새로 놓은 퀸이 기존의 퀸들을 위협한다면 함수를 반환하여 백트래킹한다.
<br>
즉, 그 이전 붑ㄴ해로 돌아가서 다음 후보를 시도하는 것이다.
<br>
<br>
일단 IsThreatened() 함수를 통과했다면 이는 새로 놓은 퀸을 부분해로 인정한다는 의미이다.
<br>
IsThreatened() 함수를 통과한 부분해가 마지막 부분해라면 (row == numberOfQueens - 1) 이는 하나의 해가 완성되었다는 뜻이므로 해를 출력한다.
<br>
<br>
아직 해를 더 찾아야 한다면 다시 FindSolutionForQueen() 함수를 재귀 호출한다.

```
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
```

그 후 IsThreatened() 함수를 보면 이 함수는 새로 놓은 퀸이 먼저 놓인 퀸들과 위협 관계인지 판단하는 역할을 한다.
- 수직 방향 위험 알아내기 : 이전 단계에서 놓은 퀸들이 위치한 열 중 새로 놓은 퀸 위치의 열과 같은 것이 있는지 확인하고, 있다면 새로 놓인 퀸은 다른 퀸을 수직으로 위협
- 수평 방향 위협 알아내기 : 이전 단계에서 놓은 퀸들이 위치한 행 중 새로 놓은 퀸이 위치한 행과 같은 것이 있는지 확인하고, 있다면 새로 놓인 퀸은 다른 퀸을 수평으로 위협
- 대각선 방향 위협 알아내기 : 두 퀸의 위치가 다음 등식을 만족하면 두 퀸은 대각선으로 상호 위협함

```
|행1-행2|=|열1-열2|
```

예를 들어 다음과 같이 퀸[3, 4]와 퀸[6, 7]은 |3-6|=3=|4-7|을 만족하므로 서로를 대각선 방향으로 위협한다.
<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/7c835541-9449-4c67-b6fa-915cd5b786fe)

<br>

다음 코드는 앞의 내용을 구현한 IsThreatened() 함수로 2개의 매개 변수가 존재한다.
- columns : 부분해
- newRow : 새로운 퀸이 놓인 행의 번호

이 두 매개 변수로부터 새 퀸의 열 번호를 얻을 수 있다.
<br>
columns[newRow] 에는 새 퀸이 놓인 열 번호가 들어 있다.
<br>
<br>
이 함수는 columns 배열을 순차적으로, 즉 0번 행부터 새 퀸이 놓인 행의 앞 행까지 돌면서 새 퀸의 위험 여부를 판단한다.
<br>
여기서 위협 여부를 판단하는 if 블록에 수평 방향 위협을 판단하는 부분이 없다.
<br>
그 이유는 IsThreatened() 함수를 호출하는 FindSolutionForQueen() 함수 자체가 새로운 행을 매개 변수로 입력 받아 실행되기 때문이다.
<br>
<br>
그러므로 수평 위협은 고려 대상에서 제외된다.

```
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
```

<br>

## N개의 퀸 문제 풀이 예제 프로그램

### [예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Backtracking/8%20Queen/NQueen.c)
