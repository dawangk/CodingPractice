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

int n, m; vi edge[MM], adj[26];
string arr[105];
bool v[26], comp[26];
vi tp;
bool dfs(int cur){
    v[cur] = true; comp[cur]  =true;
    for(int x: adj[cur]){
        if(comp[x]){cout<<"Impossible"<<ell;return false;}
        else if(!v[x])if(!dfs(x))return false;
    }
    comp[cur] = false;
    tp.pb(cur);
    return true;
}

int main(){
    inputJunk
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n-1;i++){
        int ind = 0;
        while(ind<arr[i].size()&&ind<arr[i+1].size()&&arr[i][ind]==arr[i+1][ind]){
            ind++;
        }
        if(ind<arr[i].size()&&ind<arr[i+1].size())
            adj[arr[i][ind]-'a'].pb(arr[i+1][ind]-'a');
        else if(arr[i].size()>arr[i+1].size()){
            cout<<"Impossible"<<ell;
            return 0;
        }
    }

    for(int i = 0;i<26;i++){
        if(!v[i])if(!dfs(i))return 0;
    }
    reverse(all(tp));

    for(int i = 0;i<tp.size();i++){
        cout<<(char)(tp[i]+'a');
    }cout<<ell;
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
