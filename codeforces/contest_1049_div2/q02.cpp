//
#include <iostream>
#include <cmath>
#include <numeric> // for std::gcd
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int d = to_string(x).size();
        long long M = (long long)pow(10, d) - 1;
        long long g = gcd(x, M);
        long long y = M / g;  // this is always < 1e9
        cout << y << "\n";
    }
    return 0;
}