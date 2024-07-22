#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1005][1005];
queue<pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                arr[i][j] = -1;  
            else if(arr[i][j] == 2) {
                arr[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1)
                continue;
            if(arr[nx][ny] != -1)
                continue;
            q.push({nx, ny});
            arr[nx][ny] = arr[x][y] + 1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
