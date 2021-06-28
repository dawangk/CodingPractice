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
const int MM = 2e5+5; int mod = 1e9+7;//998244353

int n, m, dist[MM]; vector<int> adj[MM];
int dp[MM]; bool used[MM];

void dfs(int cur){
    used[cur] = true;
    dp[cur] = dist[cur];
    for(int x: adj[cur]){
        if(!used[x]&&dist[cur]<dist[x]){
            dfs(x);
        }
        if(dist[cur]<dist[x]){
            dp[cur] = min(dp[cur], dp[x]);
        }else{
            dp[cur] = min(dp[cur], dist[x]);
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 0;i<MM;i++){
        adj[i].clear();
    }
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
    }
    memset(dist, -1, sizeof(dist));
    memset(dp, 0, sizeof(dp));
    memset(used, false, sizeof(used));
    queue<int> q;
    q.push(1);dist[1] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int x: adj[cur]){
            if(dist[x]==-1){
                dist[x] = dist[cur]+1;
                q.push(x);
            }
        }
    }

    dfs(1);

    for(int i = 1;i<=n;i++){
        cout<<dp[i]<<" ";
    }cout<<ell;
}

int main(){
    inputJunk
    int t; cin>>t;
    while(t--){
        solve();
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
- upperbound and lowerbound returns iterators
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
