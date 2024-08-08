#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int map[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

int bfs(int r, int c) {
    int cnt = 0;
    q.push({r, c});
    map[r][c] = 2;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > N || ny < 1 || ny > M)
                continue;
            if(map[nx][ny] != 1)
                continue;
            q.push({nx, ny});
            map[nx][ny] = 2;
        }
    }
    return cnt;
}

int main()
{
    int ans = 0;
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] == 1) {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans;
    return 0;
}
