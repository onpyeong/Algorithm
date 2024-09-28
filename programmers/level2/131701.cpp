#include <string>
#include <vector>

using namespace std;

bool num[1000001];

int solution(vector<int> elements) {
    int answer = 0, e_size = elements.size();
    int total = 0;
    
    for(int i = 0; i < e_size; i++) {
        total += elements[i];
    }
    for(int i = 0; i < e_size; i++) {
        int sum = 0;
        for(int j = 0; j < e_size; j++) {
            int idx = (i + j) % e_size;
            sum += elements[idx];
            num[sum] = true;
        }
    }
    for(int i = 1; i <= total; i++){
        if(num[i])
            answer++;
    }
    return answer;
}
