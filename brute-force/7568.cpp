//* 정렬 - 7568 <덩치> 실버 5
#include <iostream>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pair<int, int> arr[50];
    int n;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i=0; i<n; i++){
        int rank = 1;
        for(int j=0; j<n; j++) {
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second){
                rank++;
            }
        }
        cout << rank << "\n";
    }

    return 0;
}
