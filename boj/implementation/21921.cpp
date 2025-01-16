#include <iostream>

using namespace std;

int N, X, maxSum, cnt;
int a[250001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N >> X;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int sum = 0;
    for(int i = 0; i < X; i++) {
        sum += a[i];
    }
    maxSum = sum;
    cnt = 1;
    for(int i = X; i < N; i++) {
        sum -= a[i - X];
        sum += a[i];
        if(maxSum < sum) {
            maxSum = sum;
            cnt = 1;
        }else if(maxSum == sum) {
            cnt++;
        }
    }
    if(maxSum == 0)
        cout << "SAD\n";
    else
        cout << maxSum << "\n" << cnt << "\n";
}
