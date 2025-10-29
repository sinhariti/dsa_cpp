#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
  int tes; cin >> tes;
  while (tes--)
  {
    int n;
    string s, t;
    cin >>n >>s >> t;
    
    unordered_map<char, int> fs;
    for (char c : s)
      fs[c]++;
    
    bool check= true;
    for (char c : t){
      if (fs.find(c)== fs.end()){
        cout << "NO" << endl;
        check = false;
        break;
      }
      else{
        fs[c]--;
        if(fs[c]== 0){
          fs.erase(c);
        }
      }
    }
    if (check && fs.empty()){
      cout << "YES" << endl;
    }
    else if (check) {
      cout << "NO" << endl;
    }
  }
  return 0;
}