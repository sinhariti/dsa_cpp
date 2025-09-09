/**
 * 
 * Maple has two positive integers 𝑎
 and 𝑏
. She may perform the following operation any number of times (possibly zero) to make 𝑎
 equal to 𝑏
:

Choose any positive integer 𝑥
, and multiply either 𝑎
 or 𝑏
 by 𝑥
.
Your task is to determine the minimum number of operations required to make 𝑎
 equal to 𝑏
. It can be proven that this is always possible.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤100
). The description of the test cases follows.

The first and only line of each test case contains two positive integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤1000
) — the numbers Maple currently has.

Output
For each test case, output a single integer representing the minimum number of operations Maple needs to make 𝑎
 equal to 𝑏
.
 * 
 */
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
        }else if (a%b == 0 || b%a == 0) {
            cout << 1 << endl;
        }else {
          cout<<2<<endl;
        }
    }
    return 0;
}

