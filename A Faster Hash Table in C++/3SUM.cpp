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
const int MM = 2e5+5; int mod = 1e9+7;//99824435

ll n, arr[5005], dp[5005][5005];

int main(){
    inputJunk
    freopen("threesum.in","r", stdin);
    freopen("threesum.out","w", stdout);
    int q;
    cin>>n>>q;
    for(int i= 0;i<n;i++){
        cin>>arr[i];
    }

    for(int i = 0;i<n;i++){
        gp_hash_table<int,int> g({},{},{},{},{1<<16});
        for(int j = i+1;j<n;j++){
            int want = -arr[i]-arr[j];
            if(g.find(want)!=g.end()){
                dp[i][j]+=g.find(want)->s;
            }
            g[arr[j]]++;
        }
    }
    for(int i = n-1;i>=0;i--){
        for(int j = i+1;j<n;j++){
            dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
        }
    }

    for(int i = 0;i<q;i++){
        int a, b; cin>>a>>b;a--;b--;
        cout<<dp[a][b]<<ell;
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
