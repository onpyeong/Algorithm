#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[103][2];
int b[103][2];
int c[103][3];
bool op[103];
bool isX[103];
int maxN[103];
bool num[10];

int calcNum(int mode, int eId, int x) {
    int n = 0;
    if(mode == 0) {
        for(int i = 0; i < 2; i++) {
            if(a[eId][i] == -1) {
                return n;
            }
            n = n * x + a[eId][i];
        }
    }else if(mode == 1) {
        for(int i = 0; i < 2; i++) {
            if(b[eId][i] == -1) {
                return n;
            }
            n = n * x + b[eId][i];
        }
    }else {
        for(int i = 0; i < 3; i++) {
            if(c[eId][i] == -1) {
                return n;
            }
            n = n * x + c[eId][i];
        }
    }
    return n;
}

string calcCStr(int cNum, int x) {
    string cStr = "";
    if(cNum == 0)
        return "0";
    while(cNum != 0) {
        cStr += (cNum % x) + '0';
        cNum /= x;
    }
    reverse(cStr.begin(), cStr.end());
    return cStr;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    int totalMaxN = 0;
    
    for(int i = 0; i <= 100; i++) {
        fill(a[i], a[i] + 2, -1);
        fill(b[i], b[i] + 2, -1);
        fill(c[i], c[i] + 3, -1);
    }
    for(int i = 2; i < 10; i++) {
        num[i] = true;
    }
    
    for(int i = 0; i < expressions.size(); i++) {
        string s = expressions[i];
        int j = 0;
        for(; j < 3; j++) {
            if(s[j] == ' ') {
                op[i] = (s[j + 1] == '+')? true : false;
                j += 3;
                break;
            }
            a[i][j] = s[j] - '0';
            maxN[i] = max(maxN[i], a[i][j]);
        }
        for(int k = 0; k < 3; k++) {
            if(s[j] == ' ') {
                j += 3;
                break;
            }
            b[i][k] = s[j++] - '0';
            maxN[i] = max(maxN[i], b[i][k]);
        }
        for(int k = 0; j < s.size(); k++) {
            if(s[j] == 'X') {
                isX[i] = true;
                break;
            }
            c[i][k] = s[j++] - '0';
            maxN[i] = max(maxN[i], c[i][k]);
        }
        totalMaxN = max(totalMaxN, maxN[i]);
    }
    
    // 최소 진법 계산
    for(int i = 2; i <= totalMaxN; i++) {
        num[i] = false;
    }
    totalMaxN++;
    
    // 숫자 있는 걸로 최소 진법 대임
    int aNum, bNum, cNum;
    for(int eId = 0; eId < expressions.size(); eId++) {
        if(isX[eId]) 
            continue;
        for(int x = totalMaxN; x <= 9; x++) {
            if(!num[x])
                continue;
            aNum = calcNum(0, eId, x);
            bNum = calcNum(1, eId, x);
            cNum = calcNum(2, eId, x);
            if((op[eId] && aNum + bNum != cNum) || (!op[eId] && aNum - bNum != cNum)) {
                num[x] = false; // 해당 진법 탈락
            }
        }
        
    }

    // X인 식에 진법 대입해보기
    bool isSame; 
    string cStr, pStr;
    for(int eId = 0; eId < expressions.size(); eId++) {
        if(!isX[eId]) 
            continue;
        isSame = true;
        cStr = "";
        for(int x = totalMaxN; x <= 9; x++) {
            if(!num[x])
                continue;
            aNum = calcNum(0, eId, x); // 진법
            bNum = calcNum(1, eId, x);
            if(cStr == "") {
                cStr = (op[eId])? calcCStr(aNum + bNum, x) : calcCStr(aNum - bNum, x);
                pStr = cStr;
                continue;
            }
            // 이전 진법과 결과가 다른 경우
            if((op[eId] && calcCStr(aNum + bNum, x) != pStr) || (!op[eId] && calcCStr(aNum - bNum, x) != pStr)) {
                //num[x] = false; // 여기서는 진법 탈락시키면 X
                isSame = false;
                string s = expressions[eId].substr(0, expressions[eId].size() - 1) + "?";
            answer.push_back(s);
                break;
            }
        }
        // 모든 진법의 결과가 같은 경우
        if(isSame) {
            isX[eId] = false;
            string s = expressions[eId].substr(0, expressions[eId].size() - 1) + cStr;
            answer.push_back(s);
        }
    }
    
    return answer;
}
