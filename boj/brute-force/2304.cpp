#include <iostream>

using namespace std;

int N, L, H, answer;
int maxHeightIdx, maxHeight, lastIdx;
int a[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> L >> H;
      a[L] = H;
      if(H > maxHeight) {
        maxHeight = H;
        maxHeightIdx = L;
      }
    }
    
    int leftMaxIdx = 0, rightMaxIdx = 1001;
    //왼
    for(int i = 1; i < maxHeightIdx; i++) {
      if(a[leftMaxIdx] < a[i]) {
        leftMaxIdx = i;
      }
      answer += a[leftMaxIdx];
    }
    //오
    for(int i = 1000; i > maxHeightIdx; i--) {
      if(a[rightMaxIdx] < a[i]) {
        rightMaxIdx = i;
      }
      answer += a[rightMaxIdx];
    }
   
    cout << answer + a[maxHeightIdx] << "\n";
}
