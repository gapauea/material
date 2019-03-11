#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)
#define mid(a, b) ((a + b) >> 1)
#define comp(a, b) (a + b)
#define MAX 1000123
#define NEUTRAL 0 
#define ll long long
#define vi vector<ll>

using namespace std;

vi tree, a;

int size;

ll build(int u, int l, int r) {
	if(l == r) return tree[u] = a[l];
	build(left(u), l, mid(l, r));
	build(right(u), mid(l, r) + 1, r);
	
	return tree[u] = comp(tree[left(u)], tree[right(u)]);
}

void build() {
    tree = vi(4 * size, 0);
    build(1, 0, size - 1);
}

ll query(int u, int i, int j, int l, int r) {
	if(i > r || j < l) return NEUTRAL;
	if(l <= i && j <= r) return tree[u];
	
	ll lans = query(left(u), i, mid(i, j), l, r);
	ll rans = query(right(u), mid(i, j) + 1, j, l, r);
	
	return comp(lans, rans);
}

ll query(int l, int r) {
	return query(1, 0, size - 1, l, r);
}

ll update(int u, int i, int j, int idx, ll value) {
    if(idx < i || idx > j) return NEUTRAL;
    if(i == j) return tree[u] = value;
    update(left(u), i, mid(i, j), idx, value);
    update(right(u), mid(i, j) + 1, j, idx, value);
	return tree[u] = comp(tree[left(u)], tree[right(u)]);
}

ll update(int idx, int value) {
	return update(1, 0, size - 1, idx, value);
}

int main() {_
    
    size = 7;
    a = {1, 1, 2, 3, 5, 8, 13};
    build();

    cout << query(0, size - 1) << endl; // 33
    update(0, 0);
    cout << query(0, size - 1) << endl; // 32

	return 0;
}
