#include <iostream>
#include <algorithm>
 
using namespace std;
 
void mult(int *x, long m, long &s, long a){
	unsigned int p=0, t, y;
	for(long i=0;i<s;i++){
		t=x[i];
		t*=a;
		y=t+p;
		p=y/10;
		y%=10;
		x[i]=y;
		if(i==s-1 && p>0)
			s++;
	}
}
 
int main(){
	long n, s=1, max_size=1000;
	cin>>n;
	int *x= new int[max_size];
	fill_n(x, max_size, 0);
	x[0]=1;
	for(long i=2;i<=n;i++){
		mult(x, max_size, s, i);
	}
	for(long i=s-1;i>=0;i--){
		cout<<x[i];
	}
	cout<<endl;
	delete[] x;
	return 0;
}
