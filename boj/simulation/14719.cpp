#include <iostream>

using namespace std;

int H, W, total;
int leftH, rightH;
int block[501];

int main()
{
    cin >> H >> W;
    for(int i = 0; i < W; i++) {
        cin >> block[i];
    }
    
    for(int i = 1; i < W - 1; i++) {
        leftH = rightH = block[i];
        for(int l = 0; l < i; l++) leftH = max(leftH, block[l]);
        for(int r = i + 1; r < W; r++) rightH = max(rightH, block[r]);
        total += min(leftH, rightH) - block[i];
    }
    
    cout << total;
    return 0;
}
