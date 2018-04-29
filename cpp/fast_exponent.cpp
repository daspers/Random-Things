#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e10;
const ll N = 61;

ll a,b,r,c,p[N+2], n[N+2],i;

int main(){
	scanf("%lld %lld", &a, &b);
	a%=mod;
	c = b;
	for(i=0;i<N;i++){
		p[i] = c&1;
		c>>=1;
	}
	for(n[0]=a, i=1;i<N;i++)
		n[i] = (n[i-1]*n[i-1])%mod;
	for(r=1,i=0;i<N;i++)
		if(p[i])
			r=(r*n[i]) % mod;
	printf("%lld\n", r);
	return 0;
}
