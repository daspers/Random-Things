#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;

vector<int> adj[100002];
bool vis[100002];
int low[100002],dfn[100002],times,q[100002],head,scc_cnt,scc[100002],sz[100002];

void tarjan(int u,int f){
    dfn[u]=low[u]=++times;
    q[++head]=u;
    vis[u] = true;
    for(int i:adj[u]){
        if(i==f)continue;
        if(!dfn[i]){
            tarjan(i,u);
            low[u]=min(low[u],low[i]);
        }
        else low[u]=min(low[u],dfn[i]);
    }
    if(low[u]==dfn[u]){
        scc_cnt++;
        while(true){
            int x=q[head--];
            scc[x]=scc_cnt;
            sz[scc_cnt]++;
            if(x==u)break;
        }
    }
}

int main(){
	scanf("%d", &n);
    
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}