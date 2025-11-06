#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long> pq;
int N;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> x;
      if(x != 0) {
        pq.push(x);
      }else if(!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
      }else {
        cout << "0\n";
      }
    }
    return 0;
}
