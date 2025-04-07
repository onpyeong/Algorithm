#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int map[21][21];
int tmp[21][21];
int totalScore;
bool visit[21][21];
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct BlockInfo {
	int x;
	int y;
	int rainbow;
	int size;
};

vector<BlockInfo> blockGroup;

bool compare(const BlockInfo &a, const BlockInfo &b) {
	if (a.size == b.size) {
		if (a.rainbow == b.rainbow) {
			if (a.x == b.x) {
				return a.y > b.y;
			}
			return a.x > b.x;
		}
		return a.rainbow > b.rainbow;
	}
	return a.size > b.size;
}

void makeBlockGroup(int x, int y) {
	queue<BlockInfo> q;
	vector<pair<int, int>> rainbowPoint;
	BlockInfo b;
	int sx, sy, nx, ny;
	int rainbowCnt = 0, bSize = 0;

	q.push({ x, y, 0, 0});
	visit[x][y] = true;
	sx = x;
	sy = y;
	while (!q.empty()) {
		b = q.front();
		q.pop();
		bSize++;
		for (int i = 0; i < 4; i++) {
			nx = b.x + d[i][0];
			ny = b.y + d[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (visit[nx][ny])
				continue;
			if (map[nx][ny] == 0) {
				q.push({ nx, ny, ++b.rainbow, 0});
				rainbowCnt++;
				visit[nx][ny] = true;
				rainbowPoint.push_back({ nx, ny});
			}
			else if (map[nx][ny] == map[x][y]) {
				q.push({ nx, ny, b.rainbow, 0});
				visit[nx][ny] = true;
				if (sx == nx) {
					sy = min(sy, ny);
				}
				else if (sx > nx) {
					sx = nx;
				}
			}
		}
	}
	int rainbowSize = rainbowPoint.size();
	for (int i = 0; i < rainbowSize; i++) {
		visit[rainbowPoint[i].first][rainbowPoint[i].second] = false;
	}
	blockGroup.push_back({ sx, sy, rainbowCnt, bSize });
}

void removeBlock(int sx, int sy) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> blocks;
	pair<int, int> cur;
	int nx, ny;
	memset(visit, 0, sizeof(visit));

	q.push({ sx, sy});
	visit[sx][sy] = true;
	blocks.push_back({ sx, sy });
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cur.first + d[i][0];
			ny = cur.second + d[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (visit[nx][ny])
				continue;
			if (map[nx][ny] == 0) {
				q.push({ nx, ny});
				visit[nx][ny] = true;
				blocks.push_back({ nx, ny });
			}
			else if (map[nx][ny] == map[sx][sy]) {
				q.push({ nx, ny});
				visit[nx][ny] = true;
				blocks.push_back({ nx, ny });
			}
		}
	}
	int blockSize = blocks.size();
	for (int i = 0; i < blockSize; i++) {
		map[blocks[i].first][blocks[i].second] = -2;
	}
}

int findMaxBlockGroup() {
	blockGroup.clear();
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] >= 1 && map[i][j] <= M && !visit[i][j]) {
				makeBlockGroup(i, j);
			}
		}
	}
	if (!blockGroup.empty()) {
		sort(blockGroup.begin(), blockGroup.end(), compare);
		if (blockGroup[0].size < 2)
			return 0;
		removeBlock(blockGroup[0].x, blockGroup[0].y);
		return blockGroup[0].size * blockGroup[0].size;
	}
	return 0;
}

void gravity() {
	for (int j = 0; j < N; j++) { //n으로 수정
		int i = N - 1;
		while (true) {
			while (i >= 0 && (map[i][j] == -1 || map[i][j] == -2))
				i--;
			//i가 -1이거나 
			if (i == -1)
				break;
			//i가 숫자
			int ei = i + 1;
			while (ei < N && map[ei][j] == -2) {
				ei++;
			}
			//i가 -1이면
			if (ei == i + 1) {
				i--;
				continue;
			}
			map[ei - 1][j] = map[i][j];
			map[i][j] = -2;
				//마지막 위치에 옮김
			i--;
		}

	}
}

void rotate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[N - j - 1][i] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int score = 1;
	while(score != 0) {
		score = findMaxBlockGroup(); //최대 크기 블록 그룹 찾기
		if (score == 0)
			break;
		gravity();
		rotate();
		gravity();
		totalScore += score;
	}

	cout << totalScore << "\n";

	return 0;
}
