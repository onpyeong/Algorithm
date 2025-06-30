#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x, y;
int p1, p2;
vector<int> adj[101];
int dist[101];

int bfs() {
  queue<int> q;
  int cur;
  
  q.push(p1);
  dist[p1] = 1;
  while(!q.empty()) {
    cur = q.front();
    q.pop();
    
    if(cur == p2) {
      break;
    }
    
    for(int nxt : adj[cur]) {
      if(dist[nxt] == 0) {
        q.push(nxt);
        dist[nxt] = dist[cur] + 1;
      }
    }
  }
  return dist[p2] - 1;
}

int main() {
    cin >> n;
    cin >> p1 >> p2;
    cin >> m;
    for(int i = 0; i < m; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    
    cout << bfs();
    return 0;
}
