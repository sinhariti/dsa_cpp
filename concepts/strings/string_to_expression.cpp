#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;
/**
"27az+2b-20c" 
should be calculated as 
27+2-20 = 9

"a+2b"
calcuated as 
1+2=3 

"28c+ 2bx * 4x"
28+2*4

BODMAS followed 28+8 = 36

"3c-4bnm*a"

3-4*1

first *
3-4=-1
 */
// Helper function to get precedence of operators
int precedence(char op) {
    if(op == '+'|| op == '-') return 1;
    if(op == '*'|| op == '/') return 2;
    return 0;
}

// Apply operator to two numbers
int apply(int a, int b, char op) {
    if(op == '+') return a+b;
    if(op == '-') return a-b;
    if(op == '*') return a*b;
    if(op == '/') return a/b;
    return 0;
}

// Evaluate expression string
int evaluateExpression(const string& s) {
    stack<int> nums;
    stack<char> ops;
    int i = 0;
    int n = s.size();

    while(i < n) {
        if(isspace(s[i])) {
            i++;
            continue;
        }

        // If it's a digit or implicit multiplication like 2ab
        if(isdigit(s[i])) {
            int val = 0;
            while(i < n && isdigit(s[i])) {
                val = val*10 + (s[i] - '0');
                i++;
            }
            // Handle implicit multiplication like 2ab
            while(i < n && isalpha(s[i])) {
                val *= 1;
                i++;
            }
            nums.push(val);
        }

        // If it's a variable like 'a', treat as 1
        else if(isalpha(s[i])) {
            nums.push(1);
            i++;
        }

        // If it's an operator
        else {
            while(!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                int b = nums.top(); 
                nums.pop();
                int a = nums.top(); 
                nums.pop();
                char op = ops.top(); 
                ops.pop();
                nums.push(apply(a, b, op));
            }
            ops.push(s[i]);
            i++;
        }
    }

    // Final evaluation
    while(!ops.empty()) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(apply(a, b, op));
    }

    return nums.top();
}

int main() {
    vector<string> expressions = {
        "27az+2b-20c",
        "a+2b",
        "28c+2bx*4x",
        "3c-4bnm*a",
        "a+b"
    };

    for(string& s : expressions) {
        cout << s << " = " << evaluateExpression(s) << endl;
    }

    return 0;
}