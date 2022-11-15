//* DP - 14916 <거스름돈> 실버 5
#include <iostream>
using namespace std;

int main() {
    int n;
    int count = 0;

    cin >> n;

    int remain = n;
    count += (n / 5);
    remain = remain % 5;
    count += (remain / 2);
    remain = remain % 2;

    if(remain == 0) {
        cout << count << "\n";
    } else {
        int min_count = -1;
        min_count += (n / 5);
        remain = (n % 5) + 5;
        if (min_count == -1) {
            min_count = 0;
            remain = (n % 5);
        }
        min_count += remain / 2;
        remain = remain % 2;
        if (remain != 0)
            cout << -1 << "\n";
        else
            cout << min_count << "\n";
    }
    
    return 0;
}
