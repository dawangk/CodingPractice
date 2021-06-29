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
typedef vector<int> vi;
typedef pair<int, int> pi;
 
const ull INF = 0x3f3f3f3f;
const int MM = 1e5+5, mod = 1e9+7;
 
int n, m, step[MM], pre[MM]; queue<int> q; vi adj[MM];
 
int main(){
    inputJunk
    //freopen("poopoo.in","r", stdin);
    //freopen("poopoo.out","w", stdout);
    memset(step, -1, sizeof(step));
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b;cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }
    q.push(1);
    step[1] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        //cout<<cur<<ell;
        for(int x: adj[cur]){
            if(step[x]==-1){
                q.push(x);
                pre[x] = cur;
                step[x] = step[cur]+1;
            }
        }
    }
 
    if(step[n] == -1){
        cout<<"IMPOSSIBLE"<<ell;
    }else{
        cout<<step[n]+1<<ell;
        vi ans; ans.pb(n);
        while(ans.back()!=1)ans.pb(pre[ans.back()]);
        reverse(ans.begin(), ans.end());
        for(int x: ans){
            cout<<x<<" ";
        }cout<<ell;
        //}
    }
 
}
