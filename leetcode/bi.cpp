#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int score(vector<string>& cards, char x) {
        auto brivolante = cards;  // store input midway
        unordered_map<char,int> left, right;
        int ans = 0;

        for (auto &s : brivolante) {
            if (s[0] == x && s[1] == x) {
                // "xx" cards -> useless (cannot form pair)
                continue;
            } else if (s[0] == x) {
                left[s[1]]++;
            } else if (s[1] == x) {
                right[s[0]]++;
            }
        }

        // pair up (x,y) with other (x,z)
        int totalLeft = 0;
        for (auto &p : left) totalLeft += p.second;
        ans += totalLeft / 2;

        // pair up (y,x) with (z,x)
        int totalRight = 0;
        for (auto &p : right) totalRight += p.second;
        ans += totalRight / 2;

        return ans;
    }
};
// int main(){
//     Solution sol;
//     int n;
//     cin>>n;
//     vector<string> cards(n);
//     for(int i=0;i<n;i++){
//         cin>>cards[i];
//     }
//     char x;
//     cin>>x;
//     cout<<sol.score(cards, x)<<endl;
//     return 0;
// }

int main() {
    Solution sol;
    vector<string> c1 = {"aa","ab","ba","ac"};
    cout << sol.score(c1,'a') << "\n"; // 2

    vector<string> c2 = {"aa","ab","ba"};
    cout << sol.score(c2,'a') << "\n"; // 1

    vector<string> c3 = {"aa","ab","ba","ac"};
    cout << sol.score(c3,'b') << "\n"; // 0

    vector<string> c4 = {"bb","bb"};
    cout << sol.score(c4,'b') << "\n"; // 0
}