#include <iostream>
using namespace std;

int T, n, q, cnt, inst;
int idx, v;
int a[100005];
pair<int, int> tree[400000];

void init(int node, int start, int end) {
  if(start == end) {
    tree[node].first = a[start];
    tree[node].second = a[start];
    return;
  }
  int mid = (start + end) / 2;
  init(node << 1, start, mid);
  init((node << 1) | 1, mid + 1, end);
  tree[node].first = max(tree[node << 1].first, tree[(node << 1) | 1].first);
  tree[node].second = min(tree[node << 1].second, tree[(node << 1) | 1].second);
}

void update(int node, int start, int end) {
	if(end < idx || idx < start) 
        return;
    if(start == end) {
    	tree[node] = {v, v};
        return;
    }
    int mid = (start + end) / 2;
    update(node << 1, start, mid);
    update((node << 1) | 1, mid + 1, end);
    tree[node].first = max(tree[node << 1].first, tree[(node << 1) | 1].first);
    tree[node].second = min(tree[node << 1].second, tree[(node << 1) | 1].second);
}

pair<int, int> get(int node, int start, int end, int left, int right) {
	if(end < left || right < start) 
        return {-1, 1e9};
    if(left <= start && end <= right) {
    	return tree[node];
    }
    int mid = (start + end) / 2;
    pair<int, int> l = get(node << 1, start, mid, left, right);
    pair<int, int> r = get((node << 1) | 1, mid + 1, end, left, right);
    return {max(l.first, r.first), min(l.second, r.second)};
}

int main() 
{
  cin.tie(0) -> ios::sync_with_stdio(0);
  cin >> T;
  int id, x, l, r;
  for(int t = 1; t <= T; t++) {
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    init(1, 0, n - 1);
      cout << "#" << t << " ";
    for(int i = 0; i < q; i++) {
      cin >> inst;
      if(inst == 0) {
        cin >> id >> x;
          idx = id;
          v = x;
          update(1, 0, n - 1);
      }else {
        cin >> l >> r;
        pair<int, int> p = get(1, 0, n - 1, l , r - 1);
        cout <<  p.first - p.second << " ";
      }
    }
    cout << "\n";
  }
    return 0;
}
