#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

typedef long long ll;

int n,i,j,k,t,m,sz;
int tree[132000];
int a[132000];

void createtree(){
	for(int i=n-1;i>=0;i--)
		tree[i] = tree[i<<1] ^ tree[i<<1|1];
}

void update(int p, int val){	// change single value
	for(tree[p+=n] = val;p>0;p>>=1)
		tree[p>>1] = tree[p] ^ tree[p^1];
}

void update(int l, int r, int val){
	for(l+=n, r+=n;l<r;l>>=1,r>>=1){
		if(l&1)
			tree[l++] += val;
		if(r&1)
			tree[--r] += val;
	}
}

int query(int p){
	int res=0;
	for(p+=n;p>0;p>>=1)
		res ^= tree[p];
	return res;
}

void push(){	// push modification to leaves
	for(int i=1;i<n;i++){
		tree[i<<1] += tree[i];
		tree[i<<1|1] += tree[i];
		tree[i] = 0;
	}
}

int query(int l, int r){
	int res = 0;
	for(l += n, r +=n;l<r;l>>=1,r>>=1){
		if(l&1)
			res ^= tree[l++];
		if(r&1)
			res ^= tree[--r];
	}
	return res;
}

int main(){
	scanf("%d %d", &n, &m);
	n = 1<<n;
	sz = n>>1;
	for(i=0;i<n;i++)
		scanf("%d", tree+n+i);
	createtree();
	for(i=0;i<m;i++){
		scanf("%d %d", &t, &k);
    t += n-1;
		if(tree[t] != k){
			update(t-n, k);
		}
		printf("%d\n", query(0, sz-1));
	}
	return 0;
}
