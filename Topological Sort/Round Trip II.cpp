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

int n, m; vi adj[MM];
bool v[MM], contain[MM];stack<int> s;
bool f = false;

void dfs(int cur){
    //cout<<cur<<endl;
    v[cur] = true; s.push(cur);contain[cur] = true;
    for(int x: adj[cur]){
        if(v[x]&&contain[x]){
            vi ans;
            ans.pb(x);
            while(s.top()!=x){
                ans.pb(s.top());
                s.pop();
            }
            ans.pb(s.top());
            reverse(all(ans));
            cout<<ans.size()<<ell;
            for(int x: ans){
                cout<<x<<" ";
            }cout<<ell;
            f=true;
            return;
        }else if(!v[x]){
            dfs(x);
        }
        if(f) return;
    }
    if(f) return;
    s.pop();
    contain[cur] = false;
}


int main(){
    inputJunk
    int n, m; cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
    }

    for(int i  =1;i<=n;i++){
        if(!v[i]){dfs(i);}
        if(f) break;
    }
    if(!f){cout<<"IMPOSSIBLE"<<ell;}
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
