//* 구현 - 20291 <파일 정리> 실버 3
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    map <string, int> files;
    map <string, int>::iterator iter;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string file;
        cin >> file;
        string word = file.substr(file.find(".") + 1);
        if(files.find(word) != files.end()){
            files[word] = files[word] + 1;
        }else {
            files[word] = 1;
        }
    }

    for(iter = files.begin(); iter != files.end(); iter++) {
        cout << iter->first << " " << iter->second << "\n";
    }
    return 0;
}
