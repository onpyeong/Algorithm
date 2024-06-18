#include <iostream>

using namespace std;

int a, b;

int main()
{
    cin >> a >> b;
    
    int ans = 1;
    while(a < b) {
        if(b % 10 == 1){
            ans++;
            b /= 10;
        }else if(b % 2 == 0){
            ans++;
            b /= 2;
        }else {
            break;
        }
    }
    if(a == b)
        cout << ans;
    else
        cout << -1;

    return 0;
}
