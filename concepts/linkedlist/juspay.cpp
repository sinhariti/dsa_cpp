#include <iostream>     // for cin, cout
#include <vector>       // for vector
#include <unordered_map>// for unordered_map
#include <algorithm>    // for sort

using namespace std;

long long sumPairwise(vector<int>& v) {
    sort(v.begin(), v.end());
    long long res = 0;
    int k = v.size();
    for (int i = 0; i < k; i++) {
        res += 1LL * v[i] * (2LL * i - k + 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> rowMap, colMap;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int type;
            cin >> type;
            rowMap[type].push_back(i);
            colMap[type].push_back(j);
        }
    }

    long long ans = 0;
    for (auto &it : rowMap) {
        ans += sumPairwise(it.second);
    }
    for (auto &it : colMap) {
        ans += sumPairwise(it.second);
    }

    cout << ans << "\n";
    return 0;
}