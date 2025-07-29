//
#include <iostream>
#include <set>
using namespace std;


int main(){
  int t; cin>> t;
  while(t-- >0){
    int n1;
    cin>> n1;
    int ans =1e9;
    while(n1>0){
      ans = min(ans, n1%10);
      n1/=10;
    }
    cout<<ans<<'\n';
  }
  return 0;
}