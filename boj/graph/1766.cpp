#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[32003];
int indeg[32003];

void make_order() {
  priority_queue<int> pq;

  for(int i = 1; i <= N; i++) {
    if(indeg[i] == 0) {
      pq.push(-i);
    }
  }
  
  while(!pq.empty()) {
    int x = -pq.top();
    pq.pop();
    cout << x << " ";
    for(int nx : adj[x]) {
      indeg[nx]--;
      if(indeg[nx] == 0) {
        pq.push(-nx);
      }
    }
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      indeg[b]++;
    }
    
    make_order();
    return 0;
}
