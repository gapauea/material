/*
	Questão: Transporte de Painéis Solares
	Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1579
	Autor: William Azevedo da Silva
*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n, T, nPaineis, caminhoes, frete;
vector<ll> painel;

int f(ll mid){
	int t = painel.size();
	ll atualCaminhoes, atualPeso;
	
	atualCaminhoes = 1, atualPeso = 0;
	for(int i = 0; i < t; i++){
		if(atualPeso + painel[i] <= mid){
			atualPeso += painel[i];
		}
		else{
			atualCaminhoes++;
			atualPeso = painel[i];
		}
	}
	
	return (atualCaminhoes <= caminhoes);
}

ll binarySearch(){
	ll lo = *max_element(painel.begin(), painel.end());
	ll hi = accumulate(painel.begin(), painel.end(), 0LL);
	ll mid; 
	
	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(f(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main(){ 
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	while(T--){
		cin >> nPaineis >> caminhoes >> frete;
		
		painel = vector<ll>(nPaineis);
		for(int i = 0; i < nPaineis; i++){
			cin >> painel[i];
		}
		
		ll ans = binarySearch();
		cout << ans << " $" << (ans * caminhoes * frete) << endl;
	}
	return 0;
}
