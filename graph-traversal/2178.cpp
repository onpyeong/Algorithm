//* 그래프 탐색 - 2178 <미로 탐색> 실버 1
#include <iostream>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;

int arr[101][101] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c;
    queue <pair<int, int> > q;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < c; j++) {
            arr[i][j] = row[j] - '0';
        }
    }

    q.push(make_pair(0, 0));

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx > r - 1 || ny < 0 || ny > c - 1) 
                continue;
            if(arr[nx][ny] == 0) 
                continue;
            if(arr[nx][ny] == 1){
                arr[nx][ny] = arr[cur.X][cur.Y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    cout << arr[r-1][c-1] << "\n";
    return 0;
}
