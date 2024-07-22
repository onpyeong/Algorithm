#include <iostream>

using namespace std;

int board[101][101];

int main()
{
    int N, M, answer = 0;
    cin >> N >> M;
    for(int k = 0 ; k < N; k++) {
        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;
        for(int i = s_x; i <= e_x; i++) {
            for(int j = s_y; j <= e_y; j++) {
                board[i][j]++;
            }
        }
    }
    
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(board[i][j] > M)
                answer++;
        }
    }
    cout << answer;
    
    return 0;
}
  
