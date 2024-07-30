#include <iostream>

using namespace std;

int N, M;
int arr[9];

void backtracking(int s, int k) {
    if(k == M) {
        for(int i = 0; i < k; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = s; i <= N; i++) {
        arr[k] = i;
        backtracking(i, k + 1);
    }
}

int main()
{
    cin >> N >> M;
    backtracking(1, 0);
    return 0;
}
