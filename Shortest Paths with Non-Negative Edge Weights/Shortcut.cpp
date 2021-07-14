#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
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

const ll INF = 1e17+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e4+5; int mod = 1e9+7;//998244353

ll n;
ll m, t, arr[MM], dist[MM], numcows[MM]; vpll adj[MM]; vll adj2[MM];
bool v[MM];

int dfs(int cur){
    v[cur] = true;
    ll ans = arr[cur];
    for(int x: adj2[cur]){
        if(!v[x]){ans+=dfs(x);}
    }
    return numcows[cur] = ans;
}

void dij(int start){
    for(int i = 0;i<=n;i++){dist[i] = INF; v[i] = false;}

    priority_queue<pair<ll, pll>> q;
    dist[start] = 0;
    q.push({0, {start, -1}});

    while(!q.empty()){
        ll cur = q.top().s.f, pre = q.top().s.s; q.pop();
        if(v[cur])continue;

        v[cur] = true;
        if(pre!=-1){adj2[cur].pb(pre); adj2[pre].pb(cur);}
        for(auto x: adj[cur]){
            ll b = x.f, w = x.s;
            if(dist[cur]+w<dist[b]){
                dist[b] = dist[cur]+w;
                q.push({-dist[b], {b,cur}});
            }
        }
    }
}

int main(){
    inputJunk
    freopen("shortcut.in","r", stdin);
    freopen("shortcut.out","w", stdout);
    cin>>n>>m>>t;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<m;i++){
        ll a, b, c; cin>>a>>b>>c;
        adj[a].pb({b,c}); adj[b].pb({a,c});
    }
    dij(1);
    for(int i=1;i<=n;i++){
        v[i] = false;
    }
    dfs(1);
    ll ans = 0;
    //cout<<oldsum<<endl;
    for(int i = 1;i<=n;i++){
        //cout<<numcows[i]<<" "<<dist[i]<<endl;
        //cout<<numcows[i]*(dist[i]-t)<<endl;
        ans = max(ans, numcows[i]*(dist[i]-t));
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
- check if things are used properly
- read the PROBLEM (directed vs undirected graph)
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
