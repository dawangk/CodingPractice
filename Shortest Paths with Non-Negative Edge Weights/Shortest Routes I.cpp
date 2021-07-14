#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define debug cout<<"HERE"<<endl;
#define ell "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
 
const ll INF = 1e15+1;
const int MM = 1e5+5, mod = 1e9+7;
 
ll n, m, dis[MM]; vector<pi> adj[MM];bool v[MM];
 
int main(){
    inputJunk
    //freopen("closing.in","r", stdin);
    //freopen("closing.out","w", stdout);
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b, c;cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    memset(dis,INF, sizeof(dis));
    priority_queue<pair<ll, ll>> q;
 
    q.push({0, 1});dis[1] = 0;
    while(!q.empty()){
        ll cur = q.top().s; q.pop();
        if(v[cur])continue;
        v[cur] = true;
 
        for(auto x:adj[cur]){
            ll to = x.f, w = x.s;
            if(dis[to]>dis[cur]+w){
                dis[to] = dis[cur]+w;
                q.push({-dis[to], to});
            }
        }
    }
 
    for(int i = 1;i<=n;i++){
        cout<<dis[i]<<" ";
    }cout<<ell;
 
}
