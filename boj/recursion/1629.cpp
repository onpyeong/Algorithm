//* 재귀 - 1629 <곱셈> 실버 1
#include <iostream>
using namespace std;

int c;
long long func(int a, int b) {
    if(b == 1) return a % c;
    long long val = func(a, b/2);
    val = (val * val) % c;
    if(b%2){
        return val * a % c;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;

    cin >> a >> b >> c;

    cout << func(a, b) << "\n";
    return 0;
}
