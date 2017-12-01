#include <bits/stdc++.h>

using namespace std;

#define Nmax 1000
#define dummyval 999999

// Segment tree with array representation
// minimum example

int a[Nmax], tree[4*Nmax], n,i,j,k,x,y;

void createsegtree(int l, int r, int pos){
	if(l==r){
		tree[pos] = a[l];
		return;
	}
	int mid = (l+r)/2;
	createsegtree(l, mid, 2*pos+1);
	createsegtree(mid+1, r, 2*pos+2);
	tree[pos] = min(tree[2*pos+1], tree[2*pos+2]); // can be change depend on problems
}

void updatesegtree(int l, int r, int pos, int in){ //update tree
	if(l>in||r<in)
		return;
	if(l==r){
		tree[pos]=a[l];
		return;
	}
	int mid = (l+r)/2;
	updatesegtree(l, mid, 2*pos+1, in);
	updatesegtree(mid+1, r, 2*pos+2, in);
	tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}

int result(int l, int r, int ql, int qr, int pos){ //get answer to the problem
	if(l>=ql && r<=qr)
		return tree[pos];
	if(r<ql || l > qr)
		return dummyval;
	int mid = (l+r)/2;
	return min(result(l,mid,ql,qr,2*pos+1), result(mid+1, r, ql, qr, 2*pos+2));
}

void printtree(int in, int h, int s){ // for debugging
	if(tree[in]==dummyval)
		return;
	for(int b=0;b<h;b++)
		printf(" ");
	printf("%d\n", tree[in]);
	printtree(2*in+1, h+s, s);
	printtree(2*in+2, h+s, s);
}

int main() {
    scanf("%d %d", &n, &k);
	for(i=0;i<n;i++)
		scanf("%d", a+i);
	for(i=0;i<4*n;i++)
		tree[i] = dummyval;
	createsegtree(0, n-1, 0);
	printtree(0, 0, 2);
	for(i=0;i<k;i++){
		scanf("%d %d", &x, &y);
		a[x-1]=y;
		updatesegtree(0,n-1,0,x-1);
		printtree(0, 0, 2);
	}
    return 0;
}
