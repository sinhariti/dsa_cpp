#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class fentree {
    vector<int> bit;
public:
    fentree(int n) : bit(n + 1, 0) {}
    
    void newval(int idx, int delta) {
        idx++;
        while (idx < bit.size()) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }
    
    int query(int idx) { 
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};


    int countSubarraysWhereTargetIsMajority(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (nums[i] == tar) ? 1 : -1;
        }
        
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + arr[i];
        }
    
        vector<int> sortpre = pre;
        sort(sortpre.begin(), sortpre.end());
        sortpre.erase(unique(sortpre.begin(), sortpre.end()), sortpre.end());
        
        unordered_map<int, int> rankmap;
        for (int i = 0; i < sortpre.size(); i++) {
            rankmap[sortpre[i]] = i;
        }

        fentree bit(sortpre.size());
        bit.newval(rankmap[0], 1); 
        
        long long result = 0;
        for (int j = 0; j < n; j++) {
            int currpre = pre[j + 1];
            int rankcurr = rankmap[currpre];
    
            if (rankcurr > 0) {
                result += bit.query(rankcurr - 1);
            }

            bit.newval(rankcurr, 1);
        }
        
        return result;
    }


    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> nums = {1,2,2,3};
        int target = 2;
        cout << countSubarraysWhereTargetIsMajority(nums, target) << "\n";
        return 0;
    }
