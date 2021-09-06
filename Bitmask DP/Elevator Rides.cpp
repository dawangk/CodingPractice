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
//#define x real()
//#define y imag()

typedef long long ll;
typedef long double ld;
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
//typedef complex<ll> point;

const int INF = 1e9+1212;
const ll INFL = 1e18+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e6+5; int mod = 998244353;//1e9+7

int n, c,arr[22]; pi dp[1<<20];

pi cmp(pi a, pi b){
    if(a.f<b.f)return a;
    if(b.f<a.f)return b;
    if(a.f==b.f){
        return (a.s<b.s?a:b);
    }
}

int main(){
    cin>>n>>c;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int mask = 0; mask<(1<<n); mask++){dp[mask] = {INF,0};}
    dp[0] = {1, 0};
    //{# of elevators, weight of ppl in elevator}

    for(int mask = 0; mask<(1<<n); mask++){

        int cur = dp[mask].f, ppl = dp[mask].s;
    //cout<<mask<<" "<<cur<<" "<<ppl<<ell;
        for(int i = 0;i<n;i++){
            if(!(mask&(1<<i))){
                if(ppl+arr[i]<=c){
                    dp[mask^(1<<i)] = cmp(dp[mask^(1<<i)], {cur, ppl+arr[i]});
                }else{
                    dp[mask^(1<<i)] = cmp(dp[mask^(1<<i)], {cur+1, arr[i]});
                }
            }else{
                //cout<<mask<<" "<<i<<endl;
            }
        }
    }

    cout<<dp[(1<<n)-1].f;
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
