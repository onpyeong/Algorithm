#include <iostream>
#include <string>

using namespace std;

int q[10001];
int f = 0, b = -1;

int size() {
    return b - f + 1;
}

bool empty() {
    return b < f;
}

void push(int t) {
    q[++b] = t;
}

void pop() {
    if(empty())
        cout << -1 << "\n";
    else {
        cout << q[f++] << "\n";
    }
}

void front() {
    if(!empty())
        cout << q[f] << "\n";
    else
        cout << -1 << "\n";
}

void back() {
    if(!empty())
        cout << q[b] << "\n";
    else
        cout << -1 << "\n";
}


int main()
{
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string inst;
        cin >> inst;
        if(inst == "push") {
            int tmp;
            cin >> tmp;
            push(tmp);
        }else if(inst == "pop"){
            pop();
        }else if(inst == "size"){
            cout << size() << "\n";
        }else if(inst == "empty"){
            cout << empty() << "\n";
        }else if(inst == "front"){
            front();
        }else {
            back();
        }
    }

    return 0;
}
