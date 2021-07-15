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
const int MM = 1e5+5; int mod = 1e9+7;//99824435

ll n, m, k;vpll adj[MM];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;priority_queue<ll> stored[MM];

int main(){
    inputJunk
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        ll a, b, c; cin>>a>>b>>c;
        adj[a].pb({b, c});
    }

    stored[1].push(0);
    q.push({0,1});

    while(!q.empty()){
        ll cur = q.top().f, nod = q.top().s;q.pop();
        if(cur>stored[nod].top())continue;
        for(auto x: adj[nod]){
            ll b = x.f, w = x.s;
            ll newdist = cur+w;
            if(stored[b].size()<k){
                stored[b].push(newdist);
                q.push({newdist, b});
            }else if(newdist<stored[b].top()){
                stored[b].pop();
                stored[b].push(newdist);
                q.push({newdist, b});
            }
        }
    }
    vll ans;
    while(!stored[n].empty()){
        ans.pb(stored[n].top()); stored[n].pop();
    }
    reverse(all(ans));
    for(ll x: ans)cout<<x<<" ";
    cout<<ell;
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
