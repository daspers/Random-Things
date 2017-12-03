#include <bits/stdc++.h>

using namespace std;
 
int a,b,c,i,t;
 
int main(){
	puts("Invers Modulo");
	puts("Format : AX (mod B) = C (mod B)");
	printf("Input A : "); scanf("%d", &a);
	printf("Input B : "); scanf("%d", &b);
	printf("Input C : "); scanf("%d", &c);
	t = a%b;
	for(i = 1; t*i%b!=c && i<b;i++);
	if(i==b)
		printf("No X exist such that %dX (mod %d) = %d (mod %d)\n", a,b,c,b);
	else
		printf("\nX = %d\n", i);
	return 0;
}
