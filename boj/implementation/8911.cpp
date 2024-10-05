#include <iostream>

using namespace std;

int rx[4] = {-1, 0, 1, 0}; //위 오른 아래 왼
int ry[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    string cmd;
    
    cin >> T;
    while(T--) {
        int r = 0;
        int x = 0, y = 0;
        int sx = 0, sy = 0, ex = 0, ey = 0;
        
        cin >> cmd;
        for(char c : cmd) {
            if(c == 'F'){
                x += rx[r];
                y += ry[r];
                sx = min(sx, x);
                sy = min(sy, y);
                ex = max(ex, x);
                ey = max(ey, y);
            }else if(c == 'B') {
                x -= rx[r];
                y -= ry[r];
                sx = min(sx, x);
                sy = min(sy, y);
                ex = max(ex, x);
                ey = max(ey, y);
            }else if(c == 'R') {
                r++;
                if(r == 4)
                    r = 0;
            }else {
                r--;
                if(r == -1)
                    r = 3;
            }
        }
        
        cout << (ex - sx) * (ey - sy) << "\n";
    }

    return 0;
}
