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
#define x real()
#define y imag()
 
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
typedef complex<ll> point;
 
const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 2e5+5; int mod = 1e9+7;//99824435
 
/*
double cross(point a, point b){
    return (conj(a)*b).y;
}
 
point intersection(point a, point b, point p, point q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}*/
 
int arr[20][MM];
 
int dab(int a, int b){
    for(int i = 0;i<18;i++){
        if((b>>i)&1)a = arr[i][a];
    }
    if(a==0)return -1;
    else return a;
}
 
int main(){
    inputJunk
    int n, q; cin>>n>>q;
 
    for(int i = 2;i<=n;i++){
        int a; cin>>a;
        arr[0][i] = a;
    }
 
    for(int i = 1;i<18;i++){
        for(int j = 2;j<=n;j++){
            arr[i][j] = arr[i-1][arr[i-1][j]];
        }
    }
 
    for(int i = 0;i<q;i++){
        int a, b; cin>>a>>b;
        cout<<dab(a, b)<<ell;
    }
    /*
    int t; cin>>t;
    while(t--){
        int n;
        vector<point> points;
 
        for(int i = 0;i<n;i++){
            int a, b; cin>>a>>b;
            points.pb({a, b});
        }
 
        for(int i = 0;i<n;i++){
            point kekw = {points[i].x+1, 3000000000LL};
            for(int j = 0;j<n;j++){
                int next = j+1;
                if(next==n)next = 0;
                int cnt = 0;
                if(intersect())
            }
        }
 
    }
*/
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
