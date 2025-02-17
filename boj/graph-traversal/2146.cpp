#include <iostream>
#include <queue>

using namespace std;

int N, minTime = 1e9;
int map[105][105];
bool visit[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int> > border;

void findIslandBorder(int sx, int sy) { //경계 찾기
  queue<pair<int, int> > q;
  int x, y, nx, ny, isBorder;
  
  q.push({sx, sy});
  visit[sx][sy] = true;
  while(!q.empty()) {
    isBorder = false;
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for(int d = 0; d < 4; d++) {
      nx = x + dx[d];
      ny = y + dy[d];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;
      if(visit[nx][ny]) {
        continue;
      }
      if(map[nx][ny] == 1) { //섬이면 계속 탐색
        q.push({nx, ny});
        visit[nx][ny] = true;
      }else { //물을 만나면
        isBorder = true; //경계임
        continue;
      }
    }
    if(isBorder) { //경계이므로 border에 넣기
      border.push({x, y});
      visit[x][y] = true;
    }
  }
}

void calcMinBridge() {
  int x, y, nx, ny;
  
  while(!border.empty()) {
    x = border.front().first;
    y = border.front().second;
    border.pop();
    for(int d = 0; d < 4; d++) {
      nx = x + dx[d];
      ny = y + dy[d];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;
      if(visit[nx][ny]) {
        continue;
      }
      if(map[nx][ny] == 0) { //물을 만나면 거리 증가
        border.push({nx, ny});
        visit[nx][ny] = true;
        map[nx][ny] = map[x][y] + 1;
      }else if(map[nx][ny] == 1) { //다른 섬을 만나면
        minTime = min(minTime, map[x][y]); //섬까지의 거리값 갱신
      }
    }
  }
}

void initMap() {
  for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(map[i][j] != 1) { //거리 계산한 칸인 경우
			  map[i][j] = 0; //물로 만든다!
			  visit[i][j] = false;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(!visit[i][j] && map[i][j] == 1) { //새로운 섬을 만나면
			  findIslandBorder(i, j); //경계 추출
			  calcMinBridge(); //각 섬까지의 최단 거리 세기
			  initMap(); //visit, 물 초기화
			}
		}
	}
	
	cout << minTime - 1 << "\n";

	return 0;
}
