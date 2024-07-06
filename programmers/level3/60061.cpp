#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> answer;
vector<vector<int>> temp;
int wall[105][105][2]; //기둥, 보

bool compare(const vector<int> &a, const vector<int> &b) {
    if(a[0] == b[0]) {
        if(a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

bool install_bar(int x, int y) {
    //바닥 위
    if(y == N) {
        return true;
    }
    if(wall[y + 1][x][0] == 1){ //기둥 위
        return true;
    }
    //보의 적어도 한쪽 끝 부분 위
    if(wall[y][x][1] == 1 || (x > 0 && wall[y][x - 1][1] == 1)) {
        return true;
    }
    return false;
}

bool install_board(int x, int y) {
    //한쪽 끝이 기둥 위
    if(wall[y + 1][x][0] == 1 || (x < N && wall[y + 1][x + 1][0] == 1)) {
        return true;
    }
    //양쪽 끝이 보랑 연결
    if((x > 0 && wall[y][x - 1][1] == 1) && (x < N - 1 && wall[y][x + 1][1] == 1)) {
        return true;
    }
    return false;
}

void delete_bar(int x, int y) {
    wall[y][x][0] = 0;
    bool flag = true;
    int idx = 0;
    for(int i = 0; i < temp.size(); i++) {
        int ty = temp[i][0], tx = temp[i][1], type = temp[i][2];
        if(ty == y && tx == x && type == 0) {
            idx = i;
            continue;
        }
        if(type == 0) {
            if(!install_bar(tx, ty)) {
                flag = false;
                break;
            } 
        }else {
            if(!install_board(tx, ty)) {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        temp.erase(temp.begin() + idx);
    }else {
        wall[y][x][0] = 1;
    }
}

void delete_board(int x, int y) {
    wall[y][x][1] = 0;
    bool flag = true;
    int idx;
    for(int i = 0; i < temp.size(); i++) {
        int ty = temp[i][0], tx = temp[i][1], type = temp[i][2];
        if(ty == y && tx == x && type == 1) {
            idx = i;
            continue;
        }
        if(type == 0) {
            if(!install_bar(tx, ty)) {
                flag = false;
                break;
            } 
        }else {
            if(!install_board(tx, ty)) {
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        temp.erase(temp.begin() + idx);
    }else {
        wall[y][x][1] = 1;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n;
   
    for(int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0], y = n - build_frame[i][1],
        type = build_frame[i][2], oper = build_frame[i][3];
        if(type == 0) {
            if(oper == 0)
                delete_bar(x, y);
            else if(install_bar(x, y)) {
                wall[y][x][0] = 1;
                temp.push_back({y, x, 0});
            }
        }else {
            if(oper == 0)
                delete_board(x, y);
            else if(install_board(x, y)) {
                wall[y][x][1] = 1;
                temp.push_back({y, x, 1});
            }
        }
    }
    
    for(int i = 0; i < temp.size(); i++) {
        answer.push_back({temp[i][1], n - temp[i][0], temp[i][2]});
    }
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}
