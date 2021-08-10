#include <bits/stdc++.h>
using namespace std;
//#include <ext/rope>
//using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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
typedef pair<int, pi> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;
typedef vector<tripll> vtripll;

const ll INF = 1e17+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;//99824435

int n, m, dist[MM], mm[MM]; vi adj[MM], adj2[MM];
bool v[MM];vi tp;

void dfs(int cur){
    v[cur] = true;
    for(int x: adj[cur]){
        if(!v[x]){
            dfs(x);
        }
    }
    tp.pb(cur);
}

int main(){
    inputJunk
    int n, m; cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);adj2[b].pb(a);
    }

    for(int i  =1;i<=n;i++){
        if(!v[i]){dfs(i);}
    }
    reverse(all(tp));
    dist[1] = 1;
    for(int i = 0;i<n;i++){
        for (int x: adj2[tp[i]]){
            if(dist[x]==0)continue;
            if(dist[tp[i]]<dist[x]+1){
                mm[tp[i]] = x;
                dist[tp[i]] = dist[x]+1;
            }
        }
    }
    if(mm[n]==0){cout<<"IMPOSSIBLE"<<ell;return 0;}
    cout<<dist[n]<<ell;
    int cur = n;
    vi ans;
    while(mm[cur]!=0){
        ans.pb(cur);
        cur = mm[cur];
    }ans.pb(cur);
    reverse(all(ans));
    for(int x: ans){
        cout<<x<<" ";
    }cout<<ell;

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
