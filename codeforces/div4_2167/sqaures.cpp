//
#include <iostream>
using namespace std;


int main(){
  int t; cin>> t;
  while(t--){
    int s1, s2, s3, s4;
    cin>> s1 >> s2 >> s3 >> s4;
    if(s1 == s2 && s2 == s3 && s3 == s4){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}