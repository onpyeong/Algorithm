//* 백트래킹 - 1174 <줄어드는 수> 골드 5
#include <iostream>
using namespace std;

int n;
int x = 1;
int num[10] = {0};
bool is_stop = 0;

void func(int k, int m, int e) {
    if(k == m) {
        x++;
        if(x == n) {
            is_stop = 1;
        }
        return;
    }
    for(int i = 0; i < e; i++) {
        if(k == 0 && i == 0) continue;
        if(is_stop) break;
        num[k] = i;
        func(k + 1, m, i);
    }
}

int main() {

    cin >> n;

    if(n > 1023) {
        cout << -1 << "\n";
    }else if(n == 1) {
        cout << 0 << "\n";
    }else {
        int k = 0;
        for(k = 1; k <= 9; k++) {
            func(0, k, 10);
            if(is_stop) break;
        }
        for(int i = 0; i < k; i++)
            cout << num[i];
        cout << "\n";
    }
    
    return 0;
}
