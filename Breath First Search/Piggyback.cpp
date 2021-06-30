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
const int MM = 4e4+5; int mod = 1e9+7;//998244353

int b, e, p, n, m; vi adj[MM];
int distb[MM], diste[MM], distdest[MM];



int main(){
    inputJunk
    freopen("piggyback.in","r", stdin);
    freopen("piggyback.out","w", stdout);
    cin>>b>>e>>p>>n>>m;
    for(int i= 0;i<m;i++){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);adj[b].pb(a);
    }
    memset(distb, -1, sizeof(distb));
    memset(diste, -1, sizeof(diste));
    memset(distdest, -1, sizeof(distdest));
    queue<int> q;
    q.push(1); distb[1] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int x: adj[cur]){
            if(distb[x]==-1){
                q.push(x);
                distb[x] = distb[cur]+1;
            }
        }
    }
    q.push(2); diste[2] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int x: adj[cur]){
            if(diste[x]==-1){
                q.push(x);
                diste[x] = diste[cur]+1;
            }
        }
    }

    q.push(n); distdest[n] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int x: adj[cur]){
            if(distdest[x]==-1){
                q.push(x);
                distdest[x] = distdest[cur]+1;
            }
        }
    }

    int ans = b*distdest[1]+e*distdest[2];

    for(int i = 1;i<=n;i++){
        //cout<<i<<" "<<distb[i]<<" "<<b<<" "<<diste[i]<<" "<<e<<" "<<distdest[i]<<" "<<p<<ell;
        ans = min(ans, distb[i]*b+diste[i]*e+distdest[i]*p);
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
