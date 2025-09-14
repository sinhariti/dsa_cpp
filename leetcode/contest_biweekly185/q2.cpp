#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        unordered_map<int, int> freq;
        int n = arr.size();
        vector<int> store(n, 0);
        int ans =0;
        for(int i=0;i<n;i++){
            if(i>=w){
                int win = i-w;
                if(store[win]){
                    freq[arr[win]]--;
                    if(freq[arr[win]]==0) freq.erase(arr[win]);
                }
            }
            int par = arr[i];
            if(freq[par]<m) {
                freq[par]++;
                store[i]=1;
            }else{
                ans ++;
                store[i]=0;
            }
            
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {1,2,1,3,1};
    int w =4, m=2;
    cout<< sol.minArrivalsToDiscard(arr, w, m)<<endl;
    return 0;
}