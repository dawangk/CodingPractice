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
const ll P = 9973, M = 1e9+9;
const int MM = 8e5+5; int mod = 1e9+7;//99824435

int n, q, arr[MM], seg[MM];

void build(int node, int l, int r){
    if(l==r){
        seg[node] = arr[l];
    }else{
        int mid = (l+r)/2;
        build(2*node+1, l, mid);
        build(2*node+2, mid+1, r);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}

void upd(int node, int l, int r, int val){
    if(l==r){
        seg[node]-=val;
        cout<<l<<" ";
    }else{
        int mid = (l+r)/2;
        if(seg[2*node+1]>=val){
            upd(2*node+1, l, mid, val);
        }else{
            upd(2*node+2, mid+1, r, val);
        }
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}

int main(){
    inputJunk
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    build(0, 1, n);
    for(int i= 0;i<q;i++){
        int a; cin>>a;
        if(seg[0]<a)cout<<0<<" ";
        else upd(0, 1, n, a);
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
