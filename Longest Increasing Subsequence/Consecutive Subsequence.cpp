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
 
int n; vi a;
 
int main(){
    inputJunk
    cin>>n;
    for(int i  =0;i<n;i++){
        int d; cin>>d;
        a.pb(d);
    }
 
    map<int, int> m;
 
    for(int i  =0;i<n;i++){
        m[a[i]] = max(m[a[i]], m[a[i]-1]+1);
    }
    int ans = 0, ansval = -1;
    for(auto x: m){
        if(x.s>ans){
            ans = x.s;
            ansval = x.f;
        }
    }
    cout<<ans<<ell;
    int cur = ansval-ans+1;
    for(int i = 0;i<n;i++){
        if(a[i]==cur){
            cout<<i+1<<" ";
            cur++;
        }
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
