//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
  int n,m,k; cin>> n>> m>> k;
  vector<bool> anime(n+1, 0);
  vector<int> shop(n+1, -1);
  vector<int> res(n+1, 1e9);
  vector<vector<int> > adj(n+1);
  queue<int>q;
  for(int i=0; i<k; i++){
    int num ; cin>> num;
    anime[num] = 1;
    shop[num] = num;
    q.push(num);
  }
  for(int i=1;i<=m;i++){
    int x,y; cin>> x>> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(int newn : adj[node]){
      if(shop[newn]== -1){
        shop[newn] = shop[node]+1;
        q.push(newn);
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(!anime[i]){
      res[i] = shop[i];
    }else{
      int ans = 1e9;
      for(int newn : adj[i]){
        if(shop[newn] != -1){
          ans = min(ans , shop[newn]+1);
        }
      }
      if(ans != 1e9) res[i] = ans;
      else res[i] = -1;
    }
  }
  for(int i=1;i<=n;i++){
    cout<<res[i]<<" ";
  }
  return 0;
}