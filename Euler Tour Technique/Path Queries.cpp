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

ll n, q, arr[MM], newarr[MM], st[MM], en[MM];
vi adj[MM];
int timer = 0;

void dfs(int cur, int pre){

    st[cur] = timer++;
    for(int x: adj[cur]){
        if(x==pre)continue;
        dfs(x, cur);
    }
    en[cur] = timer-1;
}

void upd(int i, int v){
    for(;i<n;i|=i+1){
        //cout<<i<<ell;
        newarr[i]+=v;
    }
}

ll query(int i){
    ll ans = 0;
    for(;i;i&=i-1){
        ans+=newarr[i-1];
    }
    return ans;
}

int main(){
    cin>>n>>q;
    for(int i= 1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i= 0;i<n-1;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(1, -1);

    for(int i = 1;i<=n;i++){
        //debug
        upd(st[i], arr[i]);
        upd(en[i]+1, -arr[i]);
        //cout<<st[i]<<" "<<en[i]<<" "<<newarr[i]<<" "<<endl;
    }

    for(int i = 0;i<q;i++){
        int a, b; cin>>a>>b;
        if(a==1){
            int c; cin>>c;
            int delta = c-arr[b];
            upd(st[b], delta); upd(en[b]+1, -delta);
            arr[b] = c;
        }else{
            cout<<query(st[b]+1)<<ell;
        }
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
- check if things are used properly
- read the PROBLEM (directed vs undirected graph)
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
