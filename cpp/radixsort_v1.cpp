//radix sort
//My implementation based on observing the radix sort animation
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

ll n, arr[1000006], pos[1000006], neg[1000006];
ll ps, ns;

void radix(ll base=10){
	queue<ll> q[base+1];
	ll max = 0, md=0, div;
	//sort positive
	if(ps>1){
		md = 0;
		max = *max_element(pos, pos+ps);
		while(max>0){
			md++;
			max/=base;
		}
		div=1;
		for(ll i=1;i<=md;i++){
			for(ll j=0;j<ps;j++){
				ll temp = pos[j]/div;
				temp %= base;
				q[temp].push(pos[j]);
			}
			for(ll j=0,k=0;j<base;j++){
				while(!q[j].empty()){
					pos[k++] = q[j].front();
					q[j].pop();
				}
			}
			div *= base;
		}
	}
	//sort negative
	if(ns>1){
		md = 0;
		max = *max_element(neg, neg+ns);
		while(max>0){
			md++;
			max/=base;
		}
		div=1;
		for(ll i=1;i<=md;i++){
			for(ll j=0;j<ns;j++){
				ll temp = neg[j]/div;
				temp %= base;
				q[temp].push(neg[j]);
			}
			for(ll j=0,k=0;j<base;j++){
				while(!q[j].empty()){
					neg[k++] = q[j].front();
					q[j].pop();
				}
			}
			div *= base;
		}
	}
	//append the ans to arr
	ll k =0;
	for(ll i=ns-1;i>=0;i--)
		arr[k++] = ~neg[i]+1;
	for(ll i=0;i<ps;i++)
		arr[k++] = pos[i];
}

int main(){
	//cout<<"Input the number of data to be sorted (max : 1e6) : ";
	cin>>n;
	//cout<<"Input the data (constraint : -2e18<=data<=2e18 :\n";
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	ps=ns=0;
	for(ll i=0;i<n;i++){
		if(arr[i]<0)
			neg[ns++] = ~arr[i]+1;
		else
			pos[ps++] = arr[i];
	}
	radix(10);
	/*
	for(ll i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	*/
	return 0;
}
