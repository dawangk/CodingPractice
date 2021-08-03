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

int n; // The number of nodes in the graph
vector<int> graph[MM];
int timer = 0, tin[MM], euler_tour[MM*2];
int segtree[1600333]; // Segment tree for RMQ

void dfs(int node = 1, int parent = -1) {
	tin[node] = timer; // The time when we first visit a node
	euler_tour[timer++] = node;
	for (int i : graph[node]) {
		if (i != parent) {
			dfs(i, node);
			euler_tour[timer++] = node;
		}
	}
}

int mn_tin(int x, int y) {
	if (x == -1) return y;
	if (y == -1) return x;
	return (tin[x] < tin[y] ? x : y);
}

// Build the segment tree: run `build()` after running dfs`
void build(int node = 1, int l = 0, int r = timer - 1) {
	if (l == r) segtree[node] = euler_tour[l];
	else {
		int mid = (l + r) / 2;
		build(node * 2, l, mid);
		build(node * 2 + 1, mid + 1, r);
		segtree[node] = mn_tin(segtree[node * 2], segtree[node * 2 + 1]);
	}
}

int query(int a, int b, int node = 1, int l = 0, int r = timer - 1) {
	if (l > b || r < a) return -1;
	if (l >= a && r <= b) return segtree[node];
	int mid = (l + r) / 2;
	return mn_tin(query(a, b, node * 2, l, mid), query(a, b, node * 2 + 1, mid + 1, r));
}

// Make sure you run $dfs` and `build()` before you run this
int lca(int a, int b) {
	if (tin[a] > tin[b]) swap(a, b);
	return query(tin[a], tin[b]);
}

int main(){
    inputJunk
    int q;
    cin>>n>>q;
    for(int i = 2;i<=n;i++){
        int a; cin>>a;
        graph[i].pb(a); graph[a].pb(i);
    }

    dfs();
    //cout<<timer<<ell;
    build();
    for(int i = 0;i<q;i++){
        int a, b; cin>>a>>b;
        cout<<lca(a,b)<<ell;
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
