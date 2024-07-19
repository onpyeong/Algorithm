#include <iostream>
#include <set>

using namespace std;

set<string> s;

int main()
{
    int N, M, answer = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if(s.find(str) != s.end())
            answer++;
    }
   
    cout << answer;
    return 0;
}
