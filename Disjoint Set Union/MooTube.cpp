#include <bits/stdc++.h>
using namespace std;
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
typedef pair<pi, int> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 2e5+5; int mod = 1e9+7;//998244353

int n, q; vector<pair<int, pair<int , int>>> edges, qs;

struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) {return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int main(){
    inputJunk
    freopen("mootube.in","r", stdin);
    freopen("mootube.out","w", stdout);
    int n, q;
    cin>>n>>q;
    DSU d; d.init(n);
    for(int i = 0;i<n-1;i++){
        int a, b, c; cin>>a>>b>>c;
        edges.pb({c, {a, b}});
    }
    sort(all(edges));
    for(int i = 0;i<q;i++){
        int k, n; cin>>k>>n;
        qs.pb({k,{n, i}});
    }
    sort(all(qs)); reverse(all(qs));
    vpi ans;
    for(auto x: qs){
        int k = x.f, nod = x.s.f, index = x.s.s;
        //cout<<k<<" "<<nod<<" "<<index<<endl;
        while(!edges.empty()&&edges[edges.size()-1].f>=k){
            int a = edges[edges.size()-1].s.f, b = edges[edges.size()-1].s.s;
            //cout<<a<<" "<<b<<" "<<endl;
            d.unite(a, b);
            edges.pop_back();

        }
        ans.pb({index, d.size(nod)});
    }
    sort(all(ans));
    for(auto x: ans){
        cout<<x.s-1<<ell;
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
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
