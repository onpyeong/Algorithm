#include <iostream>
#include <vector>

using namespace std;

vector<int> front;
int arr[50005];

int main()
{
    string s;
    int answer = 0, s_size;
    cin >> s;
    s_size = s.size();

    for(int i = s_size - 1; i > 0; i--) {
        if(s[i] == ')' && s[i - 1] == ')') {
            arr[i] = arr[i + 1] + 1;
        }else {
            arr[i] = arr[i + 1];
        }
        if(s[i] == '(' && s[i - 1] == '(') {
            front.push_back(i);
        }
    }
    
    for(int i = 0; i < front.size(); i++) {
        answer += arr[front[i]];
    }
    cout << answer;
    return 0;
}
