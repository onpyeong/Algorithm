//* 그리디 - 2217 <로프> 실버 4
#include <iostream>
#include <algorithm>
using namespace std;

int lope[100001] = {0};

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> lope[i];
    }

    sort(lope, lope + n, greater<int>());

    int max = 0;
    for(int i = 0; i < n; i++) {
        int w = lope[i] * (i + 1);
        if(w > max) {
            max = w;
        }
    }

    cout << max << "\n";

    return 0;
}
