#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
int l;
vector<int> adj[100002];
int up[100002][32];
int timer;
int tin[100002], tout[100002];

/* Copy From cp-algorithms.com */

void dfslca(int v, int p){
	tin[v] = ++timer;
	up[v][0] = p;
	for(int i=1;i<=l;++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for(int x : adj[v])
		if(x!=p)
			dfslca(x, v);
	tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
	if(is_ancestor(u, v))
		return u;
	if(is_ancestor(v, u))
		return v;
	for(int i=l;i>=0;--i)
		if(!is_ancestor(up[u][i], v))
			u = up[u][i];
	return up[u][0];
}

void preprocess(int root){
	memset(up, 0, sizeof up);
	timer = 0;
	l = ceil(log2(n));
	dfslca(root, root);
}

int main(){
	preprocess(1);
	return 0;
}
