//
#include <iostream>
#include <vector>
#include <tuple>
#include <set>
using namespace std;
struct product{
  string name;
  int price;
  int weight;
  // product(string n , int p, int w){
  //   name =n;
  //   price =p;
  //   weight = w;
  // }
  bool operator <(const product &p) const{
    if(this->name != p.name) return (this->name < p.name);
    if(this->price!= p.price) return (this->price< p.price);
    return this->weight < p.weight ;
  }
};

int main(){
  int n; cin>> n;
  int ans =0;
  vector<product> list(n) ; 
  set<product> view;
  for(int i=0;i<n;i++) cin>>list[i].name;
  for(int i=0;i<n;i++) cin>>list[i].price;
  for(int i=0;i<n;i++) cin>>list[i].weight;

  for(auto &it : list){
    if(view.count(it)>0) ans++;
    else view.insert(it);
  }
  cout<< ans<<endl;
  return 0;
}