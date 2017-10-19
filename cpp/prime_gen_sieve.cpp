//Generating prime using sieve of erastoteles
//Limit Input : 664579
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull n,i,j,s,t;
bool *a;

int main (){
	scanf("%llu", &n);
	a = new bool [10000010];
	while(a==NULL)
		a = new bool [10000010];
	memset(a, true, 10000010*sizeof(bool));
	a[0]=a[1]=false;
	for(i=2,s=0;s<n;i++){
		if(a[i]){
			t = i*i;
			while(t<10000001){
				a[t] = false;
				t+=i;
			}
			s++;
		}
	}
	for(i=0,j=0;i<=1e7&&j<s;i++){
		if(a[i]){
			printf("%llu\n", i);
			j++;
		}
	}
	//printf("%llu\n",s);
	delete[] a;
	return 0;
}
