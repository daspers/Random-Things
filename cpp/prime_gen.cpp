//Generating prime using some random algorithm that i thought
//Limit Input : 1e7
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull n, a[10000009],i,s,r,j;
bool b;

int main (){
	scanf("%llu", &n);
	a[0] = 2;
	a[1] = 3;
	s=2;
	for(i=5;s<n;i+=2){
		b=true;
		r = sqrt(i);
		for(j=1;a[j]<=r;j++){
			if(i%a[j]==0){
				b=false;
				break;
			}
		}
		if(b){
			a[s++] = i;
		}
	}
	for(i=0;i<n;i++){
		printf("%llu\n", a[i]);
	}
	return 0;
}
