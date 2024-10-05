#include <iostream>
#include <stack>

using namespace std;

int R, C;
int maxDist = 1;
char board[21][21];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool alpha[27];

void dfs(int x, int y, int dist) {
    alpha[board[x][y] - 'A'] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        if(alpha[board[nx][ny] - 'A'])
            continue;
        dfs(nx, ny, dist + 1);
        maxDist = max(maxDist, dist + 1);
    }
    alpha[board[x][y] - 'A'] = false;
}

int main()
{
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    
    dfs(0, 0, 1);
    cout << maxDist;

    return 0;
}
