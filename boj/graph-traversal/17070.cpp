#include <iostream>
#include <queue>

using namespace std;

int N;
bool map[16][16];
struct Pipe{
  int type;
  int dx;
  int dy;
};
int dsize[3] = {2, 2, 3};
Pipe movePipe[3][3] = {
  {{0, 0, 1}, {2, 1, 1}}, // 가로
  {{1, 1, 0}, {2, 1, 1}}, // 세로
  {{0, 0, 1}, {1, 1, 0}, {2, 1, 1}} // 대각선
};

int calc_cnt() {
  queue<Pipe> q; // type, 끝 좌표
  int type, x, y, ntype, nx ,ny;
  int cnt = 0;
  
  q.push({0, 0, 1});
  while(!q.empty()) {
    type = q.front().type;
    x = q.front().dx;
    y = q.front().dy;
    q.pop();
    if(x == N - 1 && y == N - 1) {
      cnt++;
      continue;
    }
    for(int d = 0; d < dsize[type]; d++) {
      ntype = movePipe[type][d].type;
      nx = x + movePipe[type][d].dx;
      ny = y + movePipe[type][d].dy;
      if(nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;
      if(map[nx][ny])
        continue;
      if(ntype == 2 && (map[x + 1][y] || map[x][y + 1]))
        continue;
      q.push({ntype, nx, ny});
    }
  }
  
  return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        cin >> map[i][j];
      }
    }
    
    cout << calc_cnt();
    
    return 0;
}
