#include <iostream>
#include <algorithm>

using namespace std;

int point[4][4];

int main() {
    
    for(int i = 0; i < 3; i++) {
        cin >> point[i][0] >> point[i][1];
    }
    
    double len[3];
    int idx = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = i + 1; j <= 2; j++) {
            int x2 = (point[i][0] - point[j][0]) * (point[i][0] - point[j][0]);
            int y2 = (point[i][1] - point[j][1]) * (point[i][1] - point[j][1]);
            len[idx++] = x2 + y2;
        }
    }
    
    sort(len, len + 3);
    
    string t = "";
    int a1 = (point[1][1] - point[0][1]) * (point[2][0] - point[0][0]);
    int a2 = (point[2][1] - point[0][1]) * (point[1][0] - point[0][0]);
    if(a1 == a2) {
        cout << "X";
        return 0;
    }else if(len[0] == len[1] && len[1] == len[2]){
        cout << "JungTriangle";
        return 0;
    }else if(len[0] == len[1] || len[1] == len[2] || len[0] == len[2]) {
        t = "2";
    }
    
    if(len[0] + len[1] > len[2]) {
        cout << "Yeahkak" + t + "Triangle";
    }else if(len[0] + len[1] == len[2]) {
        cout << "Jikkak" + t + "Triangle";
    }else {
        cout << "Dunkak" + t + "Triangle";
    }

    return 0;
}
