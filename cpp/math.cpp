#include <bits/stdc++.h>

using namespace std;

/* O(SQRT(N)) */
/* Algorithm
	phi(N) = N * product_of(1-1/prime_factor)
*/
ll totient_func(ll val){
	ll sq = sqrtl(val);
	ll ans = val;
	for(ll i=2;val>1&&i<=sq;++i){
		if(val%i==0){
			ans -= ans/i;
			do{
				val/=i;
			}while(val%i==0);
		}
	}
	if(val>1)
		ans -= ans/val;
	return ans;
}

/* O(logN) */
ll binex(ll base, ll exp, ll mod){
	ll ans = 1;
	for(ll val=base%mod;exp;exp>>=1){
		if(exp&1)
			ans = ans*val%mod;
		val = val*val%mod;
	}
	return ans;
}

int main(){
	return 0;
}