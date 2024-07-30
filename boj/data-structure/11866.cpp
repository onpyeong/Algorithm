#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        q.push(i);
    }
    cout << "<";
    while(q.size() > 1) {
        for(int i = 1; i < K; i++) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    
    return 0;
}
