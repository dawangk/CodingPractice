#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug cout<<"HERE"<<endl;
#define ell "\n"
 
typedef long long ll;/*
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
*/
ll n,q, arr[200005];
 
template<class T> struct Seg {
	int n;
	T ID = 0;
	vector<T> seg;
	T comb (T a, T b) {return a + b;}
	void init (int _n) {n = _n; seg.assign(n * 2, ID);}
	void pull (int p) {
		seg[p] = comb(seg[p * 2], seg[p * 2 + 1]);
	}
	void upd (int i, T val) {
		seg[i+=n] += val;
		for (i /= 2; i; i /= 2) {
			pull(i);
		}
	}
	T query (int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(rb, seg[--r]);
		}
		return comb(ra, rb);
	}
};
 
int main(){
    inputJunk
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    Seg<long long> s;
    s.init(n+1);
    for(int i = 0;i<q;i++){
        int t; cin>>t;
        if(t==1){
            int a, b;ll k; cin>>a>>b>>k;
            s.upd(a, k); s.upd(b+1, -k);
        }else{
            int k; cin>>k;
            cout<<s.query(1, k)+arr[k]<<ell;
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
