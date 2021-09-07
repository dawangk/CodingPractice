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
const int MM = 1e3+5; int mod = 1e9+9;//998244353

int n, m, d, arr1[MM], arr2[MM]; ll dp[MM][MM][15];

int main(){
    //freopen("team.in","r", stdin);
    //freopen("team.out","w", stdout);
    inputJunk

    cin>>n>>m>>d;
    for(int i = 1;i<=n;i++){
        cin>>arr1[i];
    }
    for(int i = 1;i<=m;i++){
        cin>>arr2[i];
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int k = 1;k<=d;k++){
                dp[i][j][k]+=dp[i][j-1][k];dp[i][j][k]%=mod;
                dp[i][j][k]+=dp[i-1][j][k];dp[i][j][k]%=mod;
                dp[i][j][k]-=dp[i-1][j-1][k]; if(dp[i][j][k]<0)dp[i][j][k]+=mod;
                if(arr1[i]>arr2[j]) {dp[i][j][k]+=dp[i-1][j-1][k-1]; dp[i][j][k]%=mod; if(k==1)dp[i][j][k]++;}
                //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
            }
        }
    }
    cout<<dp[n][m][d]<<endl;
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
