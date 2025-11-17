#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        set<int> saw;
        vector<int> arr(n);
        set<int> every(arr.begin(), arr.end());
        vector<bool> pre(n + 1, false), suff(n + 1, false);
        bool ops = 0;


        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        
        if (every.size() == n) {
            cout << "0\n";
            continue;  
        }

        
        
        pre[0] = true;
        for (int i = 0; i < n; i++) {
            if (saw.count(arr[i])) break;
            saw.insert(arr[i]);  
            pre[i + 1] = true;
        }
        
        saw.clear();
        suff[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            if (saw.count(arr[i])) break;
            saw.insert(arr[i]);
            suff[i] = true;
        }
        
        for (int k = 1; k < n; k++) {
            if (pre[k] && suff[k]) {
                ops = 1;
                break;
            }
        }
        
        if (ops) {
            cout << "1"<< endl;  
        } else {
            cout << "2"<< endl;  
        }
    }
    
    return 0;
}