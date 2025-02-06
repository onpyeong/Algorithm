#include <iostream>

using namespace std;

int T, N, M, nBitOff;
string power;

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N >> M;
        nBitOff = ~0 << N; //11111000
        if((nBitOff | M) == ~0)
            power = "ON";
        else
            power = "OFF";
    	cout << "#" << t << " " << power << "\n";
    }
	return 0;
}
