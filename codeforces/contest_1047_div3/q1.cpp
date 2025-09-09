/**
 * 
 * You are doing a research paper on the famous Collatz Conjecture. In your experiment, you start off with an integer 𝑥
, and you do the following procedure 𝑘
 times:

If 𝑥
 is even, divide 𝑥
 by 2
.
Otherwise, set 𝑥
 to 3⋅𝑥+1
.
For example, starting off with 21
 and doing the procedure 5
 times, you get 21→64→32→16→8→4
.

After all 𝑘
 iterations, you are left with the final value of 𝑥
. Unfortunately, you forgot the initial value. Please output any possible initial value of 𝑥
.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤400
). The description of the test cases follows.

The first line of each test case contains two integers 𝑘
 and 𝑥
 (1≤𝑘,𝑥≤20
).

Output
For each test case, print any possible initial value on a new line. It can be shown that the answer always exists.


 */
#include <iostream>
using namespace std;

int main() {
    long long n; 
    cin >> n;
    while (true) {
        cout << n;
        if (n == 1) break; 
        cout << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    cout << "\n";
    return 0;
}