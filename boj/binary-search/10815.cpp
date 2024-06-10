//Silver 5 <숫자 카드> - 이분탐색 -
#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int n, arr[MAX];

bool binarySearch(int num) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s = 0, e = n - 1;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(arr[mid] < num) {
            s = mid + 1;
        }else if(arr[mid] > num) {
            e = mid - 1;
        }else {
            return 1;
        }
    }
    return 0;
}

int main() {
    int m, num;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> num;
        cout << binarySearch(num) << " ";
    }
    cout << "\n";

    return 0;
};
