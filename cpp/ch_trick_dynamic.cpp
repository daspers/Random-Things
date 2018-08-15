#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

const ll mod = 1e9+7;
const double pi = acos(-1);

const ll is_query = -(1LL<<62);

struct Line {
	ll m, b;
	mutable function<const Line*()> succ;
	bool operator<(const Line& rhs) const {
		if (rhs.b != is_query) return m < rhs.m; // min: reverse it
		const Line* s = succ();
		if (!s) return 0;
		ll x = rhs.m;
		return b - s->b < (s->m - m) * x; // min: reverse it
	}
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
	bool bad(iterator y) {
		auto z = next(y);
		if (y == begin()) {
			if (z == end()) return 0;
			return y->m == z->m && y->b <= z->b; // min: reverse it
		}
		auto x = prev(y);
		if (z == end()) return y->m == x->m && y->b <= x->b; // min: reverse it
		return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m); // beware overflow!
	}
	void insert_line(ll m, ll b) {
		auto y = insert({ m, b });
		y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
		if (bad(y)) { erase(y); return; }
		while (next(y) != end() && bad(next(y))) erase(next(y));
		while (y != begin() && bad(prev(y))) erase(prev(y));
	}
	ll eval(ll x) {
		auto l = *lower_bound((Line) { x, is_query });
		return l.m * x + l.b;
	}
};

int n,t,j,i,k;

int main(){
	return 0;
}
