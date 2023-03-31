//* 백트랙킹 - 10971 <외판원 순회 2> 실버 2
#include <iostream>
using namespace std;

int n;
int w[11][11] = {0};
bool isused[11] = {0};
int min_sum = 10000001;

void func(int start, int k, int sum) {
    if(k == n) {
        if(!w[start][1]){
            return;
        }
        sum += w[start][1];
        if(sum <= min_sum) {
            min_sum = sum;
        }
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isused[i] && w[start][i]) {
            isused[i] = 1;
            func(i, k + 1, sum + w[start][i]);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }

    isused[1] = 1;
    func(1, 1, 0);
    
    cout << min_sum << "\n";
   
    return 0;
}
