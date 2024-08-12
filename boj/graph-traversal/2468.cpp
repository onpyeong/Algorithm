#include <iostream>
#include <queue>

using namespace std;

int N;
int area[101][101];
bool visit[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int i, int j, int h) {
    queue<pair<int, int>> q;
    visit[i][j] = true;
    q.push({i, j});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if(area[nx][ny] <= h || visit[nx][ny])
                continue;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    int max_height = 0, ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> area[i][j];
            max_height = max(max_height, area[i][j]);
        }
    }
    
    for(int h = 0; h < max_height; h++) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(area[i][j] > h && !visit[i][j]) {
                    bfs(i, j, h);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                visit[i][j] = false;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
