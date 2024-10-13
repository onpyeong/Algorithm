#include <iostream>

using namespace std;

int switchNum, studentNum;
bool status[101];
int gender, num;

int main()
{
    cin >> switchNum;
    for(int i = 1; i <= switchNum; i++){
        cin >> status[i];
    }
    cin >> studentNum;
    for(int i = 0; i < studentNum; i++) {
        cin >> gender >> num;
        if(gender == 1) {
            for(int j = num; j <= switchNum; j += num) {
                status[j] = !status[j];
            }
        }else {
            status[num] = !status[num];
            for(int j = 1; num + j <= switchNum && num - j > 0; j++) {
                if(status[num - j] != status[num + j])
                    break;
                status[num - j] = !status[num - j];
                status[num + j] = !status[num + j];
            }
        }
    }
    
    for(int i = 1; i <= switchNum; i++) {
        cout << status[i] << " ";
        if(i % 20 == 0) {
            cout << "\n";
        }
    }
    return 0;
}
