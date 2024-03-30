#include <iostream>
#include <set>

using namespace std;

set<string, greater<string>> s;

int main() {
    
    int n;
    
    cin >> n;
    
    string name, status;
    for(int i = 0; i < n; i++) {
        cin >> name >> status;
        if(status == "enter") {
            s.insert(name);
        }else {
            s.erase(name);
        }
    }
    
    for(auto i : s) {
        cout << i << "\n";
    }

    return 0;
}
