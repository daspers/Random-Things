#include <bits/stdc++.h>

//restriction mod>n and mod is prime

using namespace std;

typedef long long ll;

ll const mod = 1e9+7;

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
T combin(T a, T b, T mod){
	if(a==b||b==0)
		return 1;
	T r = (ifact[a-b]*ifact[b])%mod;
	r *= fact[a];
	return r%mod;
}

int main(){
	cin >> n >> m >> mod;
	memset(inver, -1, sizeof inver);
	inver[1] = 1;
	genfact(mod);
	cout<<combin(n, m, mod)<<endl;
}
