#include <bits/stdc++.h>
using namespace std;
//#include <ext/rope>
//using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <stdlib.h>
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

const int INF = 1e9+1212;
const ll INFL = 1e18+1221;
const ll P = 9973, M = 1e9+9;
const int MM = 20; int mod = 998244353;//1e9+7

ll n, hh, h[MM], w[MM], s[MM], sum[1<<MM], sumw[1<<MM], dp[1<<MM], ans = -1;

int main(){
    inputJunk
    freopen("guard.in","r", stdin);
   freopen("guard.out","w", stdout);
    cin>>n>>hh;
    for(int i = 0;i<n;i++){
        cin>>h[i]>>w[i]>>s[i];
    }
    for(int mask = 0;mask<(1<<n);mask++){
        for(int i = 0;i<n;i++){
            if((1<<i)&mask){
                sum[mask] = h[i]+sum[mask-(1<<i)];
                sumw[mask] = w[i]+sum[mask-(1<<i)];
                break;
            }
        }
    }
    dp[0] = INFL;
    for(int mask = 1;mask<(1<<n);mask++){
        dp[mask] = -19;
        for(int i = 0;i<n;i++){
            if((1<<i)&mask){
                dp[mask] = max(min(dp[mask-(1<<i)]-w[i], s[i]), dp[mask]);
            }
        }
        if(sum[mask]>=hh){
            ans = max(ans, dp[mask]);
        }
    }
    if(ans==-1)cout<<"Mark is too tall"<<ell;
    else cout<<ans<<ell;
}
/*CUSTOM TEST CASE 1
20 931551327
47960483 94256016 936549689
23634711 69258315 801530355
25432157 10839535 671918027
89506163 4794085 425547791
34475201 66437617 609045131
44926465 56191007 964602056
17521172 31187662 38711495
78931211 84822015 397713398
78231806 50905522 398930945
61458830 33451910 793979387
83021935 3395839 861218331
22554218 50568195 412935177
28669466 55937269 509962054
53918807 68636826 433655076
51885742 43915823 545621061
51439353 30945216 651391961
36526633 93505814 120623679
78207053 53654495 99234462
55821281 19580678 28594374
55213066 23573737 224053014



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
