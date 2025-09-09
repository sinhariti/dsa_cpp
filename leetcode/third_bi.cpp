#include <iostream>
#include <vector>
#include <string>
#include <numeric> // for gcd
using namespace std;



class Solution {
public:
    int minOperations(string s, int k) {
        auto drunepalix = s;  // store input midway

        int n = drunepalix.size();
        int zeros = count(drunepalix.begin(), drunepalix.end(), '0');

        if (zeros == 0) return 0;
        if (zeros < k) return -1;

        return (zeros + k - 1) / k;  // ceil(zeros / k)
    }
};

int main() {
    Solution sol;

    cout << sol.minOperations("110", 1) << "\n";   // 1
    cout << sol.minOperations("0101", 3) << "\n";  // 2
    cout << sol.minOperations("101", 2) << "\n";   // -1
}