#include <iostream>
#include <queue>

using namespace std;

int M, N, H, ans;
int box[101][101][101];
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
int dh[6] = {-1, 1, 0, 0, 0, 0};

struct Tomato{
    int h;
    int x;
    int y;
};

queue<Tomato> q;

void bfs() {
    while(!q.empty()) {
        Tomato t = q.front();
        int h = t.h, x = t.x, y = t.y;
        q.pop();
        for(int i = 0; i < 6; i++) {
            int nh = h + dh[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nh < 0 || nh > H - 1 || nx < 0 || nx > N - 1 ||
            ny < 0 || ny > M - 1)
                continue;
            if(box[nh][nx][ny] != 0)
                continue;
            box[nh][nx][ny] = box[h][x][y] + 1;
            ans = box[nh][nx][ny];
            q.push({nh, nx, ny});
        }
    }
}

int main()
{
    int zero_cnt = 0;
    cin >> M >> N >> H;
    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> box[h][i][j];
                if(box[h][i][j] == 1) {
                    q.push({h, i, j});
                }
                if(box[h][i][j] == 0)
                    zero_cnt++;
            }
        }
    }
    if(zero_cnt > 0) {
        bfs();
        for(int h = 0; h < H; h++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++) {
                    if(box[h][i][j] == 0) {
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
        cout << ans - 1;
    }else {
        cout << 0; 
    }
    return 0;
}
