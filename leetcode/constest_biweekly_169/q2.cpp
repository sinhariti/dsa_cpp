#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(n);
        unordered_map<int, int> pre;
        pre[0] =1;
        int presum =0;
        int res=0;
        
        for(int i=0;i<n;i++){
            arr[i] = (nums[i] == target ? 1:-1);
        }
        
        for(int i: arr){
            presum += i;
        }

        for(int i=0;i<n;i++){
            int ctar =0;
            int len =0;
            for(int j=0;j<n;j++){
                len ++;
                if(nums[j] == target){
                    ctar++;
                }
                if(2*ctar > len)
                    res++;
            }
        }
        return res;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> nums = {1,2,3,2,2};
        int target = 2;
        cout << countMajoritySubarrays(nums, target) << "\n";
        return 0;
    }
};