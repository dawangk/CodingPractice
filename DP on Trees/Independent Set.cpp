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

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;//99824435

int n; ll black[MM], white[MM]; vi adj[MM];

ll add(ll a, ll b){
    return (a+b)%mod;
}

ll mult(ll a, ll b){
    return (a*b)%mod;
}

void dfs(int cur, int pre){
    for(int x: adj[cur]){
        if(x==pre)continue;
        dfs(x, cur);
        white[cur] = mult(white[cur], add(white[x],black[x]));
        black[cur] = mult(black[cur], white[x]);
    }
}

int main(){
    inputJunk
    cin>>n;
    for(int i= 0;i<n-1;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }

    for(int i = 1;i<=n;i++){
        black[i] = 1;
        white[i] = 1;
    }

    dfs(1, -1);
    cout<<add(white[1],black[1])<<ell;
}
/*CUSTOM TEST CASE 1
3 2
1 3
2 4
5 0
3 5
6 4
2 1
*/

/*CUSTOM TEST CASE 2
4 1
1 0
3 2
5 0
2 1
0 3
1 2
5 5
4 1
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
