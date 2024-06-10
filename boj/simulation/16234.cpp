//* 시뮬레이션 - 16234 <인구 이동> 골드 5
#include <iostream>
#include <queue>
using namespace std;

int n, L, R;
int arr[51][51] = {0};
pair<int, int> small_group[2501];
queue <pair<int, int> > q;
int group[51][51] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int num) {
    int sum = 0;
    int cnt = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        group[x][y] = num;
        sum += arr[x][y];
        small_group[cnt] = make_pair(x, y);
        cnt++;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(group[nx][ny]) continue;
            int diff = arr[x][y] - arr[nx][ny];
            if(diff < 0) diff = -diff;
            if(diff < L || diff > R) continue;
            group[nx][ny] = num;
            q.push(make_pair(nx, ny));
        }
    }

    int people = sum / cnt;
    for(int i = 0; i < cnt; i++) {
        int x = small_group[i].first;
        int y = small_group[i].second;
        arr[x][y] = people;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> L >> R;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int num = 0;
    int ans = 0;
    int max_group = n * n;
    while(true){
        num = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!group[i][j]) { //방문 안했으면
                    q.push(make_pair(i, j));
                    bfs(++num);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                group[i][j] = 0;
            }
        }

        if(num != max_group) {
            ans++;
        }
        if(num == max_group) {
            cout << ans << "\n";
            break;
        }
        if(num == 1) {
            cout << ans << "\n";
            break;
        }
    }
    
    return 0;
}
