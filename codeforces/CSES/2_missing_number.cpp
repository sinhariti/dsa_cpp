//
#include <iostream>
using namespace std;


int main(){
  int n;
  cin>>n;
  int arr[n];
  int x =0;
  for(int i=0;i<n-1;i++){
    cin>>arr[i];
    x ^= arr[i];
  }
  for(int i=1;i<=n;i++){
    x ^= i;
  }
  cout<<x<<endl;
  return 0;
}