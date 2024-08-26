#include <iostream>
#include <vector>

using namespace std;

vector<int> d;

int main()
{
    int A, P;
    cin >> A >> P;
    d.push_back(A);
    bool isSame = false;
    int idx = 0;
    
    while(!isSame) {
        int nxt = 0;
        while(A != 0) {
            int t = A % 10;
            int r = 1;
            for(int i = 1; i <= P; i++) {
                r *= t;
            }
            nxt += r;
            A /= 10;
        }
        for(idx = 0; idx < d.size(); idx++) {
            if(d[idx] == nxt) {
                isSame = true;
                break;
            }
        }
        d.push_back(nxt);
        A = nxt;
    }
    
    cout << idx;

    return 0;
}
