//
#include <iostream>
#include <vector>

using namespace std;
// class Solution {
// public:
//     vector<int> minDifference(int n, int k) {
//         vector<int>fac;
//         vector<int> ans(k,1);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
//         int copy =n;
//         for(int i=0;i<k;i++) q.push({1,i});
//         for(int i=2;i*i<=copy;i++){
//             while(copy%i == 0){
//                 fac.push_back(i);
//                 copy/=i;
//             }
//         }
//         if(copy>1) fac.push_back(copy);
        
//         for(int i=fac.size()-1;i>=0;i--){
//             int val = q.top().first;
//             int ind = q.top().second;
//             q.pop();
//             val*=fac[i]; //balancing the factors
//             ans[ind]=val;
//             q.push({val,ind});
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> op;
    long long opti = LLONG_MAX;
    void calldfs(vector<int>& fac,vector<int>& ans,  int ind, int k){
        if(ind== fac.size()){
            // int mini = INT_MAX, maxi = INT_MIN;
            // for(int n :ans){
            //     maxi= max(maxi, n);
            //     mini= min(mini, n);
            // }
            long long mini = *min_element(ans.begin(), ans.end());
            long long maxi = *max_element(ans.begin(), ans.end());
            long long diff = maxi-mini;
            if(diff<opti){
                opti = diff;
                op = ans;
            }
            return ;
        }
        for(int i=0;i<k;i++){

            ans[i] *= fac[ind];
            calldfs(fac, ans, ind + 1, k);
            ans[i] /= fac[ind];
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int>fac;
        vector<int> ans(k,1);
        int copy = n;
        for(int i=2;i*i<=copy;i++){
            while(copy%i == 0){
                fac.push_back(i);
                copy/=i;
            }
        }
        if(copy>1) fac.push_back(copy);
        sort(fac.rbegin(), fac.rend());
        op.clear();
        opti = LLONG_MAX;

        calldfs(fac, ans, 0, k);
        return op;
    }
};
int main(){
    Solution sol;
    int n,k;
    cin>>n>>k;
    vector<int> ans = sol.minDifference(n,k);
    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

