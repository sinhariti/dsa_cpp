/**
 * This is a classic path–minimization problem:

Given a string of moves L, R, U, D, find the shortest equivalent path (cancel out opposite directions).

Example:
	•	Input: LDRRLRUULR
	•	You count:
	•	L = 3
	•	R = 4
	•	U = 2
	•	D = 1
	•	Cancel opposites:
	•	Left vs Right → min(L,R) cancels
	•	Up vs Down → min(U,D) cancels
	•	Build the minimized path using the remaining moves.
 * 
 */
#include <iostream>

using namespace std;


int main(){
  string s ; cin>> s;
  string ans ;
  int l=0, r=0,u=0, d=0;

  for(auto i:s){
    if(i=='L') l++;
    else if (i=='R') r++;
    else if (i=='U') u++;
    else if (i=='D') d++;

  }
  int h = min(l,r);
  int v = min(u,d);
  ans += string(h, 'L');
  ans += string(v, 'L');
  return 0;
}