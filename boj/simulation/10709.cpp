#include <iostream>

using namespace std;

char sky[101][101];

int main()
{
    int h, w;
    
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> sky[i][j];
        }
    }
    for(int i = 0; i < h; i++) {
        int j = 0;
        while(sky[i][j] == '.') {
            cout << "-1 ";
            j++;
        }
        int cnt;
        while(j < w) {
            if(sky[i][j] == 'c') {
                cnt = 1;
                cout << "0 ";
            }else {
                cout << cnt++ << ' ';
            }
            j++;
        }
        cout << '\n';
    }

    return 0;
}
