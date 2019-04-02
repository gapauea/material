// link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1932
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define MAXN 200123

using namespace std;

int n, v[MAXN], pd[MAXN][2], c;

int lucro(int dia,int acao){
	int ans;
	if (dia == n) return 0;
	if (pd[dia][acao] != -1) return pd[dia][acao];
	ans = acao ? max(lucro(dia+1, 1), lucro(dia+1, 0) + v[dia]) : max(lucro(dia+1, 0), lucro(dia+1, 1) - v[dia] - c);
	return pd[dia][acao] = ans;
}

int main(){_
	cin >> n >> c;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		pd[i][0] = pd[i][1] = -1;
	}
	cout << lucro(0, 0) << endl;
	
	return 0;
}

