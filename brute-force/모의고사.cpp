#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one = 0, two = 0, three = 0;
    int one_answer[5] = {1, 2, 3, 4, 5};
    int two_answer[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three_answer[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == one_answer[i % 5]) one++;
        if(answers[i] == two_answer[i % 8]) two++;
        if(answers[i] == three_answer[i % 10]) three++;
    }
		//정답 수 크기 비교 부분
    /*
    int they[3] = {0, 0, 0};
    //they[0]가 1번 수포자의 정답수
    int max_value = *max_element(they, they + 3);
    
    for(int i = 0; i < 3; i++){
    	if(max_value == they[i]) answer.push_back(i + 1);
    }
    */
    if(one >= two) {
        if(one >= three) {
            answer.push_back(1);
            if(one == two) {
                answer.push_back(2);
            }
            if(one == three) {
                answer.push_back(3);
            }
        }
        else {
            answer.push_back(3);
        }
    }else {
        if(two >= three) {
            answer.push_back(2);
            if(two == three)
                answer.push_back(3);
        }else {
            answer.push_back(3);
        }
    }
    
    return answer;
}
