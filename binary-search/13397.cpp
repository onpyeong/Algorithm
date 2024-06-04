#include <iostream>

using namespace std;

int N, M;
int arr[5001];

bool check(int mid) {
    //구간 수 세기
    int cnt = 1;
    int min = 0, max = 0;
    int i = 1;
    while(i < N) {
        if(arr[min] > arr[i])
            min = i;
        if(arr[max] <= arr[i])
            max = i;
        if(arr[max] - arr[min] > mid) { //구간 나누기
            cnt++;
            min = i; max = i;
        }
        i++;
    }
    if(cnt <= M) {
        return true;
    }else {
        return false;
    }
}

int main()
{
    //점수를 기점으로 
    //F F (F T) T T T 제일 작은 T값
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int s = -2, e = 10001, mid;
    while(s + 1 < e) {
        mid = (s + e) / 2;
        if(check(mid)) {
            e = mid;
        }else {
            s = mid;
        }
    }
    
    cout << e;

    return 0;
}
