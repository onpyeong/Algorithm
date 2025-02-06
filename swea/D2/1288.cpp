#include <iostream>

using namespace std;

int T;
long long N, tmp, newNum;
int isNum;

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
    	  cin >> N;
        isNum = 0; //0~9 체크
        newNum = tmp = 0;
        while(isNum != 1023) {
          newNum += N;
          tmp = newNum;
          while(tmp != 0) {
          	isNum = (isNum | (1 << (tmp % 10)));
            tmp /= 10;
          }
        }
        cout << "#" << t << " " << newNum << "\n";
    }
	return 0;
}
