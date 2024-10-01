#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int c_size = computers.size();
    for(int i = 0; i < c_size; i++) {
        if(!visited[i]) {
            queue <int> q;
            q.push(i);
            visited[i] = true;
            
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                for(int n = 0; n < c_size; n++) {
                    if(x == n)
                        continue;
                    if(computers[x][n] == 0 || visited[n])
                        continue;
                    visited[n] = true;
                    q.push(n);
                }
            }
            answer++;
        }
    }
    
    return answer;
}
