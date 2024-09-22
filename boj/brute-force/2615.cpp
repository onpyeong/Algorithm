#include <iostream>

using namespace std;

int board[20][20];
int dx[8] = {0, 1, 1, -1, 0, -1, -1, 1};
int dy[8] = {1, 1, 0, 1, -1, -1, 0, -1};

int main()
{
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(board[i][j] == 0)
                continue;
            int cnt;
            int num = board[i][j];
            for(int d = 0; d < 4; d++) {
                cnt = 1;
                int x = i;
                int y = j;
                while(cnt < 6) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
                        break;
                    if(board[nx][ny] == num)
                        cnt++;
                    else
                        break;
                    x = nx;
                    y = ny;
                }
                x = i; y = j;
                while(cnt < 6) {
                    int nx = x + dx[d + 4];
                    int ny = y + dy[d + 4];
                    if(nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
                        break;
                    if(board[nx][ny] == num)
                        cnt++;
                    else
                        break;
                    x = nx;
                    y = ny;
                }
                if(cnt == 5) {
                    cout << num << "\n";
                    cout << x + 1 << " " << y + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    
    cout << "0\n";

    return 0;
}
