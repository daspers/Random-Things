#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

template<class T>
struct mapper{
	std::vector<T> m;
	mapper(){}
	mapper(const T *arr, int sz){mapping(arr, sz);}
	mapper(const vector<T> &arr){mapping(arr);}
	void mapping(const T *arr, int sz){
		m.clear();
		for(int i=0;i<sz;++i)
			m.pb(arr[i]);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	void mapping(const vector<T> &arr){
		m.clear();
		for(const T &x : arr)
			m.pb(x);
		sort(m.begin(), m.end());
		m.erase(unique(m.begin(), m.end()), m.end());
	}
	int get(const T &val){ return lower_bound(m.begin(), m.end(), val) - m.begin();}
	int operator[] (const T &val){ return get(val);}
};

int n,i,j,k,t;

int main(){
	return 0;
}
