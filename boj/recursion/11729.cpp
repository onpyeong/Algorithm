//* 재귀 - 11729 <하노이 탑 이동 순서> 실버 1
#include <iostream>
using namespace std;

void hanoi(int k, int from, int to) {
    int x = 6 - (from + to);
    if(k == 0){
        return;
    }
    hanoi(k - 1, from, x);
    cout << from << " " << to << "\n";
    hanoi(k - 1, x, to);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = ans * 2 + 1;
    }

    cout << ans << "\n";
    hanoi(n, 1, 3);
    
    return 0;
}
