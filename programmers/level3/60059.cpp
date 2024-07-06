#include <string>
#include <vector>
#include <iostream>

using namespace std;

int new_key[20][20];

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int key_size = key.size(), lock_size = lock.size();
    vector<pair<int, int>> zero;
    
    for(int i = 0; i < lock.size(); i++) {
        for(int j = 0; j < lock.size(); j++) {
            if(lock[i][j] == 0)
                zero.push_back({i, j});
        }
    }
    int zero_size = zero.size();
    if(zero_size == 0)
        return true;
    
    for(int i = 0; i < key_size; i++) {
        for(int j = 0; j < key_size; j++) {
            new_key[i][j] = key[i][j];
        }
    }
    
    for(int r = 0; r < 4; r++) {  //회전
        for(int dx = -key_size + 1 + zero[0].first; dx < zero[0].first + key_size; dx++) { //이동 시키기
            for(int dy = -key_size + 1 + zero[0].second; dy < zero[0].second + key_size; dy++) {
                answer = true;
                int cnt = 0;
                for(int x = 0; x < key_size; x++) {
                    for(int y = 0; y < key_size; y++) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if(nx < 0 || ny < 0 || nx >= lock_size || ny >= lock_size){
                            continue;
                        }
                        if((new_key[x][y] == 1 && lock[nx][ny] == 1)
                          || (new_key[x][y] == 0 && lock[nx][ny] == 0)) {
                            answer = false;
                            break;
                        } 
                        if(new_key[x][y] == 1 && lock[nx][ny] == 0) {
                            answer = true;
                            cnt++;
                        }
                    }
                    if(!answer)
                        break;
                }
                if(answer && cnt == zero_size) {
                    return true;
                }else {
                    answer = false;
                }   
            }
        }
        //90도 회전
        for(int i = 0; i < key_size; i++) {
            for(int j = 0; j < key_size; j++) {
                new_key[i][key_size - 1 - j] = key[j][i];
            }
        }
        for(int i = 0; i < key_size; i++) {
            for(int j = 0; j < key_size; j++) {
                key[i][j] = new_key[i][j];
            }
        }
    }

    return answer;
}
