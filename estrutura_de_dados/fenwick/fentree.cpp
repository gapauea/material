// https://www.spoj.com/problems/FENTREE/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000006

int n, q, l, r, i, x;
int a[N], fw[N];
char op;

int query(int i) {
    int sum = 0;
    for (int x = i; x; x-= x&(-x)) sum += fw[x];
    return sum;
}

void update(int i, int value) {
    for (int x = i; x < N; x += x&(-x)) fw[x] += value;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}

	cin >> q;
	while (q--) {
		cin >> op;
		if (op == 'q') {
			cin >> l >> r;
			// sempre verifique se o problema garante que l <= r
			int result = query(r)-query(l-1);
			cout << result << endl;
		} else {
			cin >> i >> x;
			update(i, x);
		}
	}

	return 0;
}

