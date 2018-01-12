#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll combin(ll a, ll b){
  b = min(b, a-b);
  ll r =1;
  for(ll i=1;i<=b;i++){
    r *= a;
    r /= i;
  }
  return r;
}

int main(){
  
  return 0;
}
