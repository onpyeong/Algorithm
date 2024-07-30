#include <iostream>

using namespace std;

int a[8], b[8];
bool is_used[8];
int N, ans = -1;

void backtracking(int m) {
    if(m == N) {
        int sum = 0;
        for(int i = 1; i < N; i++) {
            sum += abs(b[i] - b[i - 1]);
        }
        ans = max(sum, ans);
        return;
    }
    for(int i = 0; i < N; i++) {
        if(!is_used[i]) {
            b[m] = a[i];
            is_used[i] = true;
            backtracking(m + 1);
            is_used[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    backtracking(0);
    
    cout << ans;
    return 0;
}
