#include <iostream>

using namespace std;

int n, answer;
bool paper[101][101];
int r, c;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c >> r;
        for(int x = r; x < r + 10; x++) {
            for(int y = c; y < c + 10; y++) {
                paper[x][y] = true;
            }
        }
    }
    
    for(int x = 0; x < 101; x++) {
        for(int y = 0; y < 101; y++) {
            if(!paper[x][y])
                continue;
            if(!(x > 0 && paper[x - 1][y]))
                answer++;
            if(!(x < 100 && paper[x + 1][y])) 
                answer++;
            if(!(y > 0 && paper[x][y - 1]))
                answer++;
            if(!(y < 100 && paper[x][y + 1]))
                answer++;
        }
    }
    
    cout << answer;
    
    return 0;
}
