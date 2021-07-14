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
const int MM = 5e4+5; int mod = 1e9+7;//998244353

int n, m, k, dist[MM];vpi adj[MM], bales;

void dij(int start){
    for(int i = 0;i<=n;i++){
        dist[i] = INF;
    }
    vector<bool> v(n+5, false);
    dist[start] = 0;
    priority_queue<pi> q;
    q.push({0,start});
    while(!q.empty()){
        int cur = q.top().s;
        q.pop();

        if(v[cur])continue;
        v[cur] = true;
        for(auto x: adj[cur]){
            int b = x.f, w = x.s;
            if(dist[cur]+w<dist[b]){
                dist[b]= dist[cur]+w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main(){
    inputJunk
    freopen("dining.in","r", stdin);
    freopen("dining.out","w", stdout);
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        int a, b, c; cin>>a>>b>>c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    for(int i = 0;i<k;i++){
        int a, b;
        cin>>a>>b; bales.pb({a, b});
    }
    dij(n);
    vi dist2;dist2.pb(0);
    for(int i = 1;i<=n;i++){
        dist2.pb(dist[i]);
    }
    adj[n].clear();
    bool valid = false;
    for(auto x: bales){
        int b = x.f, w = x.s;
        adj[n].pb({b, dist[b]-w});
        valid = valid||(dist[b]*2-w<=0);
    }

    dij(n);

    for(int i = 1;i<n;i++){
        //cout<<dist[i]<<" "<<dist2[i]<<endl;
        if(dist[i]<=dist2[i]||valid)cout<<1<<ell;
        else cout<<0<<ell;
    }
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
