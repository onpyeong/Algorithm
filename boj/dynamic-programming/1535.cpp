#include <iostream>

using namespace std;

int n;
int L[21];
int J[21];
int dp[101]; // 무게 i 일 때 최대 J


int main() 
{
    cin >> n;
    
    for(int i = 0; i < n; i++) {
      cin >> L[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> J[i];
    }
    
    for(int i = 0; i < n; i++) { // 사람을 한 명씩 추가하면서 
      for(int life = 99; life >= 0; life--) { // 최대 life부터 감소 (현재 물건의 이전 무게의 계산 값이 현재 물건을 계산할 때 중복되지 않기 위함)
        if(life - L[i] >= 0)
          dp[life] = max(dp[life], dp[life - L[i]] + J[i]);
      }
    }
    
    cout << dp[99];
    
    return 0;
}
