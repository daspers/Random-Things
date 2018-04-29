// Restriction : n and m are copprime to mod, mod is prime
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9+7;

ll n,i,j,k,t,m=1;
ll fact[100003], ifact[100003], inver[100003];

template<typename T>
T inverse(T val, T mod){
	val = val%mod;
	if(inver[val]==-1){
		inver[val] = (-mod/val*inverse(mod%val, mod))%mod;
		if(inver[val]<0)
			inver[val]+=mod;
	}
	return inver[val];
}

template<typename T>
void genfact(T mod){
	fact[0]=1;
	for(T i=1;i<=n;i++){
		fact[i]=(fact[i-1]*i)%mod;
	}
	ifact[0]=1;
	for(T i=1;i<=n;i++){
		ifact[i]=(ifact[i-1]*inverse(i, mod))%mod;
	}
}

template<typename T>
T factorial(T val, T mod){
	if(fact[val] == -1)
		fact[val] = (factorial(val-1, mod)*val)%mod;
	return fact[val];
}

template<typename T>
T ifactorial(T val, T mod){
	if(ifact[val] == -1)
		ifact[val] = (ifactorial(val-1, mod)*inverse(val, mod))%mod;
	return ifact[val];
}

template<typename T>
T combin(T a, T b, T mod){
	if(a==b||b==0)
		return 1;
	T r = (ifactorial(a-b, mod)*ifactorial(b, mod))%mod;
	r *= factorial(a, mod);
	return r%mod;
}

int main(){
	cin >> n >> m >> mod;
	memset(inver, -1, sizeof inver);
	inver[1] = 1;
	memset(fact, -1, sizeof fact);
	memset(ifact, -1, sizeof ifact);
	fact[0]=ifact[0]=1;
	cout<<combin(n, m, mod)<<endl;
}
