//Silver 2 <나무 자르기> - 이분탐색 -
#include <iostream>
#define MAX 1000001
using namespace std;

int arr[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, h = 0; //* h 초기값 = 0 설정해야 함
    int max = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(max < arr[i])
            max = arr[i];
    }

    int s = 0;
    int e = max;
    while(s <= e) {
        int mid = (s + e) / 2;
        long long sum = 0; //* sum type 체크!
        for(int i = 0; i < n; i++) {
            if(arr[i] > mid)
                sum += (arr[i] - mid);
        }
        if(m <= sum) {
            s = mid + 1;
            h = mid;
        }else if(m > sum) { 
            e = mid - 1;
        }
    }
    cout << h << "\n";
    return 0;
}
