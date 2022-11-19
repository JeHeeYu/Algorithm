## Boyer-Moore 알고리즘이란
Boyer-Moore 알고리즘이란 검색하고자 하는 패턴의 마지막 문자부터 앞쪽으로 검사를 진행하면서 일치하지 않는 
<br>
문자가 있으면 미리 준비한 표에 따라 패턴을 옮길 크기를 정하는 고리즘이다.
<br>
<br>
Booyer-Moore 법은 Brute-Froce나 KMP 보다 효율이 더 우수하기 때문에 널리 사용되는 문자열 검색 알고리즘이다.
<br>
R.S Boyer, J.s Moore가 만든 알고리즘으로 그의 이름을 따 만들어졌다.
<br>
<br>
아래 예제는 텍스트 "ABCXDEZCABACABAC"에서 패턴 "ABAC"를 검색하는 예제이다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/202836761-66fa3086-534b-496e-a993-f45bad404de6.JPG" width="500" height="200">
<br>
<br>
먼저 텍스트와 검색할 패턴의 첫 번째 문자를 겹쳐보고 검색할 패턴의 마지막 문자 'C'를 검사한다.
<br>
텍스트의 'X'는 패턴에 없으므로, 이 문자는 패턴에 아예 없는 문자이기 때문에 패턴을 한 칸씩 뒤로 옮겨도 일치하지 않는다.
<br>
<br>
이와 같이 텍스트 안에서 패턴에 들어 있지 않은 문자를 찾으면 해당 위치까지의 문자는 건너 뛸 수 있다.
<br>
<br>
만약 패턴을 옮기는 과정을 생략하면 아래와 같은 상태가 된다.
<br>
이 상태는 패턴의 마지막 문자 'C'와 텍스트의 'C'가 일치하기 때문에 패턴을 1칸 옮길 수 있다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/202837392-bfb24c86-34eb-4ac9-9210-fa1904f63344.JPG" width="500" height="200">
<br>
<br>
패턴의 마지막 문자 'C'는 텍스트와 일치하고 있다. 다시 'C'의 이전 문자 'A'를 검사하면 'Z'와 다른 문자임을 알 수 있다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/202837478-5ac88f3f-813a-4ed5-b383-ffb93121e611.JPG" width="500" height="200">
<br>
<br>
패턴을 1칸, 2칸 옮기더라도 텍스트의 'Z' 문자는 검사할 패턴의 문자열에 존재하지 않는 것을 확인할 수 있다.
<br>
<br>
이러면 또 다시 검색할 패턴을 한꺼번에 3칸 옮겨 다시 검사를 시작한다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/202837533-c16a7ec9-bc54-443a-9f61-ebb065cbf317.JPG" width="500" height="200">
<br>
<br>
이렇게 <b>패턴의 길이를 n이라고 할 때 현재 검사하고 있는 텍스트의 문자 위치로부터 다음에 검사할 패턴의 마지막 문자 위치가 n만큼 떨어질 수 있도록 패턴을 옮기면 된다.</b>
이것이 Boyer-Moore 알고리즘을 적용하여 문자열을 검색하는 방법이다.
<br>
<br>
