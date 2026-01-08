#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[200001];
int b[200001];

int main() 
{
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    
    for(int i = 0; i < m; i++) {
      cin >> b[i];
    }
    
    sort(a, a + n);
    sort(b, b + m);
    
    int i = 0, j = 0;
    int same_cnt = 0;
    while(i < n && j < m) {
      if(a[i] == b[j]) {
        i++;
        j++;
        same_cnt++;
      }else if(a[i] < b[j]) {
        i++;
      }else {
        j++;
      }
    }
    
    cout << n + m - same_cnt * 2 << '\n';
    return 0;
}
