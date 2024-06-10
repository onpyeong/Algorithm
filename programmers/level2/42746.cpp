#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
    for(int number : numbers) {
        s.push_back(to_string(number));
    }
    
    sort(s.begin(), s.end(), compare);
    
    for(string number : s) {
        answer += number;
    }
    if(answer[0] == '0')
        answer = "0";
    return answer;
}
