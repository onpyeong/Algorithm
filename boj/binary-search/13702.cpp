#include <iostream>
#include <climits>

using namespace std;

int N, K;
long long s, e;
int d[10005];

void f() {
    s = -1, e = INT_MAX;
    while(s + 1 < e) {
        long long m = (s + e) / 2; //막걸리 양
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            cnt += d[i] / m;
        }
        if(cnt >= K) {
            s = m;
        }else {
            e = m;
        }
    }
}

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> d[i];
    }
    
    f();
    
    cout << s;

    return 0;
}
