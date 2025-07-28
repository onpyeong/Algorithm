#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, maxCnt;
string line;
bool adj[51][51];
bool visit[51];

int bfs(int x) {
  queue<pair<int, int>> q; // 번호, 거리
  memset(visit, 0, N);
  int nx, dist, cnt = -1;
  
  q.push({x, 0});
  visit[x] = true;
  while(!q.empty()) {
    nx = q.front().first;
    dist = q.front().second;
    q.pop();
    if(dist == 3) // 거리가 2인 친구만 2-친구
      return cnt;
    cnt++;
    for(int i = 0; i < N; i++) {
      if(adj[nx][i] && !visit[i]) {
        q.push({i, dist + 1});
        visit[i] = true;
      }
    }
  }
  return cnt;
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
      cin >> line;
      for(int j = 0; j < N; j++) {
        adj[i][j] = (line[j] == 'Y')? true : false;
      }
    }

    for(int i = 0; i < N; i++) {
      maxCnt = max(maxCnt, bfs(i));
    }
    
    cout << maxCnt << "\n";
    return 0;
}
