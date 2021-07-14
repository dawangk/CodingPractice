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

const ll INF = 1e16+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;//998244353

ll n, m, dist[MM], numways[MM], minmoves[MM], maxmoves[MM]; vpll adj[MM];
bool v[MM];

int main(){
    inputJunk
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b, c; cin>>a>>b>>c;
        adj[a].pb({b, c});
    }
    for(int i = 0;i<=n;i++){dist[i] = INF;
        numways[i] = 0;
        minmoves[i] = 0;
        maxmoves[i] = 0;
    }
    priority_queue<pair<ll, pair<ll, ll>>> q;
    q.push({0, {1, 0}});
    dist[1] = 0; numways[1] = 1;
    while(!q.empty()){
        ll cur = q.top().s.f, step = q.top().s.s;q.pop();
        //cout<<cur<<" "<<step<<endl;
        if(v[cur])continue;
        v[cur] = true;
        for(auto x: adj[cur]){
            ll b = x.f, w = x.s;
            if(dist[cur]+w<dist[b]){
                 dist[b] = dist[cur]+w;
                 numways[b] = numways[cur];
                 minmoves[b] = minmoves[cur]+1;
                 maxmoves[b] = maxmoves[cur]+1;
                 q.push({-dist[b], {b, step+1}});
            }else if(dist[cur]+w==dist[b]){
                numways[b]+=numways[cur]; numways[b]%=mod;
                minmoves[b] = min(minmoves[cur]+1, minmoves[b]);
                maxmoves[b] = max(maxmoves[cur]+1, maxmoves[b]);
                q.push({-dist[b], {b, step+1}});
            }
        }
    }
    cout<<dist[n]<<" "<<numways[n]<<" "<<minmoves[n]<<" "<<maxmoves[n]<<ell;

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
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
