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
const int MM = 755; int mod = 1e9+7;//99824435

int r, c, k, arr[MM][MM], ans[MM];
template<class T> struct Seg {
	const T ID = 0; T comb(T a, T b){ return (a+b+mod)%mod; }
	int n=0; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) {
		seg[p += n] += val; seg[p] %=mod; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

int main(){
    inputJunk
    freopen("hopscotch.in","r", stdin);
    freopen("hopscotch.out","w", stdout);
    cin>>r>>c>>k;
    Seg<ll> sc[k+5], t;
    vi colour[k+5];
    map<int, int> freq[k+5];
    for(int i = 1;i<=r;i++){
        for(int j = 1;j<=c;j++){
            cin>>arr[i][j];
            colour[arr[i][j]].pb(j);
        }
    }

    for(int i = 1;i<=k;i++){
        sort(all(colour[i]));
        for(int x: colour[i]){
            if(!freq[i][x]) freq[i][x] = freq[i].size();
        }
    }

    t.init(c+1);
    t.upd(1, 1);
    for(int i = 1;i<=k;i++){
        sc[i].init(freq[i].size()+3);
    }
    sc[arr[1][1]].upd(freq[arr[1][1]][1], 1);

    for(int i = 2;i<=r;i++){
        for(int j = 2;j<=c;j++){
            int cur = arr[i][j];
            ans[j] = t.query(1, j-1)-sc[cur].query(1, freq[cur][j]-1)+mod;
            ans[j]%=mod;
        }
        for(int j = 2;j<=c;j++){
            int cur = arr[i][j];
            t.upd(j, ans[j]);
            sc[cur].upd(freq[cur][j], ans[j]);
        }
    }
    cout<<ans[c]<<ell;
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
