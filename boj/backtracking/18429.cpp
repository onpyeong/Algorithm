#include <iostream>
using namespace std;

int W = 500;
int N, K;
int a[10];
bool used[10];
int cnt;

void backtracking(int k, int w) {
    if(w < W) {
        return;
    }
    if(k == N) {
        cnt++;
        return;
    }
    for(int i = 0; i < N; i++) {
        if(!used[i]) {
            used[i] = true;
            backtracking(k + 1, w + a[i]);
            used[i] = false;
        }
    }
}

int main() {
    cin >> N >> K;
    
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] -= K;
    }
    
    backtracking(0, W);
    
    cout << cnt;

    return 0;
}
