#include <iostream>

using namespace std;

int N, d, k, c;
int p[30001];
bool kind[3001];

int main()
{
    int ans = 0, max_kind = 0;
    cin >> N >> d >> k >> c;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        max_kind = max(max_kind, p[i]);
    }
    
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        bool isDouble = false;
        for(int j = 0; j < k; j++) {
            int idx = (i + j) % N;
            kind[p[idx]] = true;
            if(p[idx] == c)
                isDouble = true;
        }
        for(int i = 1; i <= max_kind; i++) {
            if(kind[i]) {
                cnt++;
                kind[i] = false;
            }
        }
        if(!isDouble)
            cnt++;
        ans = max(ans, cnt);
    }
    cout << ans;

    return 0;
}
