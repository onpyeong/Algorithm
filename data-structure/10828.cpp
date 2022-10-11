//* 스택 - 10828 <스택> 실버 4
#include <iostream>
#include <string>
using namespace std;

int stack[10001] = {};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int top = 0;
    string command;

    cin >> n;

    while (n--) {
        cin >> command;
        int x;

        if (command == "push") {
            cin >> x;
            stack[top++] = x;
        }else if (command == "pop") {
            if(top == 0) {
                cout << -1 << "\n";
            }else {
                cout << stack[--top] << "\n";
            }
        }else if (command == "size") {
            cout << top << '\n';
        }else if (command == "empty") {
            if(top == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else if (command == "top") {
            if(top == 0) cout << -1 << "\n";
            else cout << stack[top - 1] << "\n";
        }
    }

    return 0;
}