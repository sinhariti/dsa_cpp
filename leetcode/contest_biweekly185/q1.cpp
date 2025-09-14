#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    double avg (vector<int>& nums){
        double sum=0;
        double n = nums.size();
        for(auto i: nums){
            sum+=i;
        }
        return (sum/n);
    }
    int smallestAbsent(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double a = avg(nums);
        unordered_set<int>seen;
        for(int i: nums){
            if(i>0) seen.insert(i);
        }
        int first = static_cast<int>(floor(a)) + 1;
        if(first<1) first =1;
        while(true){
            if(seen.find(first)== seen.end()){
                return first;
            }
            first++;
        }
        return 1;
    }

};

int main(){
    Solution sol;
    vector<int> nums = {-34};
    cout<< sol.smallestAbsent(nums)<<endl;
    return 0;
}
