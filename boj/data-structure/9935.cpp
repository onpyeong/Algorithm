#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<char> st, buf;
string s, bs, answer;
char c;

int main() {
    cin >> s >> bs;
    
    for(int i = 0; i < s.size(); i++) {
      c = s[i];
      if(c == bs[bs.size() - 1]) { //마지막 글자랑 같으면
        for(int j = bs.size() - 2; j >= 0; j--) {
          if(!st.empty() && st.top() == bs[j]) {
            st.pop(); 
            buf.push(bs[j]); //버퍼에 임시 저장
          }else {
            while(!buf.empty()) { //다시 스택에 넣어줌
              st.push(buf.top());
              buf.pop();
            }
            st.push(c);
            break;
          }
        }
        while(!buf.empty()) {
          buf.pop();
        } //버퍼 비우기
      }else {
        st.push(c);
      }
    }
    
    if(st.empty()) {
      cout << "FRULA\n";
    }else {
      while(!st.empty()) {
        answer += st.top();
        st.pop();
      }
      reverse(answer.begin(), answer.end());
      cout << answer << "\n";
    }
    return 0;
}
