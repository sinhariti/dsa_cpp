//
#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
  int t; cin>> t;
  while(t--){
    int n ; cin>> n;
    vector<ll> arr(n);
    vector<ll> even, odd;
    vector<ll> res;
    for(int i=0;i<n;i++) {
      cin>>arr[i];
      if(arr[i]%2==0){
        even.push_back(arr[i]);
      }else{
        odd.push_back(arr[i]);
      }
    }
    if(even.empty() || odd.empty()){
      for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
      }
      cout<< endl;
      continue;
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    
    int o = even.size();
    int m = odd.size();
    int i=0, j=0;
    while(i<o && j<m){
      if(even[i]< odd[j]){
        res.push_back(even[i]);
        i++;
      }else{
        res.push_back(odd[j]);
        j++;  
      }
    }
    while(i<o){
      res.push_back(even[i]);
      i++;
    }
    while(j<m){
      res.push_back(odd[j]);
      j++;
    }
    for(int i=0;i<n;i++){
      cout<< res[i]<<" ";
    }
    cout<< endl;
  }
  return 0;
}