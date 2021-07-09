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

int n, m; vi adj[MM], close;
bool reopened[MM];

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

int main(){
    inputJunk
    freopen("closing.in","r", stdin);
    freopen("closing.out","w", stdout);
    cin>>n>>m;
    DSU d; d.init(n+1);
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 0;i<n;i++){
        int a; cin>>a;
        close.pb(a);
    }
    reverse(all(close));
    vector<string> ans;
    for(int i = 0;i<n;i++){
        int curfarm = close[i];
        reopened[curfarm] = true;
        for(int x: adj[curfarm]){
            if(reopened[x]){
                d.unite(curfarm, x);
            }
        }
        if(d.size(curfarm)==i+1){
            ans.pb("YES");
        }else{
            ans.pb("NO");
        }
    }
    reverse(all(ans));
    for(string x: ans)cout<<x<<ell;
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
