#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int, int> list;
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++){
            int other = tar-nums[i];
            if(list.find(other)!=list.end()){
                ans[0] = list[other];
                ans[1] = i;
            }else{
                list[nums[i]] = i;
            }
        }
        return ans;
    }
};
int main(){
  int n,tar;
  cin>>n>>tar;
  vector<int> nums(n);
  for(int i=0;i<n;i++) cin>>nums[i];
  Solution sol;
  vector<int> ans = sol.twoSum(nums,tar);
  cout<< ans[0]<<" "<<ans[1]<<endl;
  return 0;
}