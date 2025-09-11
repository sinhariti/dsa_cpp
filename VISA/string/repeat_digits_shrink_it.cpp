/*
Given a number in string form, replace consecutive equal digits with their sum until no consecutive digits remain (e.g., "66644319333" → "26328").

*/


//
#include <iostream>
using namespace std;

string compress(string ans){
  int n= ans.size();
  string newans;
  int count =1;
  char prev = ans[0];

  for(int i=1;i<n;i++){
    if(prev == ans[i]){
      count ++ ;
    }else{
      int sum = count*(prev-'0');
      newans+= to_string(sum);
      prev = ans[i];
      count =1;
    }
  }
  int sum = count*(prev-'0');
  newans+= to_string(sum);
  return newans;

}
int main(){
  string s; cin>> s;
  string ans = s;
  bool done = true;

  while(done){
    ans = compress(ans);
    done = false;
    for(int i=1;i<ans.size();i++){
      if(ans[i] == ans[i-1]){
        done = true;
        break;
      }
    }
  }
  
  cout<< ans<<endl;
  return 0;
}