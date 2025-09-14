#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> arr=nums;
        vector<long long> ans(32, 0);
        for(long long i: arr){
            for(int j=31;j>=0;j--){
                if(!(i & (1LL<<j))) continue;
                if(!ans[j]){
                    ans[j]^=i;
                    break;
                }
                i ^= ans[j];
            }
        }
        long long fin = 0;
        for(int j=31;j>=0;j--){
            if ((fin ^ ans[j]) > fin) {
                fin ^= ans[j];
            }
        }
        return (int)fin;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    cout<< sol.maxXorSubsequences(nums)<<endl;
    return 0;
}