/* 정렬 - 17390 <이건 꼭 풀어야 해!> 실버 3*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int N, Q;
    int L, R;

    cin >> N >> Q;

    vector<int> arr(N+1, 0);
    vector<long long> cumSum(N+1, 0); 

    arr[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += arr[i];
        cumSum[i] = sum;
    }

    
    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        cout << cumSum[R] - cumSum[L-1] << "\n";
    }

    return 0;
}