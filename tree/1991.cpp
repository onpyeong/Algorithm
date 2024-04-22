#include <iostream>

using namespace std;

int lc[30];
int rc[30];

void preorder(int cur) {
    cout << (char)(cur + 'A');
    if(lc[cur] != 0) preorder(lc[cur]);
    if(rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
    if(lc[cur] != 0) inorder(lc[cur]);
    cout << (char)(cur + 'A');
    if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
    if(lc[cur] != 0) postorder(lc[cur]);
    if(rc[cur] != 0) postorder(rc[cur]);
    cout << (char)(cur + 'A');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        char s, l, r;
        cin >> s >> l >> r;
        if(l != '.') lc[s - 'A'] = l - 'A';
        if(r != '.') rc[s - 'A'] = r - 'A';
    }
    
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    
    return 0;
}
