#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int K, M;
int map[5][5];
int temp[5][5];
int rtemp[5][5];
bool visit[5][5];
int wallNum[301];
int wallIdx;
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct Point {
	int x;
	int y;
	int r;
	int value;
};

static bool compare(const Point& a, const Point& b) {
	if (a.value == b.value) {
		if (a.r == b.r) {
			if (a.y == b.y)
				return a.x < b.x;
			return a.y < b.y;
		}
		return a.r < b.r;
	}
	return a.value > b.value;
}

void copy(int (*from)[5], int (*to)[5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			to[i][j] = from[i][j];
		}
	}
}

int calcPiece(int sx, int sy) {
	queue<pair<int, int>> q;
	int x, y, nx, ny;
	int piece = 0;

	q.push({ sx, sy });
	visit[sx][sy] = true;
	piece++;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + d[i][0];
			ny = y + d[i][1];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
				continue;
			if (visit[nx][ny])
				continue;
			if (rtemp[nx][ny] == rtemp[x][y]) {
				q.push({ nx, ny });
				visit[nx][ny] = true;
				piece++;
			}
		}
	}
	return piece;
}

int calcValue() {
	int value = 0;
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!visit[i][j]) {
				int piece = calcPiece(i, j);
				if (piece >= 3) {
					value += piece;
				}
			}
		}
	}
	return value;
}

void rotate(int x, int y) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			rtemp[x + j][y - i] = temp[x + i][y + j];
		}
	}
}

void findBestPoint() {
	vector<Point> maxValues;
	int maxValue = -1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			copy(map, temp);
			for (int r = 0; r < 4; r++) {
				if (r == 0) {
					copy(temp, rtemp);
				}
				else {
					rotate(i, j);
				}
				int value = calcValue();
				if (value >= maxValue) {
					maxValue = value;
					maxValues.push_back({ i, j, r, value });
				}
				copy(rtemp, temp);
			}
		}
	}
	sort(maxValues.begin(), maxValues.end(), compare);
	Point* p = &maxValues[0];
	copy(map, temp);
	copy(temp, rtemp);
	for (int r = 1; r <= p->r; r++) {
		rotate(p->x, p->y);
		copy(rtemp, temp);
	}
	copy(temp, map);
}

int calcPiece2(int sx, int sy) { //배열도 포인터로 받아서 가능?
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	int x, y, nx, ny;
	int piece = 0;

	q.push({ sx, sy });
	visit[sx][sy] = true;
	piece++;
	v.push_back({ sx, sy });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + d[i][0];
			ny = y + d[i][1];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
				continue;
			if (visit[nx][ny])
				continue;
			if (map[nx][ny] == map[x][y]) {
				q.push({ nx, ny });
				visit[nx][ny] = true;
				piece++;
				v.push_back({ nx, ny });
			}
		}
	}
	//0으로 만들기
	if (piece >= 3) {
		int vSize = v.size();
		for (int i = 0; i < vSize; i++) {
			map[v[i].first][v[i].second] = 0;
		}
	}
	return piece;
}

int calcValue2() {
	int value = 0;
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!visit[i][j]) {
				int piece = calcPiece2(i, j);
				if (piece >= 3) {
					value += piece;
				}
			}
		}
	}
	return value;
}

void fillNewPiece() {
	for (int j = 0; j < 5; j++) {
		for (int i = 4; i >= 0; i--) {
			if (map[i][j] == 0) {
				map[i][j] = wallNum[wallIdx++];
			}
		}
	}
}


int getRelics() {
	int value = 1, totalValue = 0;
	while (value != 0) {
		value = calcValue2();
		if (value != 0)
			fillNewPiece();
		totalValue += value;
	}
	return totalValue;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> M;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> wallNum[i];
	}

	while (K--) {
		findBestPoint();
		int value = getRelics();
		if (value == 0)
			break;
		cout << value << " ";
	}
	return 0;
}

