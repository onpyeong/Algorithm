#include <iostream>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
    heap[sz + 1] = x;
    int idx = sz + 1;
    sz++;
    while(idx != 1) {
        if(heap[idx / 2] <= heap[idx]) break;
        int temp = heap[idx / 2];
        heap[idx / 2] = heap[idx];
        heap[idx] = temp;
        idx = idx / 2;
    }
}

void pop(){
    heap[1] = heap[sz];
    heap[sz] = 0;
    sz--;
    int idx = 1;
    while(idx * 2 <= sz) {
        int left = idx * 2;
        int right = (left + 1 <= sz) ? left + 1: left;
        int minValue = left;
        if(heap[left] > heap[right]) {
            minValue = right;
        }
        if(heap[idx] <= heap[minValue]) break;
        int temp = heap[idx];
        heap[idx] = heap[minValue];
        heap[minValue] = temp;
        idx = minValue;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, x;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> x;
        if(x == 0) {
            cout << heap[1] << "\n";
            if(sz == 0) continue;
            pop();
        }else {
            push(x);
        }
    }
}
