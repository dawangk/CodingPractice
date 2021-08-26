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
const int MM = 1e5+5; int mod = 998244353;//1e9+7


template<class T> struct Seg { // comb(ID,b) = b
	const T ID = {1,0}; T comb(T a, T b) { /*cout<<a.f<<" "<<b.f<<" "<<a.s<<" "<<b.s<<ell;*/return {(a.f*b.f)%mod, (a.s*b.f+b.s)%mod}; }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

int n, q;
Seg<pair<ll, ll>> s;

int main(){
    inputJunk
    cin>>n>>q;
    s.init(n+1);
    for(int i = 0;i<n;i++){
        ll b, c; cin>>b>>c;
        s.upd(i, {b, c});

    }
    for(int i = 0;i<q;i++){
        int a, b, c, d; cin>>a>>b>>c>>d;
        if(a){
            pll curq = s.query(b, c-1);
           // cout<<(curq.f)<<" "<<d<<" "<<curq.s<<ell;
            cout<<((curq.f*d)%mod+curq.s)%mod<<ell;
        }else{
            s.upd(b, {c, d});
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
