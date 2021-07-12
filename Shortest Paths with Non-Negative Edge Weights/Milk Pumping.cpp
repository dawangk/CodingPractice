#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug cout<<"HERE"<<endl;
#define ell "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pi, int> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e3+5; int mod = 1e9+7;//998244353

int n, m; vtrip adj[MM];

int dij(int flow){
    priority_queue<pi>q;
    q.push({0, 1});
    vi dist (n+3, INF);
    vector<bool> v (n+3, false);
    dist[1] = 0;
    while(!q.empty()){
        int cur = q.top().s; q.pop();
        if(v[cur])continue;
        v[cur] = true;
        for(auto x: adj[cur]){
            int b = x.f.f, cost = x.f.s, curflow = x.s;
            if(curflow<flow)continue;
            if(dist[cur]+cost<dist[b]){
                dist[b] = dist[cur]+cost;
                q.push({-dist[b], b});
            }
        }
    }
    return dist[n];
}

int main(){
    inputJunk
    freopen("pump.in","r", stdin);
    freopen("pump.out","w", stdout);
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b, c, d; cin>>a>>b>>c>>d;
        adj[a].pb({{b, c}, d});
        adj[b].pb({{a, c}, d});
    }
    int ans = -1;
    for(int i = 1;i<=1000;i++){
        int dists = dij(i);
        if(dists==INF)continue;
        int finals = (i*1000000)/dists;
        if(finals>ans)ans = finals;
    }
    cout<<ans<<ell;
}
/*CUSTOM TEST CASE 1
*/

/*CUSTOM TEST CASE 2
*/

/*CUSTOM TEST CASE 3
*/

/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iteratorsf
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
- INF setting problems
- push vs pb
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
