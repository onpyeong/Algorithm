#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int population[10003];
int tree[40003]; //도시 간 이동 시간
int edgeCnt[40003]; //도시 간 도로 수
struct Edge {
	int transTime;
	int id;

	bool operator()(const Edge &a, const Edge &b) {
		if (a.transTime == b.transTime)
			return a.id > b.id;
		return a.transTime < b.transTime;
	}
};
priority_queue<Edge, vector<Edge>, Edge> edges; //이동 시간 길고, 고유 번호 작은 순
int initEdges[10003]; //이동 시간 초기값

void initTree(int node, int start, int end) {
	if (start == end) {
		tree[node] = initEdges[start];
		return;
	}
	int mid = (start + end) / 2;
	initTree(node * 2, start, mid);
	initTree(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int id, int value) {
	if (id < start || id > end)
		return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, id, value);
	update(node * 2 + 1, mid + 1, end, id, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int get(int node, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right);
}

void init(int N, int mPopulation[]) {
	//초기화
	edges = priority_queue < Edge, vector<Edge>, Edge>();

	n = N;
	population[0] = mPopulation[0];
	edgeCnt[0] = 1;
	for (int i = 1; i < N; i++) {
		population[i] = mPopulation[i];
		edges.push({ population[i] + population[i - 1], i - 1 });
		initEdges[i - 1] = population[i] + population[i - 1];
		edgeCnt[i - 1] = 1;
	}
	initTree(1, 0, n - 2);
	return;
}

int expand(int M) {
	int maxValue = 0;
	while(M--) {
		maxValue = edges.top().transTime;
		int edgeId = edges.top().id;
		edges.pop();
		edgeCnt[edgeId]++; //도로 개수 증가
		maxValue = floor(initEdges[edgeId] / edgeCnt[edgeId]);
		edges.push({ maxValue, edgeId});
		update(1, 0, n - 2, edgeId, maxValue);
	}
	return maxValue;
}

int calculate(int mFrom, int mTo) {
	if (mTo < mFrom) {
		int t = mTo;
		mTo = mFrom;
		mFrom = t;
	}

	return get(1, 0, n - 2, mFrom, mFrom == mTo ? mTo : mTo - 1);
}

int binarySearch(int from, int to, int K) {
	int s = 0, e = 1000 * n;
	while (s + 1 < e) {
		int mid = (s + e) / 2; //인구 수
		int cnt = 0;
		int p = 0;
		for (int i = from; i <= to; i++) {
			if (p + population[i] <= mid) {
				p += population[i];
			}
			else {
				cnt++;
				p = 0;
				i--;
			}
			if (cnt > K)
				break;
		}
		if (p <= mid) {
			cnt++;
		}
		if (cnt <= K) {
			e = mid;
		}
		else {
			s = mid;
		}
	}
	return e;
}

int divide(int mFrom, int mTo, int K) {
	return binarySearch(mFrom, mTo, K);
}

