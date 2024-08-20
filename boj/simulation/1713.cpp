#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, r;
struct Student{
    int num;
    int cnt;
    int idx;
};
Student p[21], t[21];

bool compare(const Student &a, const Student &b) {
    if(a.cnt == b.cnt)
        return a.idx < b.idx;
    return a.cnt < b.cnt;
}

bool compare_num(const Student &a, const Student &b) {
    return a.num < b.num;
}

int main()
{
    int num, size = 0;
    cin >> N >> r;
    for(int i = 0; i < r; i++) {
        cin >> num;
        //중복 체크
        int j;
        for(j = 0; j < size; j++) {
            if(p[j].num == num) {
                p[j].cnt++;
                break;
            }
        }
        if(j < size)
            continue;
        if(size == N) { //비어있는 사진틀이 없는 경우
            for(int j = 0; j < N; j++) {
                t[j] = p[j];
            }
            sort(t, t + N, compare);
            int j;
            for(j = 0; j < N; j++) {
                if(p[j].idx == t[0].idx)
                    break;
            }
            p[j] = {num, 1, i}; //삭제 후 그 자리에 추가
            continue;
        }
        p[size++] = {num, 1, i};
    }
    
    sort(p, p + size, compare_num);
    
    for(int i = 0; i < size; i++) {
        cout << p[i].num << " ";
    }

    return 0;
}
