/*
  2[a]3[bc] -> aabcbcbc
  string(3,'bc') -> bcbcbcbc
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include<algorithm>
using namespace std;

string decodeString(string s){
  string ans ="";
  int n = 0;
  while(n<s.size()){
    if(isspace(s[n])){ n++; continue;}
    
    // if digit 
    int val=0;
    while(n<s.size() && isdigit(s[n])){
      val = val*10 + (s[n]-'0');
      n++;
    }
    if(s[n]=='[') {
      if(val==0) val=1;
      n++; 
    }
    string curr="";
    while(s[n]!=']'){
      curr+= s[n];
      n++;
    }
    if(s[n]==']') n++; 

    while(val--){
      ans+=curr;
    }

  }
  return ans;
}

int main(){
    vector<string> expressions = {
        "2[a]3[bc]",
        "[a]2[b]2[cd]",
    };

    for(string& s : expressions) {
        cout << s << " = " << decodeString(s) << endl;
    }
  return 0;
}