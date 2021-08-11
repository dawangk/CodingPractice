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
const int MM = 1e5+5; int mod = 1e9+7;//99824435

int n, m, deg[MM]; vpi adj[MM];
bool v[MM], comp[MM];
vi tp;

bool dfs(int cur, int lim){
    v[cur] = true; comp[cur] = true;
    //cout<<cur<<" "<<lim<<endl;
   //for(int i = 1;i<=n;i++){cout<<v[i]<<" ";}
   //cout<<ell;
    for(auto x: adj[cur]){
        if(x.s<=lim){
            if(comp[x.f])return false;
            else if(!v[x.f]){
                if(!dfs(x.f, lim))return false;
            }
        }
    }
    comp[cur] = false;
    return true;
}

bool valid(int lim){
    for(int i = 1;i<=n;i++){
        v[i] = false;comp[i] = false;
    }
    for(int i = n;i>=1;i--){
        if(!v[i]){
            if(!dfs(i, lim))return false;
        }
    }
    return true;
}

void findtp(int num){
    priority_queue<int> q;
    for(int i = 1;i<=n;i++){
        for(auto x: adj[i]){
            if(x.s<=num){
                deg[x.f]++;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(!deg[i]){
            q.push(-i);
        }
    }
    while(!q.empty()){
        int cur = -q.top(); q.pop();
        tp.pb(cur);
        for(auto x: adj[cur]){
            if(x.s<=num){
                deg[x.f]--;
                if(!deg[x.f])
                    q.push(-x.f);
            }
        }
    }
}

int main(){
    inputJunk
    freopen("milkorder.in","r", stdin);
    freopen("milkorder.out","w", stdout);
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a; cin>>a;
        vi stuff;
        for(int j = 0;j<a;j++){
            int b; cin>>b;
            stuff.pb(b);
        }
        for(int j = 0;j<a-1;j++){
            adj[stuff[j]].pb({stuff[j+1], i+1});
            //cout<<stuff[j]<<" "<<stuff[j+1]<<" "<<i+1<<endl;
        }
    }
    int lo = 0, hi = m;
    while(lo<hi){
        int mid = (lo+hi+1)/2;
        if(valid(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    valid(lo);
    reverse(all(tp));

    findtp(lo);
   // cout<<tp.size()<<endl;
    assert(tp.size()==n);
    for(int i = 0;i<tp.size();i++){
        cout<<tp[i];
        if(i!=n-1)cout<<" ";
    }cout<<ell;
}
/*CUSTOM TEST CASE 1
10 4
3 6 10 3
4 10 9 2 3
3 9 7 8
4 10 7 9 5
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
