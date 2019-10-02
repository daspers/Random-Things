#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

template<class T>
struct FenwickTree{
	T *tree;
	int sz;
	FenwickTree(int n){
		tree = new T[n+2];
		sz = n;
		memset(tree, 0, (n+2)*sizeof(T));
	}
	FenwickTree(T* arr, int n){
		tree = new T[n+2];
		tree[0] = 0;
		sz = n;
		for(int i=1;i<=n;i++)
			tree[i] = tree[i-1]+arr[i];
		for(int i=n;i>1;i--)
			tree[i] -= tree[i - lastbit(i)];
	}
	FenwickTree(vector<T> &arr){
		int n = arr.size();
		tree = new T[n+2];
		tree[0] = 0;
		sz = n;
		for(int i=1;i<=n;i++)
			tree[i] = tree[i-1]+arr[i-1];
		for(int i=n;i>1;i--)
			tree[i] -= tree[i - lastbit(i)];
	}
	~FenwickTree(){ delete[] tree;}
	void update(int idx, T delta){
		for(;idx<=sz;idx += lastbit(idx))
			tree[idx] += delta;
	}
	int lower_bound(T value){
		T sum = 0;
		int pos = 0;
		int LOGN = ceil(log2(sz));
		for(int i=1<<LOGN; i>0; i>>=1){
			if(pos + i < sz && sum + bit[pos + i] < v){
				sum += bit[pos + i];
				pos += i;
			}
		}
		return pos + 1;
	}
	T sum(int idx){
		T res = 0;
		for(;idx >0;idx-=lastbit(idx)){
			res += tree[idx];
		}
		return res;
	}
	static inline int lastbit(int a){ return a&(-a); }
};

int main(){
	return 0;
}
