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
const int MM = 3e5+5; int mod = 1e9+7;//99824435

int n, m; vi adj[MM];
bool comp[MM], v[MM]; vi tp; string s;
int dist[30][MM];
int ans = 0;

bool dfs(int cur){
    v[cur] = true;comp[cur] = true;
    for(int x: adj[cur]){
        if(!comp[x]&&!v[x]){
            if(!dfs(x))return false;
        }else if(comp[x]){
            cout<<-1<<ell;
            return false;
        }
    }
    tp.pb(cur);
    comp[cur] = false;
    return true;
}

int main(){
    inputJunk
    cin>>n>>m>>s;
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
    }

    for(int i = 1;i<=n;i++){
        if(!v[i]){
            if(!dfs(i))return 0;
        }
    }

    reverse(all(tp));

    ans = 1;
    for(char c = 'a'; c<='z'; c++){
        int ind = c-'a';
        for(int i = 0;i<n;i++){
            int cur = tp[i];
            if(s[cur-1]==c)dist[ind][cur]++;
            if(dist[ind][cur]>ans)ans = dist[ind][cur];
            for(auto x: adj[cur]){
                //cout<<c<<" "<<cur<<" "<<x<<ell;
                dist[ind][x]=max(dist[ind][x],dist[ind][cur]);
                //cout<<ind<<" "<<x<<" "<<cur<<" "<<dist[ind][cur]<<ell;
                if(ans<dist[ind][x])ans = dist[ind][x];
            }
        }
    }
   // for(int i = 1;i<=n;i++){
    //    cout<<dist[0][i];
    //}
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
