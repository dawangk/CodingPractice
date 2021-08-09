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
const int MM = 5e5+5; int mod = 1e9+7;//99824435

string s; ll dp[505][505];
ll choose[505][505];

ll mult(ll a, ll b){
    return (1LL*a*b)%mod;
}

int main(){
    inputJunk
    cin>>s;
    int n = s.size();
    for(int i = 0;i+1<=n;i++){
        dp[i+1][i] = 1;
    }
    choose[0][0] = 1;
    for(int i = 1;i<=n/2;i++){
        choose[i][0] = 1;
        for(int j = 1;j<=i;j++){
            choose[i][j] = (choose[i-1][j]+choose[i-1][j-1])%mod;
        }
    }
    for(int i = n-1;i>=0;i--){
        for(int j = i+1;j<n;j+=2){
            for(int k = i+1;k<=j;k+=2){
                //cout<<i<<" "<<k<<" "<<j<<ell;
                if(s[i]==s[k]){
                    int x = mult(dp[i+1][k-1],dp[k+1][j]);
                    x = mult(x, choose[(j-i+1)/2][(k-i+1)/2]);
                    dp[i][j]+=x;
                    dp[i][j]%=mod;
                    //cout<<i<<" "<<j<<" "<<dp[i][j]<<ell;
                }
            }
        }
    }
    cout<<dp[0][n-1]<<ell;
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
