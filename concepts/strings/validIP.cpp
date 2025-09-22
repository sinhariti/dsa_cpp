#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

bool isValidIPv4(string s) {
    // split by '.'
    vector<string> parts;
    stringstream ss(s);
    string token;
    while (getline(ss, token, '.')) {
        parts.push_back(token);
    }

    if (parts.size() != 4) return false;

    for (auto &p : parts) {
        // must not be empty
        if (p.empty()) return false;

        // check all digits
        for (char c : p) {
            if (!isdigit(c)) return false;
        }

        // convert to int
        int num = stoi(p);

        // check range
        if (num < 0 || num > 255) return false;
    }

    return true;
}
