#include <iostream>
#include <cmath>

using namespace std;

int a[100001];

int main(){
    int n, s;
    
    cin >> n >> s;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = 1000001;
    int ed = 0;
    int sum = a[0];
    for(int st = 0; st < n; st++) {
        while(ed < n && sum < s) { //부분합이 작으면 계속 더함
            ed++;
            if(ed == n) {
                break;
            }
            sum += a[ed];
        }
        if(sum >= s) {
            ans = min(ans, ed - st + 1);
        }
        sum -= a[st];
    }
    
    if(ans == 1000001) {
        ans = 0;
    }
    
    cout << ans;
    return 0;
}
