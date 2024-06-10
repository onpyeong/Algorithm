#include <iostream>

using namespace std;

int N, K, M;
int arr_size = 0;
int arr[1000001];

bool check(int mid) {
    long long cnt = 0;
    for(int i = 0; i < arr_size; i++) {
            cnt += arr[i] / mid;
    }
    if(cnt < M) {
        return false;
    }else {
        return true;
    }
}

int main()
{
    cin >> N >> K >> M;
    
    for(int i = 0; i < N; i++) {
        int len;
        cin >> len;
        if(len <= K || len == K + K)
            continue;
        if(len > K + K) {
            len -= K + K;
        }else {
            len -= K;
        }
        arr[arr_size++] = len;
    }
    
    int s = 0, e = 1e9, mid;
    while(s + 1 < e) {
        mid = (s + e) / 2;
        if(check(mid)) {
            s = mid;
        }else {
            e = mid;
        }
    }
    if(s == 0)
        s = -1;
    cout << s;

    return 0;
}
