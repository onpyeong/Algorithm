#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t = (n % 2 == 0) ? n / 2 : n / 2 + 1;
        for(int j = 0; j < t; j++) {
            cout << "* ";
        }
        cout << "\n";
        for(int j = 0; j < n / 2; j++) {
            cout << " *";
        }
        cout << "\n";
    }
    return 0;
}
