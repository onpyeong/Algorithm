#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a[100001];
int ans = 0x7fffffff;

int main(){
    int n, m;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    int st = 0, en = 0;
    while(st < n && en < n) {
        if(a[en] - a[st] < m) {
            en++;
        }else {
            ans = min(ans, a[en] - a[st]);
            st++;
        }
    }
    
    cout << ans;
    return 0;
}
