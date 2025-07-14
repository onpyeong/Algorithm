#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, answer;
priority_queue<pair<int, pair<int, int>>> edges; // 비용, a, b
int p[1003];

int find(int x) {
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void union_parent(int a, int b) {
  a = find(a);
  b = find(b);
  if(a <= b)
    p[b] = a;
  else
    p[a] = b;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
      cin >> a >> b >> c;
      edges.push({-c, {a, b}});
    }
    
    for(int i = 1; i <= N; i++)
      p[i] = i;
    
    while(!edges.empty()) {
      auto edge = edges.top();
      edges.pop();
      if(find(edge.second.first) != find(edge.second.second)) {
        union_parent(edge.second.first, edge.second.second);
        answer -= edge.first;
      }
    }
    
    cout << answer << "\n";
    
    return 0;
}
