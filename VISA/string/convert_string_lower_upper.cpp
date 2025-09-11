/*
Given an array of strings, perform operations based on string length:
Even length: Convert to lowercase.
Odd length: Transform each character to its next alphabet (e.g., 'a' → 'b', 'z' → 'a').

 */

 #include <iostream>
 #include <string>

 using namespace std;

int main(){
  string s; cin>> s;
  string ans ;
  int n = s.length();
  for(auto c: s){
      ans += tolower(c);
  }
  if(n%2==0){
    cout<<ans<<endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    int o = s[i]-'a';
    if(s[i]=='z') o=0;
    else o++;
    ans[i]= o+'a';
  }
  cout<< ans<<endl;

  return 0;
 }