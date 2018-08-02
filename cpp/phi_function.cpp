#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define Nmax 300000 

typedef long long ll;
typedef complex<long double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int phi(int val){
	int ans = val;
	for(int i=2;i*i<=val;++i){
		if(val%i==0){
			do{
				val/=i;
			}while(val%i==0);
			ans -= ans/i;
		}
	}
	if(val>1){
		ans -= ans/val;
	}
	return ans;
}

int main(){
	
	return 0;
}