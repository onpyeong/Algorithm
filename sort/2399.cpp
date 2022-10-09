//* 정렬 - 2399 <거리의 합> 브론즈 2
#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int main()
{
    int n;
    int arr[MAX] = {};

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    long long distance = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            distance += (arr[j] - arr[i]);
        }
    }

    cout << distance * 2;
    return 0;
}
