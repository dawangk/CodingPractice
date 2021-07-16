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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, pi> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;

const ll INF = 1e17+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;//99824435

int a, b, n, m; vi vert, horz; vtrip edge;

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

template<class T> T kruskal(int N, vector<pair<T,pi>> ed) {
	//sort(all(ed));
	T ans = 0; DSU D; D.init(N+1); // edges that unite are in MST
	for(auto &a:ed){
        if (D.unite(a.s.f,a.s.s)) {
            ans += a.f;
        }
	}
	return ans;
}

int main(){
    inputJunk
    freopen("fencedin.in","r", stdin);
    freopen("fencedin.out","w", stdout);
    cin>>a>>b>>n>>m;
    vert.pb(0); horz.pb(0);
    vert.pb(a); horz.pb(b);
    for(int i = 0;i<n;i++){
        int asd; cin>>asd;
        vert.pb(asd);
    }
    for(int i = 0;i<m;i++){
        int asd; cin>>asd;
        horz.pb(asd);
    }
    sort(all(vert)); sort(all(horz));
    //for(int x: vert)cout<<x<<" ";cout<<endl;
    //for(int x: horz)cout<<x<<" ";cout<<endl;
    for(int j = 0;j<horz.size()-1;j++){
        for(int i = 0;i<vert.size()-1;i++){
            int ind = j*(n+1)+i;
            //cout<<" "<<i<<" "<<j<<" "<<ind<<endl;
            if(i<vert.size()-2){
                edge.pb({horz[j+1]-horz[j],{ind,ind+1}});
            }
            if(j<horz.size()-2){
                edge.pb({vert[i+1]-vert[i],{ind,ind+n+1}});
            }
        }
    }
    //cout<<edge.size()<<endl;
    sort(all(edge));
    //for(auto x: edge){
    //    cout<<x.f<<" "<<x.s.f<<" "<<x.s.s<<endl;
    //}
    ll ans = 0;
    DSU D; D.init((n+1)*(m+1)+1);
    for(auto a:edge){
        if (D.unite(a.s.f,a.s.s)) {
            ans += a.f;
        }
	}
    cout<<ans<<ell;


}
/*CUSTOM TEST CASE 1
15 6 2 2
4 9
1 3
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
