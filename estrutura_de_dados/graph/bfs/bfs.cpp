#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define UNVISITED 0
#define VISITED 1
#define N 50123
#define vi vector<int>

using namespace std;

vi adj[N];
int vis[N];

void initialize(int n) {
    for(int i=0; i < n; ++i) {
        adj[i].clear();
        vis[i] = UNVISITED;
    }
}

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = VISITED; 

    while(!q.empty()) { 
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(vis[v] == UNVISITED) {
                vis[v] = VISITED;
                q.push(v);
            }
        }
    }
}

int n, m, u, v, src;

int main () {
    cin >> n >> m;

    initialize(n + 5);
    
    for(int i=0; i < m; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u); // if is a digraph
    }

    cin >> src;

    bfs(src);

    // Ex: test if is possible to reach some node starting at node src

    for(int i=0; i < n; ++i) {
        if(i != src) {
            if(vis[i] == UNVISITED) {
                cout << i << " is not reachable by " << src << endl;
            }
            else {
                cout << i << " is reachable by " << src << endl;
            }
        }
    }
}
