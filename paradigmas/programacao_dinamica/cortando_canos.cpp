// link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1798
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll long long
#define MAXN 2010
#define INF 1000000123

using namespace std;

ll memo[MAXN], n, t, c[MAXN], v[MAXN];

ll f(ll tam){
	if(tam > t) return -INF;

	if(~memo[tam]) return memo[tam];
	
	ll ans = 0;	
	for(int i = 0; i < n; i++){
		ans = max(ans, f(tam + c[i]) + v[i]);
	}
	return memo[tam] = ans;
}

int main(){_
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		cin >> c[i] >> v[i];
	}
	
	memset(memo, -1, sizeof memo);
	
	cout << f(0) << endl;
	return 0;
}
