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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pi, int> trip;
typedef pair<pll, ll> tripll;
 
 
 
const ll INF = 1e15+250;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;
 
ll n, m; vector<pll> adj[MM], adj2[MM]; ll dist[MM], dist2[MM]; bool v[MM]; vector<tripll> edge;
 
void dij(){
    for(int i = 1;i<=n;i++){
        dist[i] = INF;
        v[i] = false;
    }
    dist[1] = 0;
    priority_queue<pll> q;
    q.push({0,1});
 
    while(!q.empty()){
        ll cur = q.top().s;q.pop();
        if(v[cur])continue;
        v[cur] = true;
 
        for(auto x: adj[cur]){
            ll to = x.f, w = x.s;
            if(dist[to]>dist[cur]+w){
                dist[to] = dist[cur]+w;
                q.push({-dist[to], to});
            }
        }
    }
    //for(int i = 0;i<n;i++)cout<<dist[i]<<" ";
    //cout<<ell;
}
 
void dij2(){
    for(int i = 1;i<=n;i++){
        dist2[i] = INF;
        v[i] = false;
    }
    dist2[n] = 0;
    priority_queue<pll> q;
    q.push({0,n});
 
    while(!q.empty()){
        ll cur = q.top().s;q.pop();
        if(v[cur])continue;
        v[cur] = true;
 
        for(auto x: adj2[cur]){
            ll to = x.f, w = x.s;
            if(dist2[to]>dist2[cur]+w){
                dist2[to] = dist2[cur]+w;
                q.push({-dist2[to], to});
            }
        }
    }
   // for(int i = 0;i<n;i++)cout<<dist2[i]<<" ";
    //cout<<ell;
}
 
int main(){
    inputJunk
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        ll a, b, c; cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj2[b].pb({a,c});
        edge.pb({{a,b},c});
    }
 
    ll ans = INF;
 
    dij();dij2();
 
    for(auto x: edge){
        ll neww = (x.s/2);
        ll from = x.f.f, to = x.f.s;
        //cout<<from<<" "<<dij(1, from)<<" "<<to<<" "<<dij(to,n)<<" "<<neww<<ell;
        ans = min(ans, dist[from]+neww+dist2[to]);
    }
    cout<<ans<<ell;
 
}
/*CUSTOM TEST CASE 1
 
*/
 
/*CUSTOM TEST CASE 2
 
*/
 
/*CUSTOM TEST CASE 3
 
*/
 
//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);
