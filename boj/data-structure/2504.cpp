#include <iostream>
#include <stack>

using namespace std;

int t, c, x, answer, input_size;
char open;
string input;
stack<pair<int, char>> s;
int num[35];
bool isCorrect = true;

int main() {
  cin >> input;
  input_size = input.size();
  for(int i = 0; i < input_size; i++) {
    if(input[i] == '(' || input[i] == '[')
      s.push({i, input[i]});
    else {
      if(s.empty()) {
        isCorrect = false;
        break;
      }
      x = (input[i] == ')')? 2 : 3;
      open = (input[i] == ')')? '(' : '[';
      t = s.top().first;
      c = s.top().second;
      if(c == open) {
        s.pop();
        if(i - t == 1) { //바로 나온 것
          num[t] = x; 
        }else { //사이값 계산
          int tmp = 0;
          for(int j = t + 1; j < i; j++) {
            tmp += num[j];
            num[j] = 0;
          }
          num[t] = tmp * x;
        }
      }else {
        isCorrect = false;
        break;
      }
    }
  }
  
  if(s.empty() && isCorrect) {
    for(int i = 0; i < input_size; i++) {
      answer += num[i];
    }
  }
  cout << answer << "\n";
  return 0;
}
