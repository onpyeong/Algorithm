#include <iostream>
#include <cmath>

using namespace std;

int N;
int a[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> a[i];
    }
    
    int ans_left, ans_right;
    int left_idx = 0, right_idx = N - 1;
    int min_sum = 2e9;
    while(left_idx < right_idx) {
      long long sum = (long long) a[left_idx] + a[right_idx];
      if(abs(sum) < min_sum) {
        ans_left = a[left_idx];
        ans_right = a[right_idx];
        min_sum = abs(sum);
      }
      if(sum < 0) left_idx++;
      else right_idx--;
    }
    
    cout << ans_left << " " << ans_right << '\n';
    return 0;
}
