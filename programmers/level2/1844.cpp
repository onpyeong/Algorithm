#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(vector<vector<int> > &maps, int n, int m) {
    queue<pair<int, int> > q;
    q.push({0, 0});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(maps[nx][ny] == 1) {
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx, ny});
            }
        }
        
    }
    
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    bfs(maps, n, m);
    
    if(maps[n - 1][m - 1] == 1)
        answer = -1;
    else
        answer = maps[n - 1][m - 1];
    
    return answer;
}
