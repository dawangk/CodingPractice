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
const int MM = 1e5+5; int mod = 1e9+7;//99824435

int n, arr[MM], closest[MM*100]; bool v[MM*100];
vpi edges[MM*100];
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

int kruskal(int N) {//, vector<pair<T,pi>> ed
	//sort(all(ed));//reverse(all(ed));
	int  ans = 0; DSU D; D.init(N+1); // edges that unite are in MST
	//for(auto &a:ed){
	for(int i = 0;i<=10000005;i++){
        for(auto a: edges[i])
        if (D.unite(a.f,a.s)) {
            ans += i;
        }
	}
	return ans;
}

int calc(int a, int b){
    if(b>a)swap(a, b);
    return a%b;
}

int main(){
    cin>>n;
    for(int i= 0;i<n;i++){
        cin>>arr[i];
        closest[arr[i]] = arr[i];
    }
    for(int i = 10000006;i>=1;i--){
        if(closest[i]==0)closest[i] = closest[i+1];
    }
    sort(arr, arr+n);
   // for(int i = 1;i<=12;i++){
    //    cout<<closest[i]<<endl;
    //}
    for(int i = 0;i<n;i++){
        if(v[arr[i]])continue;
        v[arr[i]]=  true;
        if(closest[arr[i]+1]==0)continue;
        if(!(2*arr[i]<=10000006&&closest[2*arr[i]]==closest[arr[i]+1])){
            edges[closest[arr[i]+1]-arr[i]].pb({arr[i], closest[arr[i]+1]});
        }

        for(int k = arr[i]; k<=10000006; k+=arr[i]){
            if(closest[k]==0)break;
            if(k+arr[i]<=10000006&&closest[k+arr[i]]==closest[k]) continue;
            edges[closest[k]-k].pb({arr[i], closest[k]});
        }
    }
    int ans = kruskal(10000500);
    cout<<ans<<ell;
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
