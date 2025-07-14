#include <iostream>
#include <vector>
#include <string>
using namespace std;

string buildCenteredLine(const vector<string>& words, int width) {
    int totalChars = 0;
    for (const string& word : words) totalChars += word.length();

    int totalGaps = words.size() + 1; // gaps: left + between words + right
    int totalSpaces = width - totalChars;

    int spacePerGap = totalSpaces / totalGaps;
    int extraSpaces = totalSpaces % totalGaps;

    string line = "*";
    line += string(spacePerGap + (extraSpaces-- > 0 ? 1 : 0), ' '); // left pad

    for (int i = 0; i < words.size(); ++i) {
        line += words[i];
        if (i != words.size() - 1) {
            line += string(spacePerGap + (extraSpaces-- > 0 ? 1 : 0), ' ');
        }
    }

    line += string(spacePerGap + (extraSpaces-- > 0 ? 1 : 0), ' '); // right pad
    line += "*";

    return line;
}

vector<vector<string>> formatCenteredText(const vector<vector<string>>& paragraphs, int width) {
    vector<vector<string>> result;
    string border(width + 2, '*');
    result.push_back({border});

    for (const auto& para : paragraphs) {
        vector<string> line;
        int currLen = 0;

        for (const string& word : para) {
            int extra = line.empty() ? 0 : line.size(); // assume at least 1 space between
            if (currLen + word.size() + extra >= width) {
                result.push_back({buildCenteredLine(line, width)});
                line.clear();
                currLen = 0;
            }
            line.push_back(word);
            currLen += word.size();
        }

        if (!line.empty()) {
            result.push_back({buildCenteredLine(line, width)});
        }
    }

    result.push_back({border});
    return result;
}

int main() {
    vector<vector<string>> words = {
        {"hello", "world"},
        { "I","am","newspaper"},
        {"edits"},
        {"this", "is", "a", "test"},
        {"what", "up"}
    };

    int width = 16;
    vector<vector<string>> output = formatCenteredText(words, width);

    for (auto& line : output)
        cout << line[0] << endl;

    return 0;
}