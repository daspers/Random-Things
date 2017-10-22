//Find the max length of palindromic subsequence
//Max string length = 1000

#include <bits/stdc++.h>
using namespace std;
 
int t,n,k,m,i,j,x,y,dp[1005][1005], sg[1005][1005];
string s;

int findpal(int a, int b){
	if(a==b)
		return 1;
	else if(a>b)
		return 0;
	if(dp[a][b]==-1){
		if(s[a]==s[b])
			dp[a][b] = findpal(a+1,b-1)+2;
		else
			dp[a][b] = max(findpal(a+1,b), findpal(a,b-1));
	}
	return dp[a][b];
}

int main()
{
	cin>>s;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", findpal(0, s.size()-1));
	return 0;
}
