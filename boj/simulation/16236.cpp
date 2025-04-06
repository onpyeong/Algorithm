#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int map[21][21];
bool visit[21][21];
int sx, sy;
int eatenFishCnt; //상어가 먹은 물고기 수
int sharkSize = 2; //상어 크기
int t; //시간

int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Fish{
  int x;
  int y;
  int dist;
};

bool compare(const Fish &a, const Fish &b) {
  if(a.dist == b.dist) {
    if(a.x == b.x) {
      return a.y < b.y;
    }
    return a.x < b.x;
  }
  return a.dist < b.dist;
}

bool calcDist() {
  queue<Fish> q;
  vector<Fish> f;
  memset(visit, 0, sizeof(visit));
  int x, y, nx, ny, dist;
  
  q.push({sx, sy, 0});
  visit[sx][sy] = true;
  while(!q.empty()) {
    x = q.front().x;
    y = q.front().y;
    dist = q.front().dist;
    q.pop();
    if(map[x][y] >= 1 && map[x][y] < sharkSize) {
      f.push_back({x, y, dist}); 
    }
    for(int i = 0; i < 4; i++) {
      nx = x + d[i][0];
      ny = y + d[i][1];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;
      if(visit[nx][ny] || map[nx][ny] > sharkSize)
        continue;
      q.push({nx, ny, dist + 1});
      visit[nx][ny] = true;
    }
  }

  if(f.empty()) { //더 이상 먹을 수 있는 물고기가 없으면
    return false;
  }
  sort(f.begin(), f.end(), compare);
  
  Fish * eFish = &f[0]; //우선 순위가 가장 높은 물고기
  map[eFish->x][eFish->y] = 9;
  map[sx][sy] = 0;
  sx = eFish->x;
  sy = eFish->y;
  eatenFishCnt++;
  if(eatenFishCnt == sharkSize) {
    eatenFishCnt = 0;
    sharkSize++;
  }
  t += eFish->dist;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> map[i][j];
      if(map[i][j] == 9) {
        sx = i;
        sy = j;
      }
    }
  }
  
  while(calcDist()) {}
  
  cout << t << "\n";
  return 0;
}
