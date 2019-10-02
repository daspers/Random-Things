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

// TIP: For large value, you can compress it or do some mapping
class OrderStatisticTree{
    int max_val;
    vector<int> bit;
    OrderStatisticTree(int _max_val){
        max_val = _max_val;
        bit.assign(max_val + 1, 0);
    }
    void update(int i, int add){
        for(;i > 0 && i < bit.size();i += i & (-i))
            bit[i] += add;
    }
    int sum(int i){
        int ans = 0;
        for(;i>0;i -= i & (-i))
            ans += bit[i];
        return ans;
    }
    int lower_bound(int value){
		int sum = 0;
		int pos = 0;
		int LOGN = ceil(log2(max_val+1));
		for(int i=1<<LOGN; i>0; i>>=1){
			if(pos + i <= max_val && sum + bit[pos + i] < value){
				sum += bit[pos + i];
				pos += i;
			}
		}
		return pos + 1;
	}
    int select_rank(int rank){
        return lower_bound(rank);
    }
    void insert(int x) {
        update(x, 1);
    }
    void remove(int x) {
        update(x, -1);
    }
    int find_rank(int val){
        return sum(val);
    }
};

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