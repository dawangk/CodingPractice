#include <bits/stdc++.h>
using namespace std;
//#include <ext/rope>
//using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <stdlib.h>
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
//#define x real()
//#define y imag()

typedef long long ll;
typedef long double ld;
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
typedef complex<ll> point;

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 2e5+5; int mod = 998244353;//1e9+7

int n, q, arr[MM], newarr[MM], bit[MM];
vpi d[MM];
vi adj[MM];
int ss[MM], ee[MM], timer = 0;

void dfs(int cur, int pre){
    ss[cur] = timer++;
    newarr[ss[cur]] = arr[cur-1];
    for(int x: adj[cur]){
        if(x==pre)continue;
        dfs(x, cur);
    }
    ee[cur] = timer-1;
}

void upd(int i, int val){
    for(;i<=n;i+=i&-i)
        bit[i]+=val;
}

int qry(int i){
    int ans = 0;
    for(;i;i-=i&-i)
        ans+=bit[i];
    return ans;
}

int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n-1;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(1, -1);
    for(int i = 1;i<=n;i++){
        int a = ss[i], b = ee[i];
        //cout<<a<<" "<<b<<ell;
        d[a+1].pb({b+1, i-1});
    }
    map<int, int> next;
    vi ans(n);
    for(int i = n;i>=1;i--){
        int cur = newarr[i-1];
        //cout<<cur<<ell;
        if(next.count(cur))upd(next[cur], -1);
        next[cur] = i;
       // debug
        upd(i, 1);
       // cout<<" "; debug
        for(auto x: d[i]){
            //cout<<x.f<<" "<<x.s<<endl;
            ans[x.s] = qry(x.f);
        }
    }
    for(int x: ans)cout<<x<<" ";cout<<ell;
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
