#include <iostream>
#include <stack>

using namespace std;

int N;
int pre, nxt;
stack<pair<int, int>> st;
int v[1000003];

int main() {
    cin >> N;
    
    cin >> pre;
    for(int i = 1; i < N; i++) {
      cin >> nxt;
      if(pre < nxt) {
        v[i - 1] = nxt;
        while(!st.empty() && st.top().first < nxt) {
          v[st.top().second] = nxt;
          st.pop();
        }
      }else {
        st.push({pre, i - 1});
      }
      pre = nxt;
    }
    while(!st.empty()) {
      v[st.top().second] = -1;
      st.pop();
    }
    
    v[N - 1] = -1;
    for(int i = 0; i < N; i++) {
      cout << v[i] << " ";
    }
    
    return 0;
}
