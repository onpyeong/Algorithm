#include <string>
#include <vector>
#include <iostream>

using namespace std;

int zero_cnt, one_cnt;
vector<vector<int>> cp_arr;

void quadtree(int x, int y, int length) {
    if(length == 1) {
        if(cp_arr[x][y]) one_cnt++; else zero_cnt++;
        return;
    }
    
    bool is_diff = 0;
    for(int i = x; i < x + length; i++) {
        for(int j = y; j < y + length; j++) {
            if(cp_arr[x][y] != cp_arr[i][j]){
                is_diff = 1;
                break;
            }
        }
    }
    
    if(is_diff) {
        quadtree(x, y, length/2);
        quadtree(x, y + length/2, length/2);
        quadtree(x + length/2, y, length/2);
        quadtree(x + length/2, y + length/2, length/2);
    }else {
        if(cp_arr[x][y]) one_cnt++; else zero_cnt++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    cp_arr = arr;
    
    quadtree(0, 0, arr.size());
    answer.push_back(zero_cnt);
    answer.push_back(one_cnt);
    
    return answer;
}
