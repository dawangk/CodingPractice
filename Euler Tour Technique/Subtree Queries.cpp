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

int n,k;
vi adj[MM];
ll arr[MM],st[MM], en[MM];
int t=  0;
template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return a+b; }
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

void dfs(int cur, int pre){
    st[cur] = t++;
    for(int x: adj[cur]){
        if(x==pre)continue;
        dfs(x, cur);
    }
    en[cur] = t-1;
}

int main(){
    inputJunk
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    Seg<ll> s; s.init(n+1);

    for(int i = 0;i<n-1;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(1,-1);
    for(int i = 1;i<=n;i++){
        s.upd(st[i], arr[i]);
    }
    for(int i = 0;i<k;i++){
        int a; cin>>a;
        if(a==1){
            int b, c; cin>>b>>c;
            s.upd(st[b], c);
        }else{
            int c; cin>>c;
            cout<<s.query(st[c], en[c])<<ell;
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
