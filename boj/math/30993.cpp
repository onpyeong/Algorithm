#include <iostream>

using namespace std;

long long arr[16];

int main()
{
    int A, B, C, N;
    cin >> N >> A >> B >> C;
    arr[1] = 1;
    for(int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] * i;
    }
    cout << arr[N] / (arr[A] * arr[B] * arr[C]);
    return 0;
}
