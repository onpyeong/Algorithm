#include <iostream>
#include <string>
#include <queue>
#define INF 1e9

using namespace std;

int T, N;
int map[105][105];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
string row;
int minTime[105][105];

void calcMinTime() {
	//최소 가중치를 계산하시오. 
	priority_queue<pair<int, pair<int, int> > > pq; //복구시간, 좌표
	int dist, x, y, nx, ny;

	pq.push({ 0, {0, 0} }); //가장 큰 가중치로 줘야 앞으로 옴 !
	minTime[0][0] = 0;
	while (!pq.empty()) {
		dist = -pq.top().first;
		x = pq.top().second.first;
		y = pq.top().second.second;
		pq.pop();
		if (minTime[x][y] < dist)
			continue;
		for (int d = 0; d < 4; d++) { //연결된 노드
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			int realTime = dist + map[nx][ny]; 
			if (minTime[nx][ny] > realTime) {
				minTime[nx][ny] = realTime;
				pq.push({ -realTime, {nx, ny} });
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> row;
			for (int j = 0; j < N; j++) {
				map[i][j] = row[j] - '0';
			}
		}

		for (int i = 0; i < N; i++) {
			fill(minTime[i], minTime[i] + N, INF);
		}

		calcMinTime();
		cout << "#" << t << " " << minTime[N - 1][N - 1] << "\n"; 
	}
	
	return 0;
}
