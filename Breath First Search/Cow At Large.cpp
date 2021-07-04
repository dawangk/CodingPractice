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
const int MM = 1e5+5; int mod = 1e9+7;//998244353

int n, start, deg[MM], dist[MM], leaf[MM], parent[MM]; vi adj[MM];

void dfs(int cur, int val){
    dist[cur] = val;
    for(int x: adj[cur]){
        if(dist[x]==-1){
            dfs(x, val+1);
            parent[x] = cur;
        }
    }
}

void bfs(int start){
    queue<pi> q;
    q.push({start, 0});
    while(!q.empty()){
        int cur = q.front().f, d=  q.front().s; q.pop();
        leaf[cur] = min(leaf[cur], d);
        for(int x: adj[cur]){
            if(leaf[x]<=d)continue;
            q.push({x, d+1});
        }
    }
}

int main(){
    inputJunk
    freopen("atlarge.in","r", stdin);
    freopen("atlarge.out","w", stdout);
    cin>>n>>start;
    for(int i = 0;i<n-1;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);deg[a]++;
        adj[b].pb(a);deg[b]++;
    }
    memset(dist, -1, sizeof(dist));
    for(int i = 1;i<=n;i++)leaf[i] = INF;
    dfs(start, 0);
    for(int i = 1;i<=n;i++){
        if(deg[i]==1){
            bfs(i);
        }
    }

    int ans = 0;
    /*
    for(int i = 1;i<=n;i++){
        cout<<dist[i]<<" ";
    }cout<<ell;
    for(int i = 1;i<=n;i++){
        cout<<leaf[i]<<" ";
    }cout<<ell;
    for(int i = 1;i<=n;i++){
        cout<<parent[i]<<" ";
    }cout<<ell;*/
    for(int i = 1;i<=n;i++){
        if(i==start)continue;
        else{
            if(dist[parent[i]]<leaf[parent[i]]&&dist[i]>=leaf[i]){
                ans++;
            }
        }
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
