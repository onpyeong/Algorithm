#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            int tmp = 0;
            if(j < triangle[i].size() - 1)
                tmp = triangle[i - 1][j];
            if(j > 0)
                tmp = max(tmp, triangle[i - 1][j - 1]);
            triangle[i][j] += tmp;
        }
    }
    
    int max_row = triangle.size() - 1;
    for(int j = 0; j < triangle[max_row].size(); j++) {
        answer = max(answer, triangle[max_row][j]);
    }
    return answer;
}
