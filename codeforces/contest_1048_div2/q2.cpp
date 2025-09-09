//
/*
Maple wants to bake some cakes for Chocola and Vanilla.

One day, she discovers 𝑛
 magical cake ovens. The 𝑖
-th oven bakes 𝑎𝑖
 cakes every second. The cakes remain in their respective ovens until they are collected.

At the end of each second, she may teleport to any oven (including the one she is currently at) and collect all the cakes that have accumulated in that oven up to that point.

Your task is to determine the maximum number of cakes Maple can collect in 𝑚
 seconds.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛≤105
, 1≤𝑚≤108
) — the number of magical ovens and the number of seconds during which Maple will collect cakes.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤105
) — the number of cakes the 𝑖
-th oven bakes every second.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer representing the maximum number of cakes Maple can collect in 𝑚
 seconds.

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Oven {
    long long cakes;     // current cached cakes
    int idx;             // which oven
    long long lastTime;  // when this value was computed
    bool operator<(const Oven &o) const {
        return cakes < o.cakes; // max-heap
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> rate(n);
        for (int i = 0; i < n; i++) cin >> rate[i];

        // priority queue of ovens
        priority_queue<Oven> pq;
        for (int i = 0; i < n; i++) {
            pq.push(Oven{rate[i], i, 0});  // after 1 sec, each oven has rate[i]
        }

        long long ans = 0;
        for (long long time = 1; time <= m; time++) {
            Oven top = pq.top();
            pq.pop();

            // recompute cakes for this oven lazily
            long long actual = (time - top.lastTime) * rate[top.idx];
            ans += actual;

            // reset oven: now it’s empty at "time"
            pq.push(Oven{rate[top.idx], top.idx, time});
        }

        cout << ans << "\n";
    }
    return 0;
}