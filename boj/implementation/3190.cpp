#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[105][105];
vector<pair<int, char>> v;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> snake;

int main()
{
    int N, K, L, answer = 0;
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }
    cin >> L;
    v.push_back({0, 'X'});
    for(int i = 1; i <= L; i++) {
        int x; char c;
        cin >> x >> c;
        v.push_back({x, c});
    }
    v.push_back({-1, 'X'}); //마지막 직진
    
    int x = 1, y = 1, r = 0;
    snake.push({1, 1});
    board[x][y] = 1;
    bool isEnd = false;
    for(int i = 1; i <= L + 2; i++) {
        int m = ((v[i].first == -1)? N : (v[i].first - v[i - 1].first));
        int c = (v[i].second == 'L')? -1 : 1;
        for(int move = 1; move <= m; move++) {
            answer++;
            int nx = x + dx[r];
            int ny = y + dy[r];
            if(nx <= 0 || ny <= 0 || nx > N || ny > N 
            || board[nx][ny] == 1) {
                isEnd = true;
                break;
            }
            if(board[nx][ny] == 0) { //빈칸이면 이동
                pair<int, int> p = snake.front();
                snake.pop();
                board[p.first][p.second] = 0;
            }
            board[nx][ny] = 1;
            snake.push({nx, ny});
            x = nx;
            y = ny;
        }
        r = (r + c == -1) ? 3 : (r + c) % 4;
        if(isEnd)
            break;
    }
    
    cout << answer;

    return 0;
}
