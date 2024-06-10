//* 그리디 - 2212 <센서> 골드 5
#include <iostream>
#include <algorithm>
using namespace std;

int sensor[10001] = {0};

int main() {
    int n, k;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> sensor[i];
    }

    sort(sensor, sensor + n);

    for(int i = 0; i < n - 1; i++) {
        sensor[i] = sensor[i + 1] - sensor[i];
    }

    sort(sensor, sensor + n - 1);

    int sum = 0;
    for(int i = 0; i < n - k; i++) {
        sum += sensor[i];
    }

    cout << sum << "\n";
    return 0;
}
