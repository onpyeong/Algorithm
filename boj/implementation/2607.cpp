#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int N;
string firstWord, word;
int firstAlpha[26];
int alpha[26];
int firstWordSize, wordSize;
bool isDiff;
int diffCount, cnt;

int main()
{
    cin >> N >> firstWord;
    firstWordSize = firstWord.size();
    for(char c : firstWord){
        firstAlpha[c - 'A']++;
    }
    
    for(int i = 0; i < N - 1; i++) {
        cin >> word;
        wordSize = word.size();
        for(int a = 0; a < 26; a++) {
            alpha[a] = 0;
        }
        for(char c : word) {
            alpha[c - 'A']++;
        }
        if(abs(firstWordSize - wordSize) > 1)
            continue;
        isDiff = false;
        diffCount = 0;
        for(int a = 0; a < 26; a++) {
            if(firstAlpha[a] != alpha[a]) {
                if(diffCount <= 1 && abs(firstAlpha[a] - alpha[a]) == 1) {
                    diffCount++;
                    continue;
                }
                isDiff = true;
                break;
            }
        }
        if(isDiff)
            continue;
        cnt++;
    }
    
    cout << cnt;

    return 0;
}
