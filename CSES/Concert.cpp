/*
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print -1.
1 \le n, m \le 2 \cdot 10^5
1 \le h_i, t_i \le 10^9
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
  int n, m; cin>> n>> m;
  vector<int>a(n);
  vector<int>t(m);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<m;i++){
    cin>>t[i];
  }

  sort(a.begin(), a.end());

  

  return 0;
}