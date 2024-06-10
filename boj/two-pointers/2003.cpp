#include <iostream>

using namespace std;

int a[10005];

int main() {
    int n, m;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int sum = 0;
    int ed = -1;
    int ans = 0;
    for(int st = 0; st < n; st++) {
        while(sum < m && ed < n - 1) {
            ed++;
            sum += a[ed];
        }
        if(sum == m) {
            ans++;
        }
        sum -= a[st];
    }
    
    cout << ans << "\n";

    return 0;
}
