#include <iostream>

using namespace std;

int N, M;
int a[100003];
long long tree[400003];
long long lazy[400003];

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

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node] * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int start, int end, int left, int right, int value) {
	update_lazy(node, start, end);
	if (end < left || right < start)
		return;
	if (left <= start && end <= right) {
		tree[node] += value * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		lazy[node] = 0;
		return;
	}

	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right, value);
	update_range(node * 2 + 1, mid + 1, end, left, right, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long get(int node, int start, int end, int idx) {
	update_lazy(node, start, end);
	if (end < idx || idx < start)
		return 0;
	if (start == end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return get(node * 2, start, mid, idx) + get(node * 2 + 1, mid + 1, end, idx);
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	int inst, l, r, k;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	init(1, 1, N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> inst;
		if (inst == 1) {
			cin >> l >> r >> k;
			update_range(1, 1, N, l, r, k);
		}
		else {
			cin >> l;
			cout << get(1, 1, N, l) << "\n";
		}
	}
	return 0;
}
