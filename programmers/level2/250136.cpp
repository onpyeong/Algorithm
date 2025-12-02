#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

int n, m;
vector<vector<int>> land_cp;
int land_cnt = 1;
int map[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int land_size[125001];

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    int x, y, nx, ny;
    int cnt = 0;
    
    q.push({i, j});
    map[i][j] = land_cnt;
    cnt++;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d++) {
            nx = x + dx[d];
            ny = y + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(map[nx][ny] != 0 || land_cp[nx][ny] == 0)
               continue;
            q.push({nx, ny});
            map[nx][ny] = land_cnt;
            cnt++;
        }
    }
    land_size[land_cnt] = cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    land_cp = land;   
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(land[i][j] == 1 && map[i][j] == 0) {
                bfs(i, j);
                land_cnt++;
            }
        }
    }
    
    int max_cnt = 0;
    int col_cnt;
    unordered_set<int> us;
    for(int i = 0; i < m; i++) {
        col_cnt = 0;
        for(int j = 0; j < n; j++) {
            if(land[j][i] == 1 && us.find(map[j][i]) == us.end()) {
                col_cnt += land_size[map[j][i]];
                us.insert(map[j][i]);
            }
        }
        max_cnt = max(max_cnt, col_cnt);
        us.clear();
    }
    
    return answer = max_cnt;
}
