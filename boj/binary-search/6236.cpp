#include <iostream>

using namespace std;

int N, M;
int price[100005];

int calcCnt(int p) {
    int t;
    int i = 0;
    int cnt = 0;
    bool flag;
    while(i < N) { //비용 계산
        t = p;
        flag = false;
        while(i < N && t - price[i] >= 0) {
            t -= price[i++];
            flag = true;
        }
        if(flag) {
            cnt++;
        }else {
            return M + 1;
        }
    }
    return cnt;
}

int search() {
    int s = 0, e = 1e9 + 1;
    int m;
    while(s + 1 < e) {
        m = (s + e) / 2;
        if(calcCnt(m) <= M) {
            e = m;
        }else {
            s = m;
        }
    }
    
    return e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> price[i];
    }
    
    cout << search() << "\n";
    
    return 0;
}
