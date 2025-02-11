#include <iostream>
#include <queue>

using namespace std;

int T, N, clickCnt;
char map[305][305];
string row;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
pair<int, int> tmp[9];

void init() {
  clickCnt = 0;
}

bool isZero(int x, int y) {
  int nx, ny;
  for(int d = 0; d < 8; d++) {
    nx = x + dx[d];
    ny = y + dy[d];
    if(nx < 0 || nx >= N || ny < 0 || ny >= N)
      continue;
    if(map[nx][ny] == '*')
      return false;
  }
  return true;
}

void clickPos(int sx, int sy) {
  queue<pair<int, int>> q;
  int x, y, nx, ny, pointCnt;
  bool isUseful;
  
  q.push({sx, sy});
  map[sx][sy] = '0';
  while(!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    
    pointCnt = 0;
    for(int d = 0; d < 8; d++) {
      nx = x + dx[d];
      ny = y + dy[d];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;
      if(map[nx][ny] == '.') {
        tmp[pointCnt++] = {nx, ny};
      }
      if(map[nx][ny] == '*') {
        map[x][y] = '1';
        break;
      }
    }
    if(map[x][y] == '0') {
      for(int i = 0; i < pointCnt; i++) {
        q.push({tmp[i].first, tmp[i].second});
        map[tmp[i].first][tmp[i].second] = '0';
      }
    }
  }
}

int main() 
{
    cin >> T;
    for(int t = 1; t <= T; t++) {
      cin >> N;
      init();
      for(int i = 0; i < N; i++) {
        cin >> row;
        for(int j = 0; j < N; j++) {
          map[i][j] = row[j];
        }
      }
      
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          if(map[i][j] == '.' && isZero(i, j)) {
            clickPos(i, j);
            clickCnt++;
          }
        }
      }
      
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          if(map[i][j] == '.') {
            clickCnt++;
          }
        }
      }
      
      cout << "#" << t << " " << clickCnt << "\n";
    }
    return 0;
}
