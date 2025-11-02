#include <bits/stdc++.h>
using namespace std;

int getValue(const string &s, unordered_map<string, int> &var) {
    try {
        return stoi(s); 
    } catch (...) { 
        return var[s]; 
    }
}





bool evaluateCondition(const string &con, unordered_map<string, int> &var) {
    regex pattern("([a-zA-Z0-9]+)(==|<|>)([a-zA-Z0-9]+)");
    smatch match;
    if (regex_search(con, match, pattern)) {
        int v1 = getValue(match[1], var);
        string op = match[2]; 
        int v2 = getValue(match[3], var);
        if (op == "==") return v1 == v2;   
        if (op == "<") return v1 < v2;
        if (op == ">") return v1 > v2;   
    }
    return false;
}

int matchend(int stind, vector<string> &lines) {
    int bal = 0;
    for (int i = stind; i < (int)lines.size(); i++) {
        string cmd = lines[i].substr(0, lines[i].find(' '));
        if (cmd == "if" || cmd == "for") bal++;
        else if (cmd == "end") { 
            bal--;
            if (bal == 0) return i;
        }
    }
    return -1;
}

int findMatchingNoOrEnd(int yesind, vector<string> &lines) {
    int bal = 0;
    for (int i = yesind; i < (int)lines.size(); i++) {
        string cmd = lines[i].substr(0, lines[i].find(' '));
        if (cmd == "if" || cmd == "for") bal++;
        else if (cmd == "end") {
            if (bal == 0) return i;
            bal--;
        } else if (cmd == "No" && bal == 0) {
            return i;
        }
    }
    return -1;
}




void execute(int stind, int endind, vector<string> &lines, unordered_map<string, int> &var) {
    int i = stind;
     
    while (i < endind) {
        string line = lines[i];
         
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        if (line.empty()) {
            i++;
            continue;   
        }
        stringstream ss(lines[i]);
        vector<string> parts;
        string token;
        while (ss >> token) parts.push_back(token);
        string command = parts[0];

        if (command == "print") {
            cout << getValue(parts[1], var) << "\n";
            i++;
        } 
        else if (command == "for") {
            string currn = parts[1];
            int start = getValue(parts[2], var);
            int end = getValue(parts[3], var);
            int endloop = matchend(i, lines);   
            for (int j = start; j <= end; j++) {
                var[currn] = j;
                execute(i + 1, endloop, lines, var);
            }

            var.erase(currn);
            i = endloop + 1;


        } 
        else if (command == "if") {
            bool con = evaluateCondition(parts[1], var);

            
            int yesb = i + 1;
            int noorend = findMatchingNoOrEnd(yesb, lines);
            bool hasnob = lines[noorend] == "No";
            int endind = hasnob ? matchend(i, lines) : noorend;
               
            if (con) 
                execute(yesb + 1, noorend, lines, var);
            else if (hasnob)
                execute(noorend + 1, endind, lines, var);
            i = endind + 1; 
        } 
        else i++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("input1.txt", "r", stdin);
    //     freopen("output1.txt", "w", stdout);
    // #endif



    vector<string> allip;
    string line;


    while (getline(cin, line)) allip.push_back(line);

    string valline = allip.back();
    allip.pop_back();
    string nlines = allip.back();
    allip.pop_back();
    vector<string> lines = allip;

    unordered_map<string, int> vari;
    stringstream ss1(nlines), ss2(valline);
    vector<string> varn;
    string name;
    while (ss1 >> name) varn.push_back(name);
    for (int i = 0; i < (int)varn.size(); i++) {
        string val; ss2 >> val;
        vari[varn[i]] = stoi(val);
    }

    execute(0, lines.size(), lines, vari);
    return 0;
}