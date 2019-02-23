/*
	Solução da questão "Pie"
	link: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1636
	Autor: William Azevedo da Silva
*/

#include<bits/stdc++.h>
#define N 10134

using namespace std;

int n, amigos;
double v[N];

int f(double vol){
	int cont = 0;
	for(int i = 0; i < n; ++i){
		cont += (int)(v[i] / vol);
	}
	if(cont < amigos) return 1;
	return 0;
}

double bb(){
	double lo = 0.0, hi = 4.0 * M_PI * 10001.0 * 10001.0, mid;
	
	for(int i = 70; i--; ){
		mid = lo + (hi - lo) / 2.0;
		if(f(mid)) hi = mid;
		else lo = mid;
	}
	return lo;
}

int main(){
	ios_base::sync_with_stdio(0);
	double raio;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> amigos;
		amigos = amigos + 1;
		for(int i = 0; i < n; ++i){
			cin >> raio;
			v[i] = raio * raio * M_PI;
		}
		cout << fixed << setprecision(5);
		cout << bb() << endl;
	}
	
	return 0;
}
