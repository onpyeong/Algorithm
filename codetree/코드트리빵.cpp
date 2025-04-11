#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define BASECAMP 1

using namespace std;

int N, M;
int map[16][16];
int dist[16][16];
int d[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} }; //상 좌 우 하
bool visit[16][16];
vector<pair<int, int>> basecamp;
int store[32][2];
int people[32][2];
bool isEnd[32];
int endCnt = 0; //도착한 사람순

struct Basecamp {
	int dist;
	int x;
	int y;
};

bool compare(const Basecamp &a, const Basecamp &b) {
	if (a.dist == b.dist) {
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	return a.dist < b.dist;
}


void moveMinDist(int p, int sx, int sy, bool goToBasecamp) {
	queue<pair<int, int>> q;
	memset(dist, 0, sizeof(dist));
	int x, y, nx, ny, ex = -1, ey = -1;

	if (!goToBasecamp) { //편의점에서 출발해서 -> 사람까지의 최단거리
		ex = people[p][0];
		ey = people[p][1];
		if (map[ex][ey] == BASECAMP) { //사람이 베이스캠프에 있을 경우 여기 도착해야하니까 visit 잠깐 false
			visit[ex][ey] = false;
		}
	}

	q.push({ sx, sy });
	dist[sx][sy] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == ex && y == ey) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			nx = x + d[i][0];
			ny = y + d[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (dist[nx][ny] > 0 || visit[nx][ny])
				continue;
			q.push({ nx, ny });
			dist[nx][ny] = dist[x][y] + 1;
		}
	}

	if (!goToBasecamp) { //편의점에서 출발해서 -> 사람까지의 최단거리
		if (map[ex][ey] == BASECAMP) { //원복
			visit[ex][ey] = true;
		}

		pair<int, int> temp[4]; //거리, 방향
		int idx = 0;
		for (int i = 0; i < 4; i++) { //사람 기준 4방향에서 가장 짧은 거리의 이동방향을 선택
			nx = ex + d[i][0];
			ny = ey + d[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || dist[nx][ny] == 0) {
				temp[idx++] = { 1000, i };
				continue;
			}
			temp[idx++] = { dist[nx][ny], i };
		}

		sort(temp, temp + 4);
		people[p][0] += d[temp[0].second][0];
		people[p][1] += d[temp[0].second][1];
	}
	else { //편의점에서 출발해서 -> 베이스 캠프까지의 거리
		vector<Basecamp> temp;
		for (int i = 0; i < basecamp.size(); i++) {
			x = basecamp[i].first;
			y = basecamp[i].second;
			temp.push_back({ dist[x][y] == 0 ? 1000 : dist[x][y] , x, y });
		}

		sort(temp.begin(), temp.end(), compare);

		people[p][0] = temp[0].x;
		people[p][1] = temp[0].y;
		visit[temp[0].x][temp[0].y] = true; //베이스 캠프 방문
	}
}

void movePeople(int maxP) {
	for (int i = 1; i <= maxP; i++) { //격자 위 사람에 대해서
		if (!isEnd[i]) {
			moveMinDist(i, store[i][0], store[i][1], false);
		}
	}
}

int simulation() {
	int t = 1;
	while (endCnt < M) {
		movePeople(min(t - 1, M)); //격자 위 모든 사람이 1칸 씩 이동
		for (int i = 1; i <= min(t - 1, M); i++) { //누군가 편의점에 도착한다면 
			if (!isEnd[i] &&
				people[i][0] == store[i][0] && people[i][1] == store[i][1]) {
				visit[store[i][0]][store[i][1]] = true;
				isEnd[i] = true;
				endCnt++;
			}
		}
		if (t <= M) {
			//t번 사람이 편의점과 가장 가까운 베이스 캠프로 이동
			moveMinDist(t, store[t][0], store[t][1], true);
		}
		t++;
	}
	return t - 1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == BASECAMP) {
				basecamp.push_back({ i, j });
			}            
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> store[i][0] >> store[i][1];
		store[i][0]--;
		store[i][1]--;
	}

	cout << simulation();
	
	return 0;
}
