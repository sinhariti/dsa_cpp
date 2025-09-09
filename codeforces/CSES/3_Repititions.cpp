//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char c;
    int votes = 0;
    int maxi = 0;
    // Step 1: Boyer–Moore to find candidate
    for (char ch : s) {
        if (ch != c) {
            c = ch;
            votes = 0;
        } 
        if (c == ch) {votes++;}
        maxi= max(maxi,votes);
    }

    cout<< maxi<< endl;
}


// int main() {
//     string s;
//     char current;
//     int count = 0, answer = 0;
//     cin >> s;
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] != current) {
//             current = s[i];
//             count = 0;
//         }
//         if (s[i] == current) {
//             count++;
//         }
//         answer = max(answer, count);
//     }
//     cout << answer;
// }