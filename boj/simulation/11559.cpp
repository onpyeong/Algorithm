#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char board[12][6];
bool visit[12][6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isRemove;

void remove_puyo(int i, int j) { //4개 이상인 뿌요를 터뜨림
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = true;
    int cnt = 0;
    char color = board[i][j];
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
                continue;
            if(visit[nx][ny] || board[nx][ny] != color)
                continue;
            q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
    
    if(cnt >= 4) { //4개 이상 연결된 경우 .으로 바꾸기
        for(int x = 0; x < 12; x++) {
            for(int y = 0; y < 6; y++) {
                if(visit[x][y]) {
                    visit[x][y] = false;
                    board[x][y] = '.';
                }
            }
        }
        isRemove = true;
    }
}

void clear_visit() {
    for(int x = 0; x < 12; x++) {
        for(int y = 0; y < 6; y++) {
            visit[x][y] = false;
        }
    }
}

int main()
{
    int answer = 0;
    
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> board[i][j];
        }
    }
    
    while(true) {
        isRemove = false;
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(board[i][j] != '.') { //알파벳인 경우 터뜨림
                    remove_puyo(i, j);
                    clear_visit();
                }
            }
        }
        if(!isRemove) { //더이상 터뜨릴게 없으면 종료
            break;
        }
        answer++;
        queue<char> q;
        for(int j = 0; j < 6; j++) { //알파벳 밑으로 내리기
            for(int i = 11; i >= 0; i--) {
                if(board[i][j] != '.') {
                    q.push(board[i][j]);
                    board[i][j] = '.';1
                }
            }
            int c = 11;
            while(!q.empty()) {
                board[c--][j] = q.front();
                q.pop();
            }
        }
    }
    
    cout << answer;

    return 0;
}
