#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isWhite = true;
    for(char c : s) {
        if(c == ' ') {
            isWhite = true;
        }else {
            if(isupper(c) && !isWhite) {
                c += 32;
            }
            if(isWhite && islower(c)) {
                c -= 32;
            }
            isWhite = false;
        }
        answer += c;
    }
    return answer;
}
