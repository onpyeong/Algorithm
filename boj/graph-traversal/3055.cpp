#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[51][51];
int visit[51][51];
queue<pair<pair<int, int>, bool>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int sx, int sy) {
  int x, y, nx, ny;
  bool isWater;
  
  q.push({{sx, sy}, false});
  visit[sx][sy] = 1;
  
  while(!q.empty()) {
    x = q.front().first.first;
    y = q.front().first.second;
    isWater = q.front().second;
    q.pop();
    
    if(map[x][y] == 'D') {
      break;
    }
    
    for(int d = 0; d < 4; d++) {
      nx = x + dx[d];
      ny = y + dy[d];
      if(nx < 0 || nx >= R || ny < 0 || ny >= C)
        continue;
      if(map[nx][ny] == 'X' || map[nx][ny] == '*')
        continue;
      if(!isWater) { //고슴도치이면
        if(visit[nx][ny] != 0)
          continue;
        q.push({{nx, ny}, isWater});
        visit[nx][ny] = visit[x][y] + 1;  
      }else { //물이면
        if(map[nx][ny] == 'D')
          continue;
        map[nx][ny] = '*';
        q.push({{nx, ny}, isWater});
      }
    }
  }
}

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    string row;
    int sx, sy, ex, ey;
    
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
      cin >> row;
      for(int j = 0; j < C; j++) {
        map[i][j] = row[j];
        if(map[i][j] == 'S') {
          sx = i;
          sy = j;
        }else if(map[i][j] == '*') {
          q.push({{i, j}, true});
        }else if(map[i][j] == 'D') {
          ex = i;
          ey = j;
        }
      }
    }
    
    BFS(sx, sy);
    
    if(visit[ex][ey] == 0)
      cout << "KAKTUS\n";
    else
      cout << visit[ex][ey] - 1 << "\n";
    
    return 0;
}
