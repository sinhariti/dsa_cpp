#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int l = 0, r = x, ans = 0;
        
        while (l <= r) {
            int m = (l + r) / 2;

            vector<pair<int, int>> nota;
            for (int pos : arr) {
                nota.push_back({pos - m, pos + m});
            }
            sort(nota.begin(), nota.end());

            vector<pair<int, int>> merged;
            for (auto i : nota) {
                if (merged.empty() || i.first > merged.back().second) {
                    merged.push_back(i);
                } else {
                    merged.back().second = max(merged.back().second, i.second);
                }
            }
            
            long long flen = 0;
            for (auto i : merged) {
                int st = max(0, i.first);
                int e = min(x, i.second);
                if (e >= st) {
                    flen += (e - st + 1);
                }
            }

            long long aval = (x + 1) - flen;
            
            if (aval >= k) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        set<int> tele;
        vector<pair<int, int>> forbidden;
        for (int pos : arr) {
            forbidden.push_back({pos - ans, pos + ans});
        }
        
        sort(forbidden.begin(), forbidden.end());
        vector<pair<int, int>> merged;
        for (auto i : forbidden) {
            if (merged.empty() || i.first > merged.back().second) {
                merged.push_back(i);
            } else {
                merged.back().second = max(merged.back().second, i.second);
            }
        }
        
        vector<int> avalp;
        int current = 0;
        for (auto interval : merged) {
            int st = max(0, interval.first);
            int end = min(x, interval.second);

            while (current < st && current <= x) {
                avalp.push_back(current);
                current++;
            }

            current = end + 1;
        }

        while (current <= x) {
            avalp.push_back(current);
            current++;
        }
        

        for (int i = 0; i < min(k, (int)avalp.size()); i++) {
            tele.insert(avalp[i]);
        }

        int pos = 0;
        while (tele.size() < k) {
            if (tele.find(pos) == tele.end()) {
                tele.insert(pos);
            }
            pos++;
        }

        for (int tp : tele) {
            cout << tp << " ";
        }
        cout << endl;
    }
    
    return 0;
}