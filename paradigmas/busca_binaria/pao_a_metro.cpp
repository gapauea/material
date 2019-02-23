/*
	Questão: Pão a Metro
	Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2329
	Autor: William Azevedo da Silva
*/

#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll>

using namespace std;

ll pessoas, sanduiches;
vi sanduiche;

int f(int mid){
	ll atualPedacos, atualTam;

	atualPedacos = 0LL;
	for(int i = 0; i < sanduiches; i++) {
		atualPedacos += (ll)(sanduiche[i]/mid);
	}
	return (atualPedacos < pessoas);
}

ll binarySearch(){
	ll lo = 1LL, mid;
	ll hi = *max_element(sanduiche.begin(), sanduiche.end());
	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(f(mid)) hi = mid;
		else lo = mid + 1;
	}
	return (lo - 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	
	cin >> pessoas >> sanduiches;
	
	sanduiche = vi(sanduiches);
	for(int i = 0; i < sanduiches; i++) cin >> sanduiche[i];
	
	cout << binarySearch() << endl;
	
	return 0;
}
