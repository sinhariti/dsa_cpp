#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pack {
    int arr;
    int pack;
    int vip;
    int index;
};



struct prior {
    bool operator()(const pack& a, const pack& b) {
        if (a.vip != b.vip) { 
            return a.vip < b.vip;  
        }
        return a.arr > b.arr; 
    }
};

int main() {
    int N;
    cin >> N;
    
    vector<pack> package(N);
    priority_queue<pack, vector<pack>, prior> wait;
    int currtime = 0;
    int index = 0;
    vector<pair<int,int>> resarr;
    vector<pair<int,int>> events;


    for (int i = 0; i < N; i++) {
        cin >> package[i].arr >> package[i].pack >> package[i].vip;
        package[i].index = i;
    }

    sort(package.begin(), package.end(), [](const pack& a, const pack& b) {
        return a.arr < b.arr;
    });
    
    
    while (index < N || !wait.empty()) {
        while (index < N && package[index].arr <= currtime) {
            wait.push(package[index]);
            index++;
        }
        
        if (wait.empty()) {
            currtime = package[index].arr;
            continue;
        }
    
        pack currpack = wait.top();
        wait.pop();
        
        int st = max(currtime, currpack.arr);
        int end = st + currpack.pack;
        resarr.push_back({currpack.arr, st});
        currtime = end;
    }
    for (auto& res : resarr) {
        int arr = res.first;
        int start = res.second;
        if (arr < start) { 
            events.push_back({arr, 1});  
            events.push_back({start, -1});   
        }
    }
    sort(events.begin(), events.end());
    
    int ans = 0;
    int curr = 0;
    for (auto& event: events) {
        curr += event.second;
        if (event.second == 1) {  
            if (curr > ans) {
                ans= curr;
            }
        }
    }
    cout << ans ;
    
    return 0;
}