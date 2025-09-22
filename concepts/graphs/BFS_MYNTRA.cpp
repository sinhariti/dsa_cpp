#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Use the standard namespace for cleaner code.
using namespace std;

pair<int, int> bfs(int first, int n, const vector<vector<int>>& adj) {
    vector<int> far(n + 1, -1);
    queue<int> q;


    far[first] = 0;
    q.push(first);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (far[v] == -1) {

                far[v] = far[u] + 1;
                q.push(v);
            }
        }
    }


    int last = first;
    int maxi = 0;
    for (int i = 1; i <= n; ++i) {
        if (far[i] > maxi) {
            maxi = far[i];
            last = i;
        }
    }
    
    return {last, maxi};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if (n <= 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, int> firstres = bfs(1, n, adj);
    int endin = firstres.first;

    pair<int, int> secondres = bfs(endin, n, adj);
    int dia = secondres.second;

    // Print the final result.
    cout << dia << endl;

    return 0;
}