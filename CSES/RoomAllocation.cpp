//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int t; cin>> t;
  vector<int>arr(t);
  vector<int> dep(t);
  vector<int> ans(t+1);
  for(int i=0;i<t;i++){
    cin>> arr[i] >> dep[i];
  }
  sort(arr.begin(), arr.end());
  sort(dep.begin(), dep.end());
  int i=0, j=0, count =0, maxi =0;
  while(i<t && j<t){
    if(arr[i]<= dep[j]){
      count++;
      ans[i] = count;
      maxi = max(maxi, count);
      i++;
      
    }else{
      count --;
      j++;
    }
  }
  cout<<maxi<<endl;
  for(int i=0;i<t;i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}