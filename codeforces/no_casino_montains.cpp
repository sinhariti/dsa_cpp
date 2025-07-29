#include <iostream>
#include <vector>
using namespace std;


int main(){
  int t; cin>> t;
  while(t-- >0){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto& x: a) cin>>x;

    int rain =0;
    int ans =0;
    for(int i=0;i<k ;i++){
      if(a[i]==1) rain++;
    }

    int l=0;
    while(l+k<=n){
      if(rain==0){
        ans++;
        l+=k+1;
        rain =0;
        for(int i=l;i<l+k;i++){
          if(a[i]==1) rain++;
        }
      }else{
        if(a[l]==1) rain--;
        if(l+k<n && a[l+k]==1) rain++;
        l++;
      }
    }
    cout<< ans<<'\n';

  }
  return 0;
}