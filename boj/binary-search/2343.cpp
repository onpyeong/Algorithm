#include <iostream>

using namespace std;

int s, e;
int N, M;
int arr[100001];

void f() {
    s = 0, e = 1e9 + 1;
    while(s + 1 < e) {
        int m = (s + e) / 2; // 블루레이 크기
        int check = false;
        int cnt = 0;
        for(int i = 0; i < N;) {
            int sum = arr[i];
            if(sum > m) {
                check = true;
                break;
            }
            if(i == N - 1) {
                cnt++;
                break;
            }
            while(sum <= m) {
                if(i == N) break;
                sum += arr[++i];
            }
            cnt++;
        }
        if(check || cnt > M) {
            s = m;
        }else {
            e = m;
        }
    }
}

int main()
{  
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    f();
    cout << e;

    return 0;
}
