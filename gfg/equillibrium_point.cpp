#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        if(arr.size()<3) return -1;
        /*
        arr = [-7, 1, 5, 2, -4, 3, 0]
        pre = [0,-7,-6,-1, 1, -3, 0, 0]
        
        arr = [1, 2, 0, 3]
        pre = [0,1, 3, 5, 8]
        
        arr = [1,2,1,0,3,1]
        pre = [0,1,3,4,4,7,8]
        */
        vector<int> pre (arr.size()+1, 0);
        for(int i=0;i< arr.size();i++){
            pre[i+1] = pre[i] + arr[i];
        }
        for(int i=1;i<arr.size();i++){
            int l = pre[i];
            int r = pre[arr.size()] - pre[i];
            if(l==r){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    cout << obj.findEquilibrium(arr) << endl;
    return 0;
}
