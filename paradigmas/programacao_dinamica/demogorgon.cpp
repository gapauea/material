// link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2532
#include<iostream>
#define MAXN 2017
#define INF 1000000123

using namespace std;

int n, memo[MAXN][MAXN], vida, d[MAXN], m[MAXN], ans;

int solve(int i, int hp){
	if(hp <= 0) return 0;
	
	if(i == n) return INF;
	
	if(memo[i][hp] != -1) return memo[i][hp];
	
	return memo[i][hp] =min(solve(i + 1, hp), solve(i + 1, hp - d[i]) + m[i]);
}

int main(){
	while(cin >> n >> vida){
	
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= vida; j++) memo[i][j] = -1;
	
		for(int i = 0; i < n; i++) cin >> d[i] >> m[i];
		
		ans = solve(0, vida);
		
		if(ans != INF)cout << ans << endl;
		else cout << "-1\n";
	}
	return 0;
}
