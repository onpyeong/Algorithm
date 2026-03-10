#include <iostream>
#include <stack>

using namespace std;

int N;
int h[80001];
stack<int> st; // 자신보다 높거나 같은 빌딩을 만나지 않은 빌딩의 idx
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> h[i];
    }
    
    for(int i = 0; i < N; i++) {
      while(!st.empty() && h[st.top()] <= h[i]) { // 현재 빌딩보다 작거나 같은 빌딩이 있으면 
        ans += i - st.top() - 1; // 개수를 세고 꺼내줌
        st.pop();
      }
      st.push(i);
    }
    while(!st.empty() && h[st.top()] <= 1e9) {
      ans += N - st.top() - 1;
      st.pop();
    }
    
    cout << ans;
    
    return 0;
}
