#include <iostream>
#include <vector>
#include <string>
using namespace std;

string buildLine(vector<string>& words, int l, int r, int currLen, int maxWidth, bool isLastLine) {
    string line = "";
    int numWords = r - l + 1;
    int totalSpaces = maxWidth - currLen;

    if (numWords == 1 || isLastLine) {
        // Left align
        for (int i = l; i <= r; ++i) {
            line += words[i];
            if (i != r) line += " ";
        }
        line += string(maxWidth - line.length(), ' ');
    } else {
        int spacePerGap = totalSpaces / (numWords - 1);
        int extraSpaces = totalSpaces % (numWords - 1);

        for (int i = l; i <= r; ++i) {
            line += words[i];
            if (i != r) {
                int spaces = spacePerGap + (extraSpaces-- > 0 ? 1 : 0);
                line += string(spaces, ' ');
            }
        }
    }
    return line;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int l = 0;
    
    while (l < words.size()) {
        int r = l;
        int currLen = 0;

        // Find how many words fit in this line
        while (r < words.size() && currLen + words[r].length() + (r - l) <= maxWidth) {
            currLen += words[r].length();
            r++;
        }

        // Build the line from l to r-1
        bool isLastLine = (r == words.size());
        result.push_back(buildLine(words, l, r - 1, currLen, maxWidth, isLastLine));
        l = r;
    }

    return result;
}

int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> output = fullJustify(words, maxWidth);

    for (const string& line : output) {
        cout << '"' << line << '"' << endl;
    }
}