#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
void solve() {
    long long n, d;
    cin >> n >> d;
    queue<pair<long long, int>> q;
    unordered_map<long long, int> arr;


    q.push({n, 0});
    arr[n] = 0;

    while (!q.empty()) {
        long long curr_n = q.front().first;
        int steps = q.front().second;
        q.pop();


        if (curr_n == 1) {
            cout << steps << endl;
            return;
        }

        if (steps > 100) continue;


        if (curr_n % 2 == 0) {
            long long next_n = curr_n / 2;

            if (arr.find(next_n) == arr.end()) {
                arr[next_n] = steps + 1;
                q.push({next_n, steps + 1});
            }
        }
        long long next_n = curr_n - d;
        if (next_n >= 1) {

            if (arr.find(next_n) == arr.end()) {
                arr[next_n] = steps + 1;
                q.push({next_n, steps + 1});
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}