//* 백트랙킹 - 15651 <N과 M (3)> 실버 3
#include <iostream>
using namespace std;

int n, m;
int num[8] = {0};
void func(int k) {
    if(k == m) {
        cout << num[0];
        for(int i = 1; i < m; i++)
            cout << " " << num[i];
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        num[k] = i;
        func(k + 1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
    return 0;
}
