#include <iostream>
#define MAX 999999

using namespace std;

int N;
struct Score {
	int score, min_score, max_score;
}scores[2][3]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp, total_max_score = 0, total_min_score = MAX;
    
    cin >> N;
    
    cin >> scores[0][0].score >> scores[0][1].score >> scores[0][2].score;
    scores[0][0].min_score = scores[0][0].max_score = scores[0][0].score;
    scores[0][1].min_score = scores[0][1].max_score = scores[0][1].score;
    scores[0][2].min_score = scores[0][2].max_score = scores[0][2].score;
    
    for(int i = 1; i < N; i++) {
	    for(int j = 0; j < 3; j++) {
		    cin >> tmp;
		    scores[1][j] = {tmp, MAX, 0};
	    }
	    
	    for(int j = 0; j < 3; j++) {
		    if(j > 0) {
			    scores[1][j - 1].min_score = min(scores[1][j - 1].min_score, scores[1][j - 1].score + scores[0][j].min_score);
			    scores[1][j - 1].max_score = max(scores[1][j - 1].max_score, scores[1][j - 1].score + scores[0][j].max_score);
		    }
		    scores[1][j].min_score = min(scores[1][j].min_score, scores[1][j].score + scores[0][j].min_score);
		    scores[1][j].max_score = max(scores[1][j].max_score, scores[1][j].score + scores[0][j].max_score);
		    if(j < 2) {
			    scores[1][j + 1].min_score = min(scores[1][j + 1].min_score, scores[1][j + 1].score + scores[0][j].min_score);
			    scores[1][j + 1].max_score = max(scores[1][j + 1].max_score, scores[1][j + 1].score + scores[0][j].max_score);
		    }
	    }
	    scores[0][0] = scores[1][0];
	    scores[0][1] = scores[1][1];
	    scores[0][2] = scores[1][2];
    }
    
    for(int i = 0; i < 3; i++) {
	    total_max_score = max(total_max_score, scores[0][i].max_score);
	    total_min_score = min(total_min_score, scores[0][i].min_score);
    }
    
    cout << total_max_score << ' ' << total_min_score << '\n';
    
    
    return 0;
}
