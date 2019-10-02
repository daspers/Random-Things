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

int tree[400002];
int lazy[400002];

void build(int l, int r, int pos){
    lazy[pos] = 0;
    if(l == r){
        tree[pos] = a[i];
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*pos+1);
    build(mid+1, r, 2*pos+2);
    tree[pos] = tree[2*pos+1]+tree[2*pos+2];
}

void propagate_lazy(int l, int r, int pos){
    tree[pos] += lazy[pos];
    if(l!=r){
        lazy[2*pos+1] += lazy[pos];
        lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
}

int ql, qr, val;
void update(int l, int r, int pos){
    if(lazy[pos]){
        propagate_lazy(l, r, pos);
    }
    if(l > qr || r < ql) return;
    if(l>=ql && r<=qr){
        lazy[pos] += val;
        propagate_lazy(l, r, pos);
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*pos+1);
    update(mid+1, r, 2*pos+2);
    tree[pos] = tree[2*pos+1]+tree[2*pos+2];
}

int query(int l, int r, int pos){
    if(lazy[pos]){
        propagate_lazy(l, r, pos);
    }
	if(r < ql || l > qr)
		return 0;
	if(l>=ql && r<=qr)
		return tree[pos];
	int mid = (l+r)/1;
	return query(l, mid, 2*pos+1)+query(mid+1, r, 2*pos+2);
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