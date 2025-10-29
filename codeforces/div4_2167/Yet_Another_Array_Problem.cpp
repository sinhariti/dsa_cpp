#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}
bool isp(ll n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin>> t;
  while(t--){
    int n ; cin>> n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>> arr[i];
    ll g = arr[0];
    for(int i=1;i<n;i++) g= gcd(g, arr[i]);

    if(g==1){
      cout<< "2\n";
      continue;
    }
    vector<ll> p;
    ll store = g;
    for(ll i=2;i*i<=store;i++){
      if(store%i ==0){
        p.push_back(i);
        while(store%i==0){
          store/=i;
        }
      }
    }
    if(store>1){
      p.push_back(store);
    }
    for(ll j = 2; j<=g+1 ;j++){
      if(!isp(j)) continue;
      bool check = true;
      for(int i=0;i<p.size();i++){
        if(j==p[i]){
          check = false;
          break;
        }
      }
      if(check){
        cout<< j << endl;
        break;
    }
  }
}
return 0;
}