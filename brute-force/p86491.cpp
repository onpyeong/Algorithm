#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int min_len = 0, max_len = 0;
    for(int i = 0; i < sizes.size(); i++) {
        int min_idx = (sizes[i][0] <= sizes[i][1]) ? 0 : 1;
        min_len = max(min_len, sizes[i][min_idx]);
        max_len = max(max_len, sizes[i][1 - min_idx]);
    }
    answer = min_len * max_len;
    return answer;
}
