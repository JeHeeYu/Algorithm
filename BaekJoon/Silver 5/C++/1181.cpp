#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(string a, string b)
{
  if(a.length() == b.length()) {
      return a < b;
  }
    
  return a.length() < b.length();
}

int main(){
  int N;
  
  vector<string> v;  
  
  cin >> N;
  
  for(int i = 0; i < N; i++) {
    string str;
    cin >> str;
    
    if(find(v.begin(), v.end(), str) == v.end()) {
        v.push_back(str);
    }
  }
  
  sort(v.begin(), v.end(), Compare);

  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }
}
