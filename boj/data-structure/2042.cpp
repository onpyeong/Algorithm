#include <iostream>

using namespace std;

int N, M, K;

long long a[1000003];
long long tree[4000003];

void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int idx, long long value) {
	if (idx < start || idx > end)
		return;
	if (start == end) {
		tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, value);
	update(node * 2 + 1, mid + 1, end, idx, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long get(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int inst, b, d;
	long long c;

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	init(1, 1, N);
	for (int i = 0; i < M + K; i++) {
		cin >> inst >> b;
		if (inst == 1) {
			cin >> c;
			update(1, 1, N, b, c);
		}
		else {
			cin >> d;
			cout << get(1, 1, N, b, d) << "\n";
		}
	}
	return 0;
}
