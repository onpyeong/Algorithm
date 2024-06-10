#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i = (n + 1) / 2; i >= 1; i--) {
        int sum = i;
        int j = i - 1;
        for(; j >= 1; j--) {
            sum += j;
            if(sum == n) {
                answer++;
                break;
            }else if(sum > n) {
                break;
            }
        }
        if(j == 1)
            break;
    }
    return answer;
}
