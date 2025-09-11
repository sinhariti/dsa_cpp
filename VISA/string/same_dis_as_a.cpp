/*
Given string str of size N consisting of lowercase English alphabets, the task is to encode the given string as follows:

change every character of that string to another character
the distance between the changed character and the current character is the same as the distance between the current character and 'a'.
Also, assume that the character's array forms a cycle, i.e. after 'z' the cycle starts again from 'a'.
*/

#include <iostream>

using namespace std;

int main(){

  string s ; cin>> s;
  string ans ;
  for(auto c: s){
    int dist = c-'a';
    if(dist + (c-'a') >= 26){
      dist = (dist + (c-'a'))%26;
      ans += ('a'+ dist);
    }else{
      ans += (c+ dist);
    }
  }
  cout<<ans<< endl;
  return 0;
}