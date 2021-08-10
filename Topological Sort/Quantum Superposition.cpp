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
const int MM = 1e3+5; int mod = 1e9+7;//99824435

int n, n1, m, m1; vi adj[MM], adj2[MM];
bool v[MM], v2[MM];vi tp, tp2;
set<int> re[MM], re2[MM];

void dfs(int cur){
    v[cur] = true;
    for(int x: adj[cur]){
        if(!v[x]){
            dfs(x);
        }
    }
    tp.pb(cur);
}

void dfs2(int cur){
    v2[cur] = true;
    for(int x: adj2[cur]){
        if(!v2[x]){
            dfs2(x);
        }
    }
    tp2.pb(cur);
}

int main(){
    inputJunk
    cin>>n>>n1>>m>>m1;
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
    }
    for(int i = 0;i<m1;i++){
        int a, b; cin>>a>>b;
        adj2[a].pb(b);
    }

    for(int i  =1;i<=n;i++){
        if(!v[i]){dfs(i);}
    }
    for(int i  =1;i<=n1;i++){
        if(!v2[i]){dfs2(i);}
    }
    reverse(all(tp));
    reverse(all(tp2));
    re[1].insert(0);re2[1].insert(0);
    for(int i = 0;i<n;i++){
        int cur = tp[i];
        for(int x: adj[cur]){
            for(int y: re[cur]){
                re[x].insert(y+1);
            }
        }
    }

    for(int i = 0;i<n1;i++){
        int cur = tp2[i];
        for(int x: adj2[cur]){
            for(int y: re2[cur]){
                re2[x].insert(y+1);
            }
        }
    }
    set<int> ree, ree2;
    for(int x: re[n])ree.insert(x);
    for(int x: re2[n1])ree2.insert(x);
    int q; cin>>q;
    for(int i = 0;i<q;i++){
        int a; cin>>a;
        bool f = true;
        for(int x: ree){
            //cout<<x<<ell;
            int findd = a-x;
            //cout<<" "<<findd<<ell;
            if(ree2.count(findd)){f = false;cout<<"Yes"<<ell;break;}
        }
        if(f)cout<<"No"<<ell;
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
