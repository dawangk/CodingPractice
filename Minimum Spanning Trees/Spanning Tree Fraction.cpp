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

typedef unsigned long long ll;
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

ll n, m;vector<pair<pi, pi>> edges;
int A, B;
struct DSU {
	vi e; void init(int N) { e = vi(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

template<class T> T kruskal(int N, vector<pair<T,pair<pi, pi>>> ed) {
	sort(all(ed));reverse(all(ed));A = 0; B = 0;
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	//for(auto a:ed){
    for(int i = 0;i<ed.size();i++){
        auto a = ed[i];
        if (D.unite(a.s.f.f,a.s.f.s)) {ans += a.f;A+=a.s.s.f; B+=a.s.s.s;}
	}
	return ans;
}

bool valid(double c){
    vector<pair<double, pair<pi, pi>>> cedges;

    for(auto x: edges){
        cedges.pb({(double)((double)x.s.f-(double)x.s.s*c),{{x.f.f, x.f.s},{x.s.f, x.s.s}}});
    }
    double ans = kruskal(n, cedges);
   // cout<<" "<<A<<" "<<B<<" "<<c<<endl;
    return A>=B*c;
}

int main(){
    inputJunk
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a, b, c, d; cin>>a>>b>>c>>d;
        //adj[a].pb({b,{c, d}});
        //adj[b].pb({a,{c, d}});
        edges.pb({{a, b}, {c, d}});
    }


    double lo = 0, hi = mod;
    for(int i = 0;i<60;i++){
        double mid = ((lo+hi)/2);
       // cout<<lo<<" "<<hi<<" "<<mid<<boolalpha<<" "<<endl;
        if(valid(mid)){//cout<<true<<endl;
            lo = mid;
        }else{
            hi = mid;//cout<<false<<endl;
        }
    }
    valid(lo);
    cout<<A/__gcd(A,B)<<"/"<<B/__gcd(A,B)<<ell;
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
