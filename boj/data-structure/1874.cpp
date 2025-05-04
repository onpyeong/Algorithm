#include <iostream>
#include <stack>

using namespace std;

int N;
int input[100003];
stack<int> s;
string answer;
bool isEnd;
int idx = 1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> input[i];
  }
  
  isEnd = true;
  for(int i = 0; i < N; i++) {
    if(input[i] == idx) {
      answer += "+\n";
      answer += "-\n";
      idx++;
    }else if(input[i] > idx) {
      while(input[i] > idx) {
        answer += "+\n";
        s.push(idx++);
      }
      answer += "+\n";
      answer += "-\n";
      idx++;
    }else {
      if(input[i] != s.top()) {
        isEnd = false;
        break;
      }else {
        answer += "-\n";
        s.pop();
      }
    }
  }
  if(isEnd) {
    cout << answer;
  }else {
    cout << "NO\n";
  }
}
