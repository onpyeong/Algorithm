#include <iostream>
#include <queue>

using namespace std;
int K, W, H, minCnt;
bool map[203][203];
bool visit[31][203][203];
int dHorse[8][2] = {
		{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
		{1, -2}, {2, -1}, {2, 1}, {1, 2}
};
int dAdj[4][2] = {
		{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

struct Point{
  int x;
  int y;
  int horseCnt;
  int moveCnt;
};

bool isInvalid(int x, int y, int horseCnt) {
	return x < 0 || x >= H || y < 0 || y >= W || map[x][y] || visit[horseCnt][x][y];
}

void moveMonkey() {
  queue<Point> q;
  Point p;
  int nx, ny;
  
  q.push({0, 0, 0, 0});
  visit[0][0][0] = true;
  while(!q.empty()) {
    p = q.front();
    q.pop();
    
    if(p.x == H - 1 && p.y == W - 1) {
  		minCnt = min(minCnt, p.moveCnt);
  		continue;
  	}
  	
  	for(int i = 0; i < 4; i++) {
  		nx = p.x + dAdj[i][0];
  		ny = p.y + dAdj[i][1];
  		if(isInvalid(nx, ny, p.horseCnt))
  			continue;
  		q.push({nx, ny, p.horseCnt, p.moveCnt + 1});
  		visit[p.horseCnt][nx][ny] = true;
  	}
  	if(p.horseCnt < K) {
  		for(int i = 0; i < 8; i++) {
  			nx = p.x + dHorse[i][0];
  			ny = p.y + dHorse[i][1];
  			if(isInvalid(nx, ny, p.horseCnt + 1))
  				continue;
  			q.push({nx, ny, p.horseCnt + 1, p.moveCnt + 1});
  		  visit[p.horseCnt + 1][nx][ny] = true;
  		}
  	}
  }
}

int main() {

	cin >> K;
	cin >> W >> H;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	
	minCnt = 1e9;
	moveMonkey();
	cout << (minCnt == 1e9? -1 : minCnt);
	
}
