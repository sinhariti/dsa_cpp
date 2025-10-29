//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
  int n, m, k; cin>> n>> m>> k;
  vector<int> a(n);
  vector<int>b(m);
  for(int i=0; i<n; i++){
    cin>> a[i];
  }
  sort(a.begin(), a.end());
  for(int i=0; i<m; i++){
    cin>> b[i];
  }
  sort(b.begin(), b.end());
  int i=0, j=0, ans=0;
  while(i<n && j<m){
    if(abs(a[i]-b[j]) <= k){
      ans++;
      i++;
      j++;
    }
    else if(a[i] < b[j]){
      i++;
    }
    else{
      j++;
    }
  }
  cout<< ans;
  return 0;
}