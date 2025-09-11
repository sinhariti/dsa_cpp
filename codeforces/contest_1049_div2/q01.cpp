//
#include <iostream>
using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin>>t;

  while(t-->0){
    int ans =0;
    int n ; cin>> n;
    string s; cin>>s;
    int count = 0;
    int lasto = 0;
    for(int i=0;i<n;i++){
      if(s[i]=='1') { count++;}

    }
    int diff = n-count;
    for(int i=0;i<diff;i++){
      if(s[i]=='1') ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}