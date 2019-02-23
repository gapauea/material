/*
	Encontrar elemento em vetor ordenado usando busca binária.
	Autor: William Azevedo da Silva
*/

#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 10012

using namespace std;

int n, q, v[MAXN], t, pos, x;

int f(int mid){
	return (v[mid] >= x);
}

int bb(){
	int lo = 0, hi = n - 1, mid;
	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(f(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main(){_
	while((cin >> n >> q) && (n || q)){
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v, v+n);
		cout << "CASE# " << ++t << ":" << endl;
		for(int i = 0; i < q; i++){
			cin >> x;
			pos = bb();
			if(v[pos] == x) cout << x << " found at " << (pos + 1) << endl;
			else cout << x << " not found" << endl;
		}
	}
	return 0;
}
