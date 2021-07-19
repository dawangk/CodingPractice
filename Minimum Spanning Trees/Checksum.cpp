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
const int MM = 2e3+5; int mod = 1e9+7;//99824435



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
	sort(all(ed));reverse(all(ed));
	T ans = 0; DSU D; D.init(N+1); // edges that unite are in MST
	for(auto &a:ed){
        if (D.unite(a.s.f,a.s.s)) {
            ans += a.f;
        }
	}
	return ans;
}

int solve(){
    int n; cin>>n;
    vector<vi> grid(n, vector<int>(n));
    vtrip edges;
    int useless;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int sum = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j]!=0){
                edges.pb({grid[i][j],{i, n+j}});
                sum+=grid[i][j];
            }
        }
    }
    for(int i = 0;i<n;i++)cin>>useless>>useless;

    return sum-kruskal(2*n,edges);
}

int main(){
    inputJunk
    int t; cin>>t;
    int cnt=  1;
    while(t--){
        cout<<"Case #"<<cnt<<": "<<solve()<<ell;
        cnt++;
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
