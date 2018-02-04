#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

ll coss[4], n, x;

//divide and conquer solution
ll recurse(ll n){
	if(n==0)
		return 1;
	if(n==1)
		return coss[3];
	if(n&1){
		return (2*recurse((n-1)/2)*recurse((n+1)/2)-coss[3])%mod;
	}
	else{
		ll t = recurse(n/2);
		return (2*t*t - 1) % mod;
	}
}

//itterative solution
ll itterative(ll n){
	coss[0] = 1;
	coss[1] = coss[3] = x;
	for(i=2;i<=t;i++){
		coss[2] = 2*coss[1]*coss[3] - coss[0];
		coss[2] %= mod;
		coss[0] = coss[1];
		coss[1] = coss[2];
	}
	return coss[1];
}

int main(){
	coss[3] = x;
	return 0;
}
