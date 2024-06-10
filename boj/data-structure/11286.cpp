/*http://boj.kr/b8343775a2df428d8747759b7da51550
#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator() (int a, int b) { //true이면 swap -> sort의 cmp와 반대
    if(abs(a) != abs(b)) return abs(a) > abs(b);
    return a > 0 && b < 0;
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int, vector<int>, cmp> pq;
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    if(x == 0){
      if(pq.empty()) cout << "0\n";
      else{
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else pq.push(x);
  }
}*/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
unordered_map<int, int> m; //절댓값, 음수의 개수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, x;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                cout << 0 << "\n";
                continue;
            }
            int t = pq.top();
            if(m.find(t) != m.end()) {
                m[t] = m[t] - 1;
                if(m[t] == 0) {
                    m.erase(t);
                }
                t = -t;
            }
            cout << t << "\n";
            pq.pop();
        }else {
            if(x < 0) {
                x = -x;
                m[x] = m[x] + 1;
            }
            pq.push(x);
        }
    }

    return 0;
}
