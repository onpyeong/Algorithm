#include <iostream>

using namespace std;

int x, count;

int main() {
    cin >> x;
    
    while(x > 0) {
        count += x % 2;
        x /= 2;
    } 

    cout << count;
    return 0;
}
