#include <string>
#include <vector>

using namespace std;

int servers[30];

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int add_server_count = 0;
    
    for(int i = 0; i < 24; i++) {
        add_server_count = players[i] / m - servers[i];
        if(add_server_count > 0) {
            answer += add_server_count;
            for(int j = i; j < i + k && j < 24; j++) {
                servers[j] += add_server_count;
            }
        } 
    }
    return answer;
}
