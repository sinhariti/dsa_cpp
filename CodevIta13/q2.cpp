#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define d double
#define f first
#define s second
#define pb push_back
#define mpi map<int, int>
#define umpi unordered_map<int, int>

ll power(int a , int b){
    int result = 1;
    while(b>0){
        if(b%2 == 1) result*=a;
        a*=a;
        b/=2;
    }
    return result;
}

static inline d calcarea(const vector<pair<d,d>>& p){
    int n = (int)p.size();
    long d s = 0.0L;
    for(int i=0;i<n;i++){
        int j = (i+1)%n;
        s += (long d)p[i].first * p[j].second - (long d)p[j].first * p[i].second;
    }
    return fabsl(s) * 0.5L;
}

static inline d calcperi(const vector<pair<d,d>>& p){
    int n = (int)p.size();
    long d per = 0.0L;
    for(int i=0;i<n;i++){
        int j = (i+1)%n;
        per += fabsl((long d)p[i].first - p[j].first) + fabsl((long d)p[i].second - p[j].second);
    }
    return (d)per;
}

void solve(){
    int n; if(!(cin >> n)) return;

    vector<pair<d,d>> pts(n);
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        pts[i] = {d(x), d(y)};
    }
    d A0 = calcarea(pts);
    d P  = calcperi(pts);
    d maxh = 1e18;
    for(int i=0;i<n;i++){
        int j = (i+1)%n;
        d L = fabs(pts[i].first - pts[j].first) + fabs(pts[i].second - pts[j].second);
        maxh = min(maxh, (L - 0.1)/2.0);
    }
    if(maxh < 0) { cout << fixed << setprecision(2) << 0.00; return; }

    int steps = (int)floor(maxh*10.0 + 1e-9);
    d best = 0.0;
    for(int k=0;k<=steps;k++){
        d H = k * 0.1;
        d A = A0 - P*H + 4.0*H*H; 
        if(A < 0) A = 0;         
        d V = H * A;
        if(V > best) best = V;
    }

    cout<<fixed<<setprecision(2)<<best+1e-9;
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt","w", stdout);
// #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) solve();
    return 0;
}