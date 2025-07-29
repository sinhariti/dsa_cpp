//DSU Union by rankkkk

#include <iostream>
#include <vector>
using namespace std;
class disjointset{
  private:
    vector<int> rank, par, size;
  public:
    disjointset(int n){
      rank.resize(n+1, 0);
      par.resize(n+1, 0);
      size.resize(n+1, 1);
      for(int i=0;i<=n;i++){
        par[i] = i; // initialise all nodes parent as themselves
      }
    }
    //path compression 
    int findupar(int node){
      if(node == par[node]){
        return node;
      }
      return par[node] = findupar(par[node]);
    }
    //union by RANK
    void unionr(int u, int v){
      int pu = par[u];
      int pv = par[v];
      if(pu== pv) return ;
      // if rank of pu is less than pv, then pu->pv
      // there is no change in rank
      if(rank[pu] < rank[pv]){
        par[pu] = pv;
      }else if(rank[pu] > rank[pv]){
        par[pv] = pu;
        // pv->pu
      }else{
        par[pv] = pu;
        rank[pu]++;
      }
    }

    // union by size
    void unions(int u, int v){
      int pu = findupar(u);
      int pv = findupar(v);
      if(pv== pu) return ;
      if(size[pu] < size[pv]){
        par[pu] = pv;
        size[pv] += size[pu];
      }else{
        par[pv] = pu;
        size[pu] += size[pv];
      }
    }
};

int main(){
  disjointset ds (7);
  ds.unions(1,2);
  ds.unions(2,3);
  ds.unions(4,5);
  ds.unions(6,7);
  ds.unions(5,6);
  // check if 3 and 7 belong to the same component or not 
  if(ds.findupar(3) == ds.findupar(7)){
    cout<<"same\n";
  }else{
    cout<<"not same\n";
  }
  ds.unions(3,7);
  if(ds.findupar(3) == ds.findupar(7)){
    cout<<"same\n";
  }else{
    cout<<"not same\n";
  }
  
  return 0;
}