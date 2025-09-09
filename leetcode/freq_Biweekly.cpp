#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s = to_string(n);
        int ans=9;
        int least=INT_MAX;
        unordered_map<char, int>mapp;
        for(char c: s){
            mapp[c]++;
        }
        for(auto it: mapp){
            int c = it.first -'0';
            int freq = it.second;
            if(freq<least){
                least = freq;
                ans = c;
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    int n;
    cin>>n;
    cout<<sol.getLeastFrequentDigit(n)<<endl;
    return 0;
}
