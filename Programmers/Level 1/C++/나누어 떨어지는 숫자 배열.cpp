#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int idx = 0;
    
    for(int i = 0; i < arr.size(); i++)
    {
       if(arr[i] % divisor == 0)
       {
           answer.push_back(arr[i]);
           idx++;
       }
    }
    
    sort(answer.begin(), answer.end());
    
    if(idx == 0)
            answer.push_back(-1);
    
    return answer;
}
