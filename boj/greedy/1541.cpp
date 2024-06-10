//* 그리디 - 1541 <잃어버린 괄호> 실버 2
#include <iostream>
#include <string>
using namespace std;

int main() {
    string exp = "";

    cin >> exp;

    int i = 0;
    int ans = 0;
    bool isMinus = false;

    int sum = 0;
    while(i < exp.length()) {
        char c = exp[i++];
        int num = 0;
        while(c != '-') {
            if(c - '0' >= 0 && c - '0' <= 9) {
                num = num * 10 + c - '0';
            }else if(c == '+') {
                sum += num;
                num = 0;
            }
            c = exp[i++];
            if(i > exp.length()) break;
        }
        sum += num;
        if(isMinus) {
            ans -= sum;
            sum = 0;
            isMinus = false;
        }
        if(c == '-') {
            ans += sum;
            sum = 0;
            isMinus = true;
        }
        if(sum > 0) { //더하기만 한 경우
            ans = sum;
        }
    }

    cout << ans << "\n";
    return 0;
}
